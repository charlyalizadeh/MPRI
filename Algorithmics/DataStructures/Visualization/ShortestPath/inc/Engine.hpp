#ifndef ENGINE_H
#define ENGINE_H
#include "../lib/olcPixelGameEngine.h"
#include "../../../Graph/graphmatrix.hpp"
#include "../inc/ChoiceBar.hpp"

#include <vector>
#include <array>
#include <chrono>

enum class State {
    INPUT_WALLS,
    DELETE_WALLS,
    CHOOSE_START,
    CHOOSE_END
};

class Engine : public olc::PixelGameEngine
{
public:
    // Constructor
	Engine(std::pair<int,int> border_dim = {10, 10});

    // olc::PixelGameEngine methods
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

    // Getter/Setter
    std::pair<int,int> get_border_dim() const;
    int get_border_width() const;
    int get_border_height() const;
    std::pair<int,int> get_grid_dim() const;
    int get_grid_width() const;
    int get_grid_height() const;
    void add_wall(std::pair<int,int> coord1, std::pair<int,int> coord2);
    void delete_wall(std::pair<int,int> coord1, std::pair<int,int> coord2);


private:
    // Draw methods
    void draw_walls(olc::Pixel color = olc::BLACK, int thickness = 1);
    void draw_selection_rect(olc::Pixel color = olc::BLACK);
    void draw_selection_wall(olc::Pixel color = olc::BLACK);
    void draw_selection_circle(olc::Pixel color);
    void draw_wall(std::pair<int,int> coord1, std::pair<int,int> coord2, olc::Pixel color = olc::BLACK, int thickness = 1);
    void draw_up_wall(std::pair<int,int> coord, olc::Pixel color = olc::BLACK, int thickness = 1);
    void draw_down_wall(std::pair<int,int> coord, olc::Pixel color = olc::BLACK, int thickness = 1);
    void draw_left_wall(std::pair<int,int> coord, olc::Pixel color = olc::BLACK, int thickness = 1);
    void draw_right_wall(std::pair<int,int> coord, olc::Pixel color = olc::BLACK, int thickness = 1);
    void fill_rect(std::pair<int,int> coord, olc::Pixel color = olc::BLACK);
    void draw_rect(std::pair<int,int> coord, int thickness=1, olc::Pixel color=olc::BLACK);
    void fill_circle(std::pair<int,int> coord, olc::Pixel color = olc::BLACK);
    void draw_grid();
    void draw_state();
    void draw_start();
    void draw_end();
    void draw_path(std::vector<std::pair<int,int>> path);
    void draw_path(std::pair<int,int> coord1, std::pair<int,int> coord2, olc::Pixel color = olc::Pixel(5, 55, 101), int thickness = 2);
    void draw_path_up(std::pair<int,int> coord, olc::Pixel color = olc::Pixel(5, 55, 101), int thickness = 1);
    void draw_path_down(std::pair<int,int> coord, olc::Pixel color = olc::Pixel(5, 55, 101), int thickness = 1);
    void draw_path_left(std::pair<int,int> coord, olc::Pixel color = olc::Pixel(5, 55, 101), int thickness = 1);
    void draw_path_right(std::pair<int,int> coord, olc::Pixel color = olc::Pixel(5, 55, 101), int thickness = 1);
    void draw_arrow(std::pair<int,int> coord1, std::pair<int,int> coord2, olc::Pixel color = olc::Pixel(128, 128, 128));
    void draw_arrow_up(std::pair<int,int> coord, olc::Pixel color = olc::Pixel(128, 128, 128));
    void draw_arrow_down(std::pair<int,int> coord, olc::Pixel color = olc::Pixel(128, 128, 128));
    void draw_arrow_left(std::pair<int,int> coord, olc::Pixel color = olc::Pixel(128, 128, 128));
    void draw_arrow_right(std::pair<int,int> coord, olc::Pixel color = olc::Pixel(128, 128, 128));
    void draw_dijkstra();
    void draw_current_path();

    // Utilities
    std::pair<int,int> get_grid_coord(std::pair<int,int> coord) const;
    std::pair<int,int> get_canvas_coord(std::pair<int,int> coord) const;
    void set_all_grid_neighbors();
    size_t get_index(std::pair<int,int> coord) const;
    std::pair<int,int> get_coord(int index) const;
    int get_wall_type(std::pair<int,int> coord1, std::pair<int,int> coord2) const;
    int get_closest_wall(std::pair<int, int> mouse, std::pair<int,int> rect) const;

    // Action
    void input_walls();
    void delete_walls();
    void update_state();
    void choose_start();
    void choose_end();
    void compute_dijkstra();
    void compute_dijkstra_one();
    void compute_astar();
    std::vector<std::pair<int,int>> get_path(std::pair<int,int> coord) const;
    void clear();

private:
    std::pair<int,int> m_border_dim, m_grid_dim;
    bool m_input_walls;
    GraphMatrix<> m_graph;
    State m_state;
    std::pair<int,int> m_start, m_end;
    //std::vector<std::pair<int,int>> m_path;
    ChoiceBar m_choicebar;
    std::vector<int> m_dijkstra_prev;
    std::vector<int> m_dijkstra_dists;
};

#endif
