//
// Created by Erika on 5/19/19.
//

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>



bool is_multiple_of_3(unsigned int i)
{
    return (i % 3)==0;
}

void print(const std::vector<unsigned int> &vec)
{
    for (const auto& i: vec)
        std::cout << i << ' ';
    std::cout << std::endl;
}



TEST_CASE("filter alle vielfache von drei", "[erase]"){

    std::vector<unsigned int> myVector;

    for (int i = 0; i <100; i++){
        unsigned int num = rand() % 100u;
        myVector.emplace_back(num);
    }
    int i = 0;
    for (unsigned int iter : myVector){
        i = i + 1;
        std::cout << i << " : " << iter << std::endl;
    }

    myVector.erase(std::remove_if(myVector.begin(), myVector.end(), [](unsigned int i) -> bool{ return !is_multiple_of_3(i);}), myVector.end());
    print(myVector);

    REQUIRE(std::all_of(myVector.begin(), myVector.end(), is_multiple_of_3));
};



int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

