//
// Created by Erika on 5/15/19.
//



#include <iostream>
#include <list>
#include <iterator>
#include <map>
#include<set>
#include<vector>
#include <algorithm>



int main()
{
    std::list<unsigned int> listOfNumbers;
    std::set<unsigned int> setOfNumbers;
    std::map<unsigned int, int> mapOfNumber;
    std::map<unsigned int, int>::iterator itMap;
    for (int i = 0; i <100; i++){
        unsigned int j = rand() % 100u;
        listOfNumbers.push_back(j);
        itMap = mapOfNumber.find(j);
        // Check if element exists in map or not
        if (itMap != mapOfNumber.end()) {
            unsigned int key = itMap->first;
            int value = itMap->second;
            mapOfNumber[key] = value + 1;

        } else {
            mapOfNumber[j] = 1;
        }

    }

    auto it = listOfNumbers.begin();
    while(it != listOfNumbers.end())
    {
        std::cout<<(*it)<<"  ";
        setOfNumbers.insert(*it);
        it++;

    }

    std::cout<<std::endl;
    std::cout<< "set " <<std::endl;


    std::set<unsigned int>::iterator sit;
    for (int i = 0; i <100; i++){
        sit = setOfNumbers.find(i);
        if(sit == setOfNumbers.end())
            std::cout<<"Number not found :"<< i <<std::endl;
    }


    auto iteratorMap = mapOfNumber.begin() ;
    while(iteratorMap != mapOfNumber.end())
    {
        unsigned int key = iteratorMap->first;
        int value = iteratorMap->second;
        std::cout << "key = " << key << " :: Value = " << value << std::endl;
        iteratorMap ++;

    }


    // aufgabe 3.10

    std::vector<unsigned int> myVector;
    myVector.resize(listOfNumbers.size());
    std::copy (listOfNumbers.begin(), listOfNumbers.end(), myVector.begin());

    std::cout << "Vector v2 contains following elements" << std::endl;

    for (unsigned int iter : myVector)
        std::cout << iter << std::endl;


    return 0;


}


