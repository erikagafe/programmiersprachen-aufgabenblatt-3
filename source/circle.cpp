//
// Created by Erika on 5/5/19.
//

#include "circle.hpp"

Circle::Circle () {
    // nada
}

Circle::Circle (Vec2 const &position, float const &radius, Color const &color) :
        name_(""),
        position_(position),
        radius_(radius),
        color_(color) {
    // nada
}

Circle::Circle(std::string name, Vec2 const &position, float const &radius, Color const &color) :
        name_(name),
        position_(position),
        radius_(radius),
        color_(color) {
    // nada
}

float Circle::circumference() const {
    if (std::abs(radius_) < 0.001f) /* null check */{

        throw std::runtime_error("Prohibited input");
    }
    return 2 * radius_ * M_PI;
}

std::string Circle::print()const {
    return "Name: " + name_ + "\n"
           + "Radius: " + std::to_string(radius_) + "\n"
           + "Position : {" + std::to_string(position_.x) + ", " + std::to_string(position_.y) + "}\n"
           + "Color: {" + std::to_string(color_.r) + ", " + std::to_string(color_.g) + ", " + std::to_string(color_.b) + "}\n";
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

float Circle::get_radius() const {
    return radius_;
}

std::ostream& operator <<(std::ostream& os, Circle const& c){
    return os << c.print();
}
bool operator ==(const Circle& c1,const  Circle& c2){
    return c1.get_radius() == c2.get_radius();

}

bool operator <(const Circle& c1,const Circle& c2){
    return c1.get_radius() < c2.get_radius();
}

bool operator >(const Circle& c1, const Circle& c2){
    return c1.get_radius() > c2.get_radius();
}



