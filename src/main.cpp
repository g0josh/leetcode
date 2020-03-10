#include<iostream>
#include <vector>
#include "array_easy.hpp"

int main(int argc, char** argv){
    //Arrays
    std::vector<int> vi = {2,1,1,3};
    std::cout<<"Input vector = ";
    array_easy::printVector(vi, -1);
    std::cout<<"Max profit = "<<array_easy::maxProfit(vi)<<std::endl;
}