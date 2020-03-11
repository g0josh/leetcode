#include<iostream>
#include <vector>
#include "array_easy.hpp"


int main(int argc, char** argv){
    //Arrays
    std::vector<int> vi = {2,1,1,3};
    std::cout<<"Input vector = ";
    array_easy::printVector(vi, -1);
    std::cout<<"Max profit = "<<array_easy::maxProfit(vi)<<std::endl;

    //     std::vector<int> vi = {4,9,5};
//     array_easy::printVector(vi, -1);
//     array_easy::rotate(vi, 2);
//     array_easy::printVector(vi, -1);
//     std::cout<<"Contains duplicate : "<<array_easy::containsDuplicate(vi)<<"\n";

//     //find the only number that appears once
//     std::cout <<"The number that only appears once = "<<array_easy::singleNumber(vi)<<"\n";

//     //find intersection of arrays
//     std::vector<int> vi2 = {9,4,9,8,4};
//     array_easy::printVector(vi2, -1);
//     std::cout<<"Intersecting elements = ";
//     array_easy::printVector(array_easy::intersect(vi, vi2), -1);

//     //plus one
//     vi = {9,9,9};
//     std::cout<<"plus one digits of ";
//     array_easy::printVector(vi, -1);
//     std::cout<<"= ";
//     array_easy::printVector(array_easy::plusOne(vi), -1);

    //move zeroes
    vi = {0,1,0,3,12,0};
    std::cout<<"move zeroes of ";
    array_easy::printVector(vi, -1);
    std::cout<<"= ";
    array_easy::moveZeroes(vi);
    array_easy::printVector(vi, -1);
}