#include "../inc/Engine.hpp"

#include <algorithm>



// Utilities
std::vector<std::pair<int,int>> get_grid_neighbors(std::pair<int,int> coord, std::pair<int,int> borders) {
    std::vector<std::pair<int,int>> neighbors;
    std::vector<std::pair<int,int>> possible_neigbors({{coord.first, coord.second - 1},
                                                       {coord.first + 1, coord.second},
                                                       {coord.first, coord.second + 1},
                                                       {coord.first - 1, coord.second}});
    for(auto const& n : possible_neigbors) {
        if(n.first >= 0 && n.second >= 0 && n.first < borders.first && n.second < borders.second) {
            neighbors.push_back(n);
        }
    }
    return neighbors;
}

std::string coord_to_str(std::pair<int,int> coord) {
    return '(' + std::to_string(coord.first) + ',' + std::to_string(coord.second) + ')';
}

// Constructor
Engine::Engine(std::pair<int,int> border_dim): m_border_dim(border_dim) {
    sAppName = "Path finding";
}


bool Engine::OnUserCreate()
{
    m_border_dim.first -= ScreenWidth() % m_border_dim.first;
    m_border_dim.second -= ScreenHeight() % m_border_dim.second;
    m_grid_dim = {ScreenWidth() / m_border_dim.first,
                  ScreenHeight() / m_border_dim.second};
    m_graph = GraphMatrix<>(m_grid_dim.first * m_grid_dim.second);
    m_state = State::INPUT_WALLS;
    set_all_grid_neighbors();
    m_start = {-1, -1};
    m_end = {-1, -1};
    std::vector<ChoiceWidget> choices_widgets({
        {"assets/add_wall.png", "Input walls"},
        {"assets/delete_wall.png", "Delete walls"},
        {"assets/start.png", "Choose start"},
        {"assets/end.png", "Choose end"}
    });
    m_choicebar = ChoiceBar({ScreenWidth() - 25, 5}, {20, 20}, choices_widgets);
	return true;
}
bool Engine::OnUserUpdate(float fElapsedTime)
{
    update_state();
    if(GetKey(olc::C).bPressed)
        clear();

    Clear(olc::WHITE);
    draw_grid();
    draw_dijkstra();
    draw_walls();
    draw_start();
    draw_end();
    switch(m_state) {
        case State::INPUT_WALLS:
            input_walls();
            draw_selection_wall();
            break;
        case State::DELETE_WALLS:
            delete_walls();
            draw_selection_wall(olc::Pixel(191, 64, 64));
            break;
        case State::CHOOSE_START:
            choose_start();
            draw_selection_circle(olc::Pixel(0, 102, 0, 250));
            break;
        case State::CHOOSE_END:
            choose_end();
            draw_selection_circle(olc::Pixel(153, 0, 0, 250));
            break;
    }
    if(GetKey(olc::ENTER).bPressed)
        compute_dijkstra();
    draw_current_path();
    draw_state();
    return true;
}


// Getter/Setter
std::pair<int,int> Engine::get_border_dim() const {
    return m_border_dim;
}
int Engine::get_border_width() const {
    return m_border_dim.first;
}
int Engine::get_border_height() const {
    return m_border_dim.second;
}
std::pair<int,int> Engine::get_grid_dim() const {
    return m_grid_dim;
}
int Engine::get_grid_width() const {
    return m_grid_dim.first;
}
int Engine::get_grid_height() const {
    return m_grid_dim.second;
}
void Engine::add_wall(std::pair<int,int> coord1, std::pair<int,int> coord2) {
    m_graph.add_edge(get_index(coord1), get_index(coord2));
    if(!m_dijkstra_prev.empty())
        compute_dijkstra();
}
void Engine::delete_wall(std::pair<int,int> coord1, std::pair<int,int> coord2) {
    m_graph.delete_edge(get_index(coord1), get_index(coord2));
    if(!m_dijkstra_prev.empty())
        compute_dijkstra();
}


// Draw methods
void Engine::draw_walls(olc::Pixel color, int thickness) {
    for(size_t x = 0; x < get_grid_width(); x++) {
        for(size_t y = 0; y < get_grid_height(); y++) {
            auto neighbors = get_grid_neighbors({x, y}, get_grid_dim());
            for(auto const& n: neighbors) {
                if(!(n.first > x || n.second > y) && !m_graph.has_edge(get_index({x, y}), get_index(n))) {
                    draw_wall({x, y}, n, olc::BLACK, 3);
                }
            }
        }
    }
}
void Engine::draw_selection_rect(olc::Pixel color) {
    auto grid_coord = get_grid_coord({GetMouseX(), GetMouseY()});
    if(GetMouse(0).bHeld || GetMouse(0).bPressed) {
        fill_rect(grid_coord, olc::GREY);
    }
    draw_rect(grid_coord, 2, color);
}
void Engine::draw_selection_wall(olc::Pixel color) {
    std::pair<int,int> mouse = {GetMouseX(), GetMouseY()};
    std::pair<int,int> rect = get_grid_coord(mouse);
    int wall_type = get_closest_wall(mouse, rect);
    auto neighbors = get_grid_neighbors(rect, get_grid_dim());
    if(wall_type < neighbors.size()) {
        draw_wall(rect, neighbors[wall_type], color, 4);
    }
}
void Engine::draw_selection_circle(olc::Pixel color) {
    auto grid_coord = get_grid_coord({GetMouseX(), GetMouseY()});
    fill_circle(grid_coord, color);
}
void Engine::draw_wall(std::pair<int,int> coord1, std::pair<int,int> coord2, olc::Pixel color, int thickness) {
    int wall_type = get_wall_type(coord1, coord2);
    switch(wall_type) {
        case 0:
            draw_up_wall(coord1, color, thickness);
            break;
        case 1:
            draw_right_wall(coord1, color, thickness);
            break;
        case 2:
            draw_down_wall(coord1, color, thickness);
            break;
        case 3:
            draw_left_wall(coord1, color, thickness);
            break;
    }
}
void Engine::draw_up_wall(std::pair<int,int> coord, olc::Pixel color, int thickness) {
    auto canvas_coord = get_canvas_coord(coord);
    for(int i = 0; i < thickness; i++) {
        DrawLine(canvas_coord.first,
                 canvas_coord.second + i,
                 canvas_coord.first + get_border_width(),
                 canvas_coord.second + i,
                 color);
        DrawLine(canvas_coord.first,
                 canvas_coord.second - i,
                 canvas_coord.first + get_border_width(),
                 canvas_coord.second - i,
                 color);
    }
}
void Engine::draw_down_wall(std::pair<int,int> coord, olc::Pixel color, int thickness) {
    auto canvas_coord = get_canvas_coord(coord);
    for(int i = 0; i < thickness; i++) {
        DrawLine(canvas_coord.first,
                 canvas_coord.second + get_border_height() + i,
                 canvas_coord.first + get_border_width(),
                 canvas_coord.second + get_border_height() + i,
                 color);
        DrawLine(canvas_coord.first,
                 canvas_coord.second + get_border_height() - i,
                 canvas_coord.first + get_border_width(),
                 canvas_coord.second + get_border_height() - i,
                 color);
    }
}
void Engine::draw_left_wall(std::pair<int,int> coord, olc::Pixel color, int thickness) {
    auto canvas_coord = get_canvas_coord(coord);
    for(int i = 0; i < thickness; i++) {
        DrawLine(canvas_coord.first + i,
                 canvas_coord.second, 
                 canvas_coord.first + i,
                 canvas_coord.second + get_border_height(),
                 color);
        DrawLine(canvas_coord.first - i,
                 canvas_coord.second, 
                 canvas_coord.first - i,
                 canvas_coord.second + get_border_height(),
                 color);
    }
}
void Engine::draw_right_wall(std::pair<int,int> coord, olc::Pixel color, int thickness) {
    auto canvas_coord = get_canvas_coord(coord);
    for(int i = 0; i < thickness; i++) {
        DrawLine(canvas_coord.first + get_border_width() + i,
                 canvas_coord.second, 
                 canvas_coord.first + get_border_width() + i,
                 canvas_coord.second + get_border_height(),
                 color);
        DrawLine(canvas_coord.first + get_border_width() - i,
                 canvas_coord.second, 
                 canvas_coord.first + get_border_width() - i,
                 canvas_coord.second + get_border_height(),
                 color);
    }
}
void Engine::fill_rect(std::pair<int,int> coord, olc::Pixel color) {
    auto canvas_coord = get_canvas_coord(coord);
    FillRect(canvas_coord.first, canvas_coord.second, get_border_width(), get_border_height(), color);
}
void Engine::draw_rect(std::pair<int, int> coord, int thickness, olc::Pixel color) {
    auto canvas_coord = get_canvas_coord(coord);
    for(int i = 0; i < thickness; i++) {
        DrawRect(canvas_coord.first - i, canvas_coord.second - i, get_border_width() + 2 * i, get_border_height() + 2 * i, color);
    }
}
void Engine::fill_circle(std::pair<int,int> coord, olc::Pixel color) {
    auto canvas_coord = get_canvas_coord(coord);
    canvas_coord.first += get_border_width() / 2;
    canvas_coord.second += get_border_height() / 2;
    int radius = std::min(get_border_width(), get_border_height());
    FillCircle(canvas_coord.first, canvas_coord.second, radius / 2 - 2, color);
}
void Engine::draw_grid() {
    for(size_t x = 0; x < ScreenWidth(); x+=get_border_width()) {
        DrawLine(x, 0, x, ScreenHeight(), olc::Pixel(200, 200, 200));
    }
    for(size_t y = 0; y < ScreenHeight(); y+=get_border_height()) {
        DrawLine(0, y, ScreenWidth(), y, olc::Pixel(200, 200, 200));
    }
}
void Engine::draw_state() {
    m_choicebar.draw(*this);
}
void Engine::draw_start() {
    if(m_start != std::pair<int,int>{-1, -1})
        fill_circle(m_start, olc::Pixel(0, 102, 0));
}
void Engine::draw_end() {
    if(m_end != std::pair<int,int>{-1, -1})
        fill_circle(m_end, olc::Pixel(153, 0, 0));
}
void Engine::draw_path(std::vector<std::pair<int,int>> path) {
    if(path.size() < 2)
        return;
    for(size_t i = 1; i < path.size(); i++) {
        draw_path(path[i - 1], path[i]);
    }
}
void Engine::draw_path(std::pair<int,int> coord1, std::pair<int,int> coord2, olc::Pixel color, int thickness) {
    int wall_type = get_wall_type(coord1, coord2);
    switch(wall_type) {
        case 0:
            draw_path_up(coord1, color, thickness);
            draw_path_down(coord2, color, thickness);
            break;
        case 1:
            draw_path_right(coord1, color, thickness);
            draw_path_left(coord2, color, thickness);
            break;
        case 2:
            draw_path_down(coord1, color, thickness);
            draw_path_up(coord2, color, thickness);
            break;
        case 3:
            draw_path_left(coord1, color, thickness);
            draw_path_right(coord2, color, thickness);
            break;
    }
}
void Engine::draw_path_up(std::pair<int,int> coord, olc::Pixel color, int thickness) {
    auto canvas_coord = get_canvas_coord(coord);
    for(int i = 0; i < thickness; i++) {
        DrawLine(canvas_coord.first + get_border_width() / 2 + i,
                 canvas_coord.second,
                 canvas_coord.first + get_border_width() / 2 + i,
                 canvas_coord.second + get_border_height() / 2,
                 color);
        DrawLine(canvas_coord.first + get_border_width() / 2 - i,
                 canvas_coord.second,
                 canvas_coord.first + get_border_width() / 2 - i,
                 canvas_coord.second + get_border_height() / 2,
                 color);
    }
}
void Engine::draw_path_down(std::pair<int,int> coord, olc::Pixel color, int thickness) {
    auto canvas_coord = get_canvas_coord(coord);
    for(int i = 0; i < thickness; i++) {
        DrawLine(canvas_coord.first + get_border_width() / 2 + i,
                 canvas_coord.second + get_border_height(),
                 canvas_coord.first + get_border_width() / 2 + i,
                 canvas_coord.second + get_border_height() / 2,
                 color);
        DrawLine(canvas_coord.first + get_border_width() / 2 - i,
                 canvas_coord.second + get_border_height(),
                 canvas_coord.first + get_border_width() / 2 - i,
                 canvas_coord.second + get_border_height() / 2,
                 color);
    }
}
void Engine::draw_path_left(std::pair<int,int> coord, olc::Pixel color, int thickness) {
    auto canvas_coord = get_canvas_coord(coord);
    for(int i = 0; i < thickness; i++) {
        DrawLine(canvas_coord.first, 
                 canvas_coord.second + get_border_height() / 2 + i,
                 canvas_coord.first + get_border_width() / 2,
                 canvas_coord.second + get_border_height() / 2 + i,
                 color);
        DrawLine(canvas_coord.first, 
                 canvas_coord.second + get_border_height() / 2 - i,
                 canvas_coord.first + get_border_width() / 2,
                 canvas_coord.second + get_border_height() / 2 - i,
                 color);
    }
}
void Engine::draw_path_right(std::pair<int,int> coord, olc::Pixel color, int thickness) {
    auto canvas_coord = get_canvas_coord(coord);
    for(int i = 0; i < thickness; i++) {
        DrawLine(canvas_coord.first + get_border_width(), 
                 canvas_coord.second + get_border_height() / 2 + i,
                 canvas_coord.first + get_border_width() / 2,
                 canvas_coord.second + get_border_height() / 2 + i,
                 color);
        DrawLine(canvas_coord.first + get_border_width(), 
                 canvas_coord.second + get_border_height() / 2 - i,
                 canvas_coord.first + get_border_width() / 2,
                 canvas_coord.second + get_border_height() / 2 - i,
                 color);
    }
}
void Engine::draw_arrow(std::pair<int,int> coord1, std::pair<int,int> coord2, olc::Pixel color) {
    int wall_type = get_wall_type(coord1, coord2);
    switch(wall_type) {
        case 0:
            draw_arrow_up(coord1, color);
            break;
        case 1:
            draw_arrow_right(coord1, color);
            break;
        case 2:
            draw_arrow_down(coord1, color);
            break;
        case 3:
            draw_arrow_left(coord1, color);
            break;
    }
}
void Engine::draw_arrow_up(std::pair<int,int> coord, olc::Pixel color) {
    auto canvas_coord = get_canvas_coord(coord);
    DrawLine(canvas_coord.first + get_border_width() / 2,
             canvas_coord.second + 2,
             canvas_coord.first + get_border_width() / 2,
             canvas_coord.second + get_border_height() - 2,
             color);
    FillTriangle(canvas_coord.first + get_border_width() / 2, canvas_coord.second + 2,
                 canvas_coord.first + 4, canvas_coord.second + get_border_height() / 2 - 2, 
                 canvas_coord.first + get_border_width() - 4, canvas_coord.second + get_border_height() / 2 - 2,
                 color);
}
void Engine::draw_arrow_down(std::pair<int,int> coord, olc::Pixel color) {
    auto canvas_coord = get_canvas_coord(coord);
    DrawLine(canvas_coord.first + get_border_width() / 2,
             canvas_coord.second + 2,
             canvas_coord.first + get_border_width() / 2,
             canvas_coord.second + get_border_height() - 2,
             color);
    FillTriangle(canvas_coord.first + get_border_width() / 2, canvas_coord.second +  get_border_height() - 2,
                 canvas_coord.first + 4, canvas_coord.second + get_border_height() / 2 + 2, 
                 canvas_coord.first + get_border_width() - 4, canvas_coord.second + get_border_height() / 2 + 2,
                 color);
}

void Engine::draw_arrow_left(std::pair<int,int> coord, olc::Pixel color) {
    auto canvas_coord = get_canvas_coord(coord);
    DrawLine(canvas_coord.first + 2,
             canvas_coord.second + get_border_height() / 2,
             canvas_coord.first + get_border_width() - 2,
             canvas_coord.second + get_border_height()/ 2,
             color);
    FillTriangle(canvas_coord.first + 2, canvas_coord.second +  get_border_height() / 2,
                 canvas_coord.first + get_border_width() / 2 - 2, canvas_coord.second + 4, 
                 canvas_coord.first + get_border_width() / 2 - 2, canvas_coord.second + get_border_height() - 4,
                 color);
}
void Engine::draw_arrow_right(std::pair<int,int> coord, olc::Pixel color) {
    auto canvas_coord = get_canvas_coord(coord);
    DrawLine(canvas_coord.first + 2,
             canvas_coord.second + get_border_height() / 2,
             canvas_coord.first + get_border_width() - 2,
             canvas_coord.second + get_border_height()/ 2,
             color);
    FillTriangle(canvas_coord.first + get_border_width() - 2, canvas_coord.second +  get_border_height() / 2,
                 canvas_coord.first + get_border_width() / 2 + 2, canvas_coord.second + 4, 
                 canvas_coord.first + get_border_width() / 2 + 2, canvas_coord.second + get_border_height() - 4,
                 color);
}
void Engine::draw_dijkstra() {
    for(size_t v = 0; v < m_dijkstra_prev.size(); v++) {
        auto prev = m_dijkstra_prev[v];
        if(v == -1)
            continue;
        auto coord1 = get_coord(v);
        auto coord2 = get_coord(prev);
        draw_arrow(coord1, coord2);
    }
}
void Engine::draw_current_path() {
    auto grid_coord = get_grid_coord({GetMouseX(), GetMouseY()});
    auto path = get_path(grid_coord);
    draw_path(path);
}

// Utilies
std::pair<int,int> Engine::get_grid_coord(std::pair<int,int> coord) const {
    return {coord.first / get_border_width(), coord.second / get_border_height()};
}
std::pair<int,int> Engine::get_canvas_coord(std::pair<int,int> coord) const {
    return {coord.first * get_border_width(), coord.second * get_border_height()};
}
void Engine::set_all_grid_neighbors() {
    for(int i = 0; i < m_grid_dim.first; i++) {
        for(int j = 0; j < m_grid_dim.second; j++) {
            for(auto const& n: get_grid_neighbors({i, j}, m_grid_dim)) {
                m_graph.add_edge(get_index({i, j}), get_index(n));
            }
        }
    }
}
size_t Engine::get_index(std::pair<int,int> coord) const {
    return coord.second * get_grid_width() + coord.first;
}
std::pair<int,int> Engine::get_coord(int index) const {
    return {index - (index / get_grid_width()) * get_grid_width(), index / get_grid_width()};
}
int Engine::get_wall_type(std::pair<int,int> coord1, std::pair<int,int> coord2) const {
    if(coord1.first == coord2.first) {
        return coord1.second > coord2.second ? 0 : 2;
    }
    else if(coord1.second == coord2.second) {
        return coord1.first > coord2.first ? 3 : 1;
    }
    else {
        return -1;
    }
}
int Engine::get_closest_wall(std::pair<int,int> mouse, std::pair<int,int> rect) const {
    auto rect_origin = get_canvas_coord(rect);
    std::vector<int> dists = {std::abs(mouse.second - rect_origin.second),
                              std::abs(mouse.first - (rect_origin.first + get_border_width())),
                              std::abs(mouse.second - (rect_origin.second + get_border_height())),
                              std::abs(mouse.first - (rect_origin.first))};
    return std::distance(dists.begin(), std::min_element(dists.begin(), dists.end()));
}

// Action
void Engine::input_walls() {
    if(GetMouse(0).bPressed || GetMouse(0).bHeld) {
        std::pair<int,int> mouse = {GetMouseX(), GetMouseY()};
        std::pair<int,int> rect = get_grid_coord(mouse);
        int wall_type = get_closest_wall(mouse, rect);
        auto neighbors = get_grid_neighbors(rect, get_grid_dim());
        if(wall_type < neighbors.size()) {
            delete_wall(rect, neighbors[wall_type]);
        }
    }
}
void Engine::delete_walls() {
    if(GetMouse(0).bPressed || GetMouse(0).bHeld) {
        std::pair<int,int> mouse = {GetMouseX(), GetMouseY()};
        std::pair<int,int> rect = get_grid_coord(mouse);
        int wall_type = get_closest_wall(mouse, rect);
        auto neighbors = get_grid_neighbors(rect, get_grid_dim());
        if(wall_type < neighbors.size()) {
            add_wall(rect, neighbors[wall_type]);
        }
    }
}
void Engine::update_state() {
    m_choicebar.update(*this);
    if(GetMouseWheel() > 0) {
        int state = static_cast<int>(m_state);
        if(state == 0)
            m_state = static_cast<State>(3);
        else
            m_state = static_cast<State>(state - 1);
    }
    else if(GetMouseWheel() < 0) {
        int state = static_cast<int>(m_state);
        if(state == 3)
            m_state = static_cast<State>(0);
        else
            m_state = static_cast<State>(state + 1);
    }
}
void Engine::choose_start() {
    if(GetMouse(0).bPressed) {
        auto coord = get_grid_coord({GetMouseX(), GetMouseY()});
        if(coord != m_end) {
            m_start = coord;
        }
    }
}
void Engine::choose_end() {
    if(GetMouse(0).bPressed) {
        auto coord = get_grid_coord({GetMouseX(), GetMouseY()});
        if(coord != m_start) {
            m_end = coord;
        }
        if(!m_dijkstra_prev.empty())
            compute_dijkstra();
    }
}
void Engine::compute_dijkstra() {
    auto dijkstra_results = m_graph.dijkstra(get_index(m_end));
    m_dijkstra_dists = dijkstra_results.first;
    m_dijkstra_prev = dijkstra_results.second;
}
std::vector<std::pair<int,int>> Engine::get_path(std::pair<int,int> coord) const {
    if(m_dijkstra_prev.empty())
        return {};
    std::vector<std::pair<int,int>> path;
    int v = m_dijkstra_prev[get_index(coord)];
    path.push_back(coord);
    while(v != -1) {
        path.push_back(get_coord(v));
        v = m_dijkstra_prev[v];
    }
    return path;
}
void Engine::clear() {
    m_dijkstra_prev.clear();
    m_dijkstra_dists.clear();
}

