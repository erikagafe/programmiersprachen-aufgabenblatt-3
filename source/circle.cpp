//
// Created by Erika on 5/5/19.
//

#include "circle.hpp"

Circle::Circle() {}

Circle::Circle(Vec2 const& position_, float const& radius_, Color const& color_) : position_ (position_), radius_ (radius_),  color_ (color_) {}

float Circle::perimeter() const {
    return 2 *radius_ * M_PI;
}

float Circle::area() const {
    return radius_ *radius_* M_PI;
}





