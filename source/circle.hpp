//
// Created by Erika on 5/5/19.
//

#ifndef BLATT2_CIRCLE_HPP
#define BLATT2_CIRCLE_HPP

#include "color.hpp"
#include "vec2.hpp"
#include <cmath>
#include <iostream>
#include "window.hpp"


class Circle {

    private:
        std::string name_ = "Chinchilla";
        Vec2 position_;
        float radius_ = 0.0f;
        Color color_;


    public:
        Circle();
        Circle(Vec2 const& position, float const& radius, Color const& color);
        Circle(std::string name, Vec2 const& position, float const& radius, Color const& color);
        std::string print() const;
        float circumference() const;
        float area() const;
        float get_radius() const;
        void draw (Window const& win) const;
        void draw (Window const& win, float thickness) const;
        bool is_inside(Vec2 const& point) const;

};

std::ostream& operator <<(std::ostream& os, Circle const& c);
bool operator ==(const Circle& c1, const  Circle& c2);
bool operator <(const Circle& c1, const  Circle& c2);
bool operator >(const Circle& c1, const  Circle& c2);


#endif //BLATT2_CIRCLE_HPP
