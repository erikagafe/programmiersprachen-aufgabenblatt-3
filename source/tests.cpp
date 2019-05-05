#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}



/* Test cases for Vec2 */
TEST_CASE("vec2", "[Vec2]"){
    Vec2 a;
    Vec2 b{5.1f, -9.3f};
    REQUIRE(a.x == 0.0f);
    REQUIRE(a.y == 0.0f);
    REQUIRE(b.x == 5.1f);
    REQUIRE(b.y == -9.3f);
};


TEST_CASE("Vec2& operator+=", "[Vec2& operator+=]"){
    Vec2 b{5.1f, -9.3f};
    Vec2 a{5.1f, -9.3f};
    a+=b;
    REQUIRE(a.x== 10.2f);
    REQUIRE(a.y == -18.6f);
};

TEST_CASE("Vec2& operator-=", "[Vec2& operator-=]"){
    Vec2 b{5.1f, -9.3f};
    Vec2 a{5.1f, -9.3f};
    a-=b;
    REQUIRE(a.x== 0.0f);
    REQUIRE(a.y == 0.0f);
};

TEST_CASE("Vec2& operator*=", "[Vec2& operator*=]"){
    Vec2 a{5.1f, -9.3f};
    float b = 2.5;
    a*=b;
    REQUIRE(a.x== 12.75f);
    REQUIRE(a.y == -23.25f);
};

TEST_CASE("Vec2& operator/=", "[Vec2& operator/=]"){
    Vec2 a{5.1f, -9.3f};
    float b = 1.3;
    a/=b;
    REQUIRE(a.x ==  Approx(3.9230).epsilon(0.1));
    REQUIRE(a.y ==  Approx(-7.1538).epsilon(0.1));
};

TEST_CASE("Vec2 operator+", "[Vec2 operator+]"){
    Vec2 a{5.1f, -9.3f};
    Vec2 b{5.1f, -9.3f};
    Vec2 c = a+b;
    REQUIRE(c.x== 10.2f);
    REQUIRE(c.y == -18.6f);
};

TEST_CASE("Vec2 operator*", "[Vec2 operator*]"){
    Vec2 a{5.1f, -9.3f};
    float b = 2.5;
    Vec2 c = a*b;
    REQUIRE(c.x== 12.75f);
    REQUIRE(c.y == -23.25f);
};

TEST_CASE("Vec2 operator/", "[Vec2 operator/]"){
    Vec2 a{5.1f, -9.3f};
    float b = 1.3;
    Vec2 c = a/b;
    REQUIRE(c.x ==  Approx(3.9230).epsilon(0.1));
    REQUIRE(c.y ==  Approx(-7.1538).epsilon(0.1));
};

TEST_CASE("Vec2 operator* float", "[Vec2 operator*]"){
    float b = 2.5;
    Vec2 a{5.1f, -9.3f};
    Vec2 c = b*a;
    REQUIRE(c.x== 12.75f);
    REQUIRE(c.y == -23.25f);
};


/* Test cases for Mat2*/

TEST_CASE("Mat2 operator*=", "[Mat2 operator*=]"){
    Mat2 a{2,6,4,8};
    Mat2 b{2,6,4,8};
    b*=a;
    REQUIRE(b.e_00== 28.0f);
    REQUIRE(b.e_01 == 40.0f);
};

TEST_CASE("Mat2 operator*", "[Mat2 operator*]"){
    Mat2 a{2,6,4,8};
    Mat2 b{2,6,4,8};
    Mat2 c = a*b;
    REQUIRE(c.e_00== 28.0f);
    REQUIRE(c.e_01 == 40.0f);
};

TEST_CASE("Vec2 operator* mat2", "[Vec2 operator* mat2]"){
    Mat2 a{4,6,2,8};
    Vec2 b{4,6};
    Vec2 c = a*b;
    REQUIRE(c.x== 28.0f);
    REQUIRE(c.y == 72.0f);
};


TEST_CASE("Vec2 operator*1 mat2", "[Vec2 operator*1 mat2]"){
    Vec2 b{4,6};
    Mat2 a{4,6,2,8};
    Vec2 c = b*a;
    REQUIRE(c.x== 28.0f);
    REQUIRE(c.y == 72.0f);
};

TEST_CASE("Mat2 inverse", "[Mat2 inverse]"){
    Mat2 src {4,2,7,6};
    Mat2 inv = inverse(src);
    REQUIRE(inv.e_00 == Approx(0.6f).epsilon(0.01));
    REQUIRE(inv.e_10 == Approx(-0.2f).epsilon(0.01));
    REQUIRE(inv.e_01== Approx(-0.7f).epsilon(0.01));
    REQUIRE(inv.e_11== Approx(0.4f).epsilon(0.01));
    REQUIRE_THROWS(inverse({2,4,2,4} ));
};
TEST_CASE("Mat2 transpose", "[Mat2 transpose]"){
    Mat2 src {4,2,7,6};
    Mat2 trans = transpose(src);
    REQUIRE(trans.e_00 == 4.0f);
    REQUIRE(trans.e_10 == 7.0f);
    REQUIRE(trans.e_01== 2.0f);
    REQUIRE(trans.e_11==  6.0f);
};


TEST_CASE("Mat2 make_rotation_mat2", "[Mat2 make_rotation_mat2]"){
    float phi {0.8};
    Mat2 rot = make_rotation_mat2(phi);
    REQUIRE(rot.e_00 == Approx(0.69670671f).epsilon(0.001));
    REQUIRE(rot.e_10 == Approx(0.71735609f).epsilon(0.001));
    REQUIRE(rot.e_01==  Approx(-0.71735609f).epsilon(0.001));
    REQUIRE(rot.e_11==  Approx(0.69670671f).epsilon(0.001));
};


TEST_CASE("Color color", "[color]"){
    Color a;
    REQUIRE(0.45f == a.r);
    REQUIRE(0.45f == a.g);
    REQUIRE(0.45f == a.b);
};


TEST_CASE("Circle Circumference", "[Circle Circumference]"){
    Circle c = Circle(Vec2{}, 2.0f, Color {});
    Circle b = Circle(Vec2{2.3f, 5.5f }, 4.0f, Color {});
    Circle d = Circle(Vec2{}, 0.0000001f, Color {});

    REQUIRE(Approx(c.circumference()) == 2 * 2 * M_PI);
    REQUIRE(b.circumference() ==  Approx(25.1328).epsilon(0.1));
    REQUIRE_THROWS(d.circumference());
};

TEST_CASE("Rectangle Circumference", "[Rectangle Circumference]"){
    Rectangle c = Rectangle(Vec2 {2.0f,2.0f}, Vec2 {4.0f,4.0f},  Color {});
    Rectangle b = Rectangle(Vec2 {0.0f,0.0f}, Vec2 {4.0f,4.0f},  Color {});
    REQUIRE(c.circumference() ==  Approx(8.0f).epsilon(0.1));
    REQUIRE(b.circumference() ==  Approx(16.0f).epsilon(0.1));

};

