//
// Created by Erika on 5/5/19.
//

#include "rectangle.hpp"


Rectangle::Rectangle(Vec2 const& min_, Vec2 const & max_,  Color const& color): min_ (min_), max_ (max_), color_ (color_) {}

Rectangle::Rectangle () {
    length_ = 5;
    width_ = 5;
}

float Rectangle::area () const {
    return (width_ *length_ );
}

float Rectangle::circumference () const {
    float length = (max_.x - min_.x);
    float width = (max_.y - min_.y);
    return (2*(length + width));

}