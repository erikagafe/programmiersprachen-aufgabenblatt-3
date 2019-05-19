//
// Created by Erika on 5/19/19.
//

#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

int main (){

    std::vector<int> v_0(10);  // vector of size 10
    for (auto& v : v_0) {   // iterator
        v = std :: rand (); // assign a random value to the vector
    }

    std::copy(std::cbegin(v_0), std::cend(v_0),
              std::ostream_iterator<int>(std::cout, "\n")); // output the vector from front to back with ostream.

    std::list<int> l_0(std::cbegin(v_0), std::cend(v_0)); // list created that is filled the elements of v_0
    std::list<int> l_1(std::cbegin(l_0), std::cend(l_0)); // list created that is filled the elements of l_0
    std::reverse(std::begin(l_1), std::end(l_1)); // the order of l_1 is reversed
    std::copy(std::cbegin(l_1), std::cend(l_1),
              std::ostream_iterator<int>(std::cout, "\n")); // output the list from front to back with ostream.


    std::cout<< "before sorted" <<std::endl;
    l_1.sort(); // l_1 is sorted
    std::copy(l_1.cbegin(), l_1.cend(),
              std::ostream_iterator<int>(std::cout, "\n"));// output the sorted list from front to back with ostream.

    std::cout<< "before generated" <<std::endl;
    std::generate(std::begin(v_0), std::end(v_0), std::rand); //assign a new random number to v_0
    std::copy(v_0.crbegin(), v_0.crend(),std::ostream_iterator<int>(std::cout, "\n")); // output the vector from front to back with ostream.


 return 0;
}