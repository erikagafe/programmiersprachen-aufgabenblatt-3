//
// Created by Erika on 5/18/19.
//

#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <set>
#include "circle.hpp"
#include <iostream>
#include <algorithm>
#include <string>



int main(int argc, char* argv[]){
    Circle circle;
    std::string input;

    std::cout<< "name of the circle" << "\n";
    std::cin >> input;

    Circle circle1(input, {600,60}, 35,{0.5,0.5,1.0});
    std::set<Circle> circles;
    circles.insert(circle);
    circles.insert(circle1);

    std::cout<< circle << "\n";
    std::cout<< circle1 << "\n";
}

