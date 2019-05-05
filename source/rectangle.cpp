//
// Created by Erika on 5/5/19.
//

#include "rectangle.hpp"


Rectangle::Rectangle(Vec2 const& min_, Vec2 const & max_,  Color const& color_): min_ (min_), max_ (max_), color_ (color_) {}

Rectangle::Rectangle () {}

float Rectangle::area () const {
    return (width_ *length_ );
}

float Rectangle::circumference () const {
    float length = (max_.x - min_.x);
    float width = (max_.y - min_.y);
    return (2*(length + width));

}

void Rectangle::draw(Window const& win, float thickness) const {
    win.draw_line(min_.x, min_.y,max_.x,min_.y,color_.r, color_.g, color_.b, thickness);
    win.draw_line(min_.x, min_.y,min_.x,max_.y,color_.r, color_.g, color_.b,thickness);
    win.draw_line(max_.x, min_.y,max_.x,max_.y,color_.r, color_.g, color_.b,thickness);
    win.draw_line(min_.x, max_.y,max_.x,max_.y,color_.r, color_.g, color_.b, thickness);
}


void Rectangle::draw(Window const& win) const {
    win.draw_line(min_.x, min_.y,max_.x,min_.y,color_.r, color_.g, color_.b);
    win.draw_line(min_.x, min_.y,min_.x,max_.y,color_.r, color_.g, color_.b);
    win.draw_line(max_.x, min_.y,max_.x,max_.y,color_.r, color_.g, color_.b);
    win.draw_line(min_.x, max_.y,max_.x,max_.y,color_.r, color_.g, color_.b);
}