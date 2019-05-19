//
// Created by Erika on 5/19/19.
//


#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>




void print(const std::vector< int> &vec)
{
    for (const auto& i: vec)
        std::cout << i << ' ';
    std::cout << std::endl;
}


TEST_CASE("test for 10", "[10]"){

    std::vector<int> v_1{1,2,3,4,5,6,7,8,9};
    std::vector<int> v_2{9,8,7,6,5,4,3,2,1};
    std::vector<int> v_3(9);


    std::transform(v_1.begin(), v_1.end(), v_2.begin(),v_3.begin(),
                   [](int x1, int x2) -> int { return(x1 + x2); });

    print(v_3);


    REQUIRE(std::all_of(v_3.begin(), v_3.end(), [](int i){return i == 10;}));
};



int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}


