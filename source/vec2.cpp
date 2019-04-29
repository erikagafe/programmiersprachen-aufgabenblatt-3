//
// Created by Erika on 4/29/19.
//

#include <iostream>
#include "vec2.hpp"


//Vec2& Vec2::operator+(Vec2 const& v){
//    Vec2 vec2;
//    vec2.x = this ->x +v.x;
//    vec2.y = this ->y +v.y;
//    return vec2;
//
//};


Vec2& Vec2::operator+=(Vec2 const& v){
    x += v.x;
    y += v.y;
    return *this;

};

Vec2& Vec2::operator -=(Vec2 const& v){
    x -= v.x;
    y -= v.y;
    return *this;

};
Vec2& Vec2::operator*=(float s){
    x = x * s;
    y = y * s;
    return *this;

};

Vec2& Vec2::operator/=(float s){
    x = x / s;
    y = y / s;
    return *this;

};

//int main()
//{
//    Vec2 a;
//    Vec2::operator+=(a); // An example call to "operator+"
//    std::cout << a.x;
//    return 0;
//}
