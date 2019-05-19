//
// Created by Erika on 5/18/19.
//

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>
#include "circle.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <map>



TEST_CASE("Circle sorted"){
    std::vector <Circle> circles;

    circles.emplace_back("Manzana", Vec2{250.0f, 250.0f}, 50.0f, Color{1.0f, 1.0f, 0.0f});
    circles.emplace_back("Chinchilla", Vec2{250.0f, 250.0f}, 25.0f, Color{1.0f, 0.0f, 0.0f});
    // using default comparison (operator <):
    std::sort(circles.begin(), circles.end());

    REQUIRE(std::is_sorted(circles.begin(), circles.end()));
};


int main(int argc, char *argv[]) {


    std::vector <Circle> circles;

    std::string input;
    std::cout << "name of the circle" << "\n";
    std::cin >> input;

    circles.emplace_back(input, Vec2{250.0f, 250.0f}, 50.0f, Color{1.0f, 1.0f, 0.0f});
    circles.emplace_back("Chinchilla", Vec2{250.0f, 250.0f}, 25.0f, Color{1.0f, 0.0f, 0.0f});


    // using default comparison (operator <):
    std::sort(circles.begin(), circles.end());
    // could also work like this (lambda): ... , [](const Circle &lhs, const Circle &rhs) -> bool { return lhs < rhs; });

    std::cout << "myvector contains:";
    for (std::vector<Circle>::iterator it = circles.begin(); it != circles.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';


    return Catch::Session().run(argc, argv);


}

