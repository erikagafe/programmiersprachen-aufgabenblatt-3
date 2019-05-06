//
// Created by Erika on 5/5/19.
//

#include "rectangle.hpp"


Rectangle::Rectangle(Vec2 const &min, Vec2 const &max, Color const &color) : min_(min), max_(max), color_(color) {
    if (min_.x > max_.x) {
        std::cerr << "X min / max order confused, flipping the order" << std::endl;
        float temp = min_.x;
        min_.x = max_.x;
        max_.x = temp;
    }

    if (min_.y > max_.y) {
        std::cerr << "Y min / max order confused, flipping the order" << std::endl;
        float temp = min_.y;
        min_.y = max_.y;
        max_.y = temp;
    }
}

Rectangle::Rectangle() {}

float Rectangle::area() const {
    return (width_ * length_);
}

float Rectangle::circumference() const {
    float length = (max_.x - min_.x);
    float width = (max_.y - min_.y);
    return (2 * (length + width));

}

void Rectangle::draw(Window const &win, float thickness) const {
    win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
    win.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    win.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    win.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
}


void Rectangle::draw(Window const &win) const {
    win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b);
    win.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b);
    win.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b);
    win.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b);
}

bool Rectangle::is_inside(Vec2 const &point) const {
    return point.x >= min_.x && point.x <= max_.x && point.y >= min_.y && point.y <= max_.y;
}