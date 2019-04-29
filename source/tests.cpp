#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


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