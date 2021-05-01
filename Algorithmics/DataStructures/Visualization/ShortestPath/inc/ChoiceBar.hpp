#ifndef CHOICEBAR_H
#define CHOICEBAR_H

#include "./CircularIndex.hpp"
#include "../lib/olcPixelGameEngine.h"
#include <chrono>

class ChoiceWidget {
    private:
        std::string m_name;
        olc::Sprite* m_sprite;

    public:
        ChoiceWidget(olc::Sprite* sprite = olc::Sprite(10, 10).Duplicate(),
                     std::string name = ""): m_name(name), m_sprite(sprite) {}
        ChoiceWidget(const ChoiceWidget& other) {
            m_name = other.m_name;
            m_sprite = other.m_sprite->Duplicate();
        }
        ChoiceWidget(std::string sprite_path, std::string name = ""):  m_name(name) {
            m_sprite = new olc::Sprite(sprite_path);
        }
        ~ChoiceWidget() {
            delete m_sprite;
        }

        std::string get_name() const { return m_name; }
        const olc::Sprite& get_sprite() const { return *m_sprite; }
        void set_name(std::string name) { m_name = name; }
        void set_sprite(olc::Sprite sprite) { m_sprite = sprite.Duplicate(); }

        void draw(olc::PixelGameEngine& engine,
                  std::pair<int,int> coord,
                  olc::Pixel color = olc::BLACK,
                  std::pair<int,int> dim = {-1, -1},
                  bool name = false) const {
            if(dim == std::pair<int,int>{-1, -1})
                dim = {m_sprite->width, m_sprite->height};
            engine.DrawRect(coord.first, coord.second, dim.first + 1, dim.second + 1, color);
            engine.DrawPartialSprite(coord.first + 1, coord.second + 1, m_sprite, 0, 0, dim.first, dim.second);
            if(name) {
                engine.FillRect(coord.first - 8 * m_name.size() - 2, coord.second, m_name.size() * 8, dim.second, olc::WHITE);
                engine.DrawString(coord.first - 8 * m_name.size() - 2, coord.second + dim.second / 2 - 4, m_name, olc::BLACK);
            }
        }
};

class ChoiceBar {
    public:
        ChoiceBar(std::pair<int,int> coord = {0, 0},
                  std::pair<int,int> choice_dim = {-1, -1},
                  std::vector<ChoiceWidget> widgets = {});
        ChoiceBar(std::pair<int,int> coord,
                  std::pair<int,int> choice_dim,
                  std::vector<std::pair<std::string,std::string>> widgets);
            
        void draw(olc::PixelGameEngine& engine) const;
        void update(const olc::PixelGameEngine& engine);
        void add_choice(const ChoiceWidget& widget);
        void add_choice(std::string name, olc::Sprite sprite);

        auto get_last_display() const;
        int get_last_display_elapsed() const;
    private:
        std::pair<int,int> m_coord, m_choice_dim;
        std::vector<ChoiceWidget> m_widgets;
        CircularIndex m_choices;
        std::chrono::time_point<std::chrono::system_clock> m_last_display;
};

#endif
