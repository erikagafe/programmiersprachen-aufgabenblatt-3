//
// Created by Erika on 5/5/19.
//

#include <iostream>
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"
using namespace std;

#ifndef BLATT2_RECTANGLE_HPP
#define BLATT2_RECTANGLE_HPP



class Rectangle {


    private:
        Vec2 min_;
        Vec2 max_;
        float length_  = 0.0f;
        float width_   = 0.0f;
        Color color_;

    public:
        Rectangle ();
        Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& color_);
        float area () const ;
        float circumference () const ;
        void draw(Window const& win) const;
        void draw(Window const& win, float thickness) const;
        bool is_inside(Vec2 const& point) const;


};

#endif //BLATT2_RECTANGLE_HPP
