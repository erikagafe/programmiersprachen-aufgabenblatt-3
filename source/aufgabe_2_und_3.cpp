//
// Created by Erika on 5/15/19.
//



#include <iostream>
#include <list>
#include <iterator>
#include<set>



int main()
{
    std::list<unsigned int> listOfNumbers;
    std::set<unsigned int> setOfNumbers;
    for (int i = 0; i <100; i++){
        unsigned int j = rand() % 100;
        listOfNumbers.push_back(j);
        setOfNumbers.insert(j);

    }

    std::set<unsigned int>::iterator sit;
    std::list<unsigned int>::iterator it = listOfNumbers.begin();
    while(it != listOfNumbers.end())
    {
        std::cout<<(*it)<<"  ";
        it++;

    }
    std::cout<< "set " <<std::endl;
    for (int i = 0; i <100; i++){
        sit = setOfNumbers.find(i);
        if(sit == setOfNumbers.end())
            std::cout<<"Number not found :"<< i <<std::endl;
    }


   return 0;


}


