//
// Created by Erika on 4/29/19.
//

#include "mat2.hpp"
#include "vec2.hpp"



Mat2 &Mat2::operator*=(Mat2 const &m) {

    // e_00  e_01
    // e_10  e_11

    float m_e_00 = e_00;
    float m_e_01 = e_01;
    float m_e_10 = e_10;
    float m_e_11 = e_11;

    e_00 = (m_e_00 * m.e_00) + (m_e_01 * m.e_10);
    e_01 = (m_e_00 * m.e_01) + (m_e_01 * m.e_11);
    e_10 = (m_e_10 * m.e_00) + (m_e_11 * m.e_10);
    e_11 = (m_e_10 * m.e_01) + (m_e_11 * m.e_11);

    return *this;

};

Mat2 operator*(Mat2 const &m1, Mat2 const &m2) {
    return Mat2{m1} *= m2;

}

Vec2 operator*(Mat2 const &m, Vec2 const &v) {
    Vec2 v1;

    v1.x = (m.e_00 * v.x) + (m.e_01 * v.y);
    v1.y = (m.e_10 * v.x) + (m.e_11 * v.y);

    return Vec2{v1};

}

Vec2 operator*(Vec2 const &v, Mat2 const &m) {

    Vec2 v1;
    v1.x = (m.e_00 * v.x) + (m.e_01 * v.y);
    v1.y = (m.e_10 * v.x) + (m.e_11 * v.y);

    return v1;

}

Mat2 inverse(Mat2 const &m) {
    Mat2 inv;
    float determinant = (m.e_00 * m.e_11) - (m.e_01 * m.e_10);

    if(std::abs(determinant) < 0.001f) /* null check */{

        throw std::runtime_error("Prohibited input");
    }

    inv.e_00 = m.e_11 / determinant;
    inv.e_01 = -(m.e_01) / determinant;
    inv.e_10 = -(m.e_10) / determinant;
    inv.e_11 = m.e_00 / determinant;

    return inv;
}

Mat2 transpose(Mat2 const& m){
    Mat2 trans;

    trans.e_00 = m.e_00;
    trans.e_01 = m.e_10;
    trans.e_10 = m.e_01;
    trans.e_11 = m.e_11;

    return trans;

}
Mat2 make_rotation_mat2(float phi){
    Mat2 rot;
    // e_00  e_01
    // e_10  e_11
    rot.e_00 = cosf(phi);
    rot.e_10 = sinf(phi);
    rot.e_01 = sinf(-phi);
    rot.e_11 = cos(phi);

    return rot;
}