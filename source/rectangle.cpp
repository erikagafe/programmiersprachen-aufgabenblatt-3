//
// Created by Erika on 5/5/19.
//

#include "rectangle.hpp"



Rectangle::Rectangle () {
    length_ = 5;
    width_ = 5;
}

float Rectangle::area () const {
    return (width_ *length_ );
}
float Rectangle::perimeter () const {
    return (2*(length_ + width_));

}