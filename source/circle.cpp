//
// Created by Erika on 5/5/19.
//

#include "circle.hpp"

Circle::Circle() {}

Circle::Circle(Vec2 const &position_, float const &radius_, Color const &color_) : position_(position_),
                                                                                   radius_(radius_), color_(color_) {}

float Circle::circumference() const {
    if (std::abs(radius_) < 0.001f) /* null check */{

        throw std::runtime_error("Prohibited input");
    }
    return 2 * radius_ * M_PI;
}

float Circle::area() const {
    return radius_ * radius_ * M_PI;
}

void Circle::draw(Window const &win, float thickness) const {
    float theta;
    float delta = M_PI / 36.0f;

    float xp, xn;
    float yp, yn;
    float old_theta;
    float new_theta;

    for (theta = 0.0f; theta <= (2 * M_PI); theta = theta + delta) {
        old_theta = theta;
        new_theta = theta + delta;
        xp = cosf(old_theta) * radius_ + position_.x;
        yp = sinf(old_theta) * radius_ + position_.y;
        xn = cosf(new_theta) * radius_ + position_.x;
        yn = sinf(new_theta) * radius_ + position_.y;
        win.draw_line(xp,yp, xn, yn, color_.r, color_.g, color_.b, thickness);
    }

}

void Circle::draw(Window const &win) const {
    float theta;
    float delta = M_PI / 36.0f;

    float xp, xn;
    float yp, yn;
    float old_theta;
    float new_theta;

    for (theta = 0.0f; theta <= (2 * M_PI); theta = theta + delta) {
        old_theta = theta;
        new_theta = theta + delta;
        xp = cosf(old_theta) * radius_ + position_.x;
        yp = sinf(old_theta) * radius_ + position_.y;
        xn = cosf(new_theta) * radius_ + position_.x;
        yn = sinf(new_theta) * radius_ + position_.y;
        win.draw_line(xp,yp, xn, yn, color_.r, color_.g, color_.b);
    }

}

bool Circle::is_inside(Vec2 const& point) const{
    float d_radius = pow(radius_,2.0f);
    float p= pow((point.x - position_.x),2.0f) + pow((point.y - position_.y),2.0f);
    return p < d_radius;

}



