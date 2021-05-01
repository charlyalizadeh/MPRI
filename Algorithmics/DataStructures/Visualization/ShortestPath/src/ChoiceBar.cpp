#include "../inc/ChoiceBar.hpp"



ChoiceBar::ChoiceBar(std::pair<int,int> coord,
                     std::pair<int,int> choice_dim,
                     std::vector<ChoiceWidget> widgets): m_coord(coord), m_choice_dim(choice_dim), m_widgets(widgets) {
    m_choices = CircularIndex(widgets.size());
}
ChoiceBar::ChoiceBar(std::pair<int,int> coord,
                     std::pair<int,int> choice_dim,
                     std::vector<std::pair<std::string,std::string>> widgets): m_coord(coord), m_choice_dim(choice_dim) {
    m_choices = CircularIndex(widgets.size());
    for(auto const& widget: widgets) {
        m_widgets.push_back(ChoiceWidget(widget.second, widget.first));
    }
}

void ChoiceBar::draw(olc::PixelGameEngine& engine) const {
    int elapsed = get_last_display_elapsed();
    if(elapsed > 1.5) {
        return;
    }
    for(size_t i = 0; i < m_widgets.size(); i++) {
        size_t y = m_coord.second + i * m_choice_dim.second;
        bool name = m_choices.get_current() == i;
        m_widgets[i].draw(engine, {m_coord.first, y}, olc::GREY, m_choice_dim, name);
    }
    size_t y = m_coord.second + m_choices.get_current() * m_choice_dim.second;
    engine.DrawRect(m_coord.first,
                    y,
                    m_choice_dim.first + 1,
                    m_choice_dim.second,
                    olc::RED);
}
void ChoiceBar::update(const olc::PixelGameEngine& engine) {
    if(engine.GetMouseWheel() > 0) {
        m_choices.go_up();
        m_last_display = std::chrono::system_clock::now();
    }
    else if(engine.GetMouseWheel() < 0) {
        m_choices.go_down();
        m_last_display = std::chrono::system_clock::now();
    }
}
void ChoiceBar::add_choice(const ChoiceWidget& widget) {
    m_widgets.push_back(widget);
    m_choices.set_size(m_widgets.size());
}
void ChoiceBar::add_choice(std::string name, olc::Sprite sprite) {
    m_widgets.push_back(ChoiceWidget(sprite.Duplicate(), name));
    m_choices.set_size(m_widgets.size());
}

auto ChoiceBar::get_last_display() const { return m_last_display; }
int ChoiceBar::get_last_display_elapsed() const { 
    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - m_last_display;
    return elapsed_seconds.count();
}
