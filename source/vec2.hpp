//
// Created by Erika on 4/24/19.
//

#ifndef BLATT2_VEC2_HPP
#define BLATT2_VEC2_HPP


struct Vec2 {

    float x = 0.0f;
    float y = 0.0f;

    Vec2& operator+=(Vec2 const& v);
    Vec2& operator -=(Vec2 const& v);
    Vec2& operator*=(float s);
    Vec2& operator/=(float s);


};

Vec2 operator+(Vec2 const& u, Vec2 const& v);
Vec2 operator-(Vec2 const& u, Vec2 const& v);
Vec2 operator*(Vec2 const& v, float s);
Vec2 operator/(Vec2 const& v, float s);
Vec2 operator*(float s, Vec2 const& v);


#endif //BLATT2_VEC2_HPP


