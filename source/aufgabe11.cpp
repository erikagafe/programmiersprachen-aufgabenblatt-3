//
// Created by Erika on 5/19/19.
//

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <functional>


//struct is_multiple_of_3 {
//    bool operator() (const unsigned int& i) const {return i%3==0;}
//    typedef unsigned int argument_type;
//};

bool is_multiple_of_3(unsigned int i)
{
    return (i % 3)==0;
};

template <class _Container>
void print(_Container& a)
{
    for (const auto& i: a)
        std::cout << i << ' ';
    std::cout << std::endl;
};

bool is_even(int n) { return n % 2 == 0; };

template <class _Container, class _Predicate>
_Container filter (_Container a, _Predicate& b) {
    a.erase(std::remove_if(a.begin(), a.end(), [b](int n)->bool{ return!b(n);}), a.end());
    return a;
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
//    myVector.erase(std::remove_if(myVector.begin(), myVector.end(), std::not1(is_multiple_of_3())), myVector.end());
    print(myVector);

    //REQUIRE(std::all_of(myVector.begin(), myVector.end(), is_multiple_of_3()));
    REQUIRE(std::all_of(myVector.begin(), myVector.end(), is_multiple_of_3));
};

TEST_CASE("filter even", "[erase_even]"){

    std::vector<int> v{1,2,3,4,5,6};
    std::vector<int> all_even = filter(v, is_even);

    print(all_even);

    REQUIRE(std::all_of(all_even.begin(), all_even.end(), is_even));
};




int main(int argc, char* argv[]) {

    return Catch::Session().run(argc, argv);

}

