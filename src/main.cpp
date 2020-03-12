#include<iostream>
#include <vector>
#include "array_easy.hpp"


int main(int argc, char** argv){
    //Arrays
    std::vector<int> vi = {2,1,1,3};
    std::cout<<"Max profit of ";
    array_easy::printVector(vi, -1);
    std::cout<< " = "<<array_easy::maxProfit(vi);

    vi = {4,9,5};
    std::cout<<"\nRotated ";
    array_easy::printVector(vi, -1);
    std::cout<<" to ";
    array_easy::rotate(vi, 2);
    array_easy::printVector(vi, -1);

    vi = {4,9,5, 7, 5, 4};
    std::cout<<"\nDuplicates in ";
    array_easy::printVector(vi, -1);
    std::cout<< " = ";
    std::cout<<array_easy::containsDuplicate(vi);

    //find the only number that appears once
    std::cout <<"\nThe number that only appears once in ";
    array_easy::printVector(vi, -1);
    std::cout<< " is "<<array_easy::singleNumber(vi);

    //find intersection of arrays
    std::vector<int> vi2 = {9,4,9,8,4};
    std::cout<<"\nIntersecting elements of ";
    array_easy::printVector(vi, -1);
    std::cout<<" and ";
    array_easy::printVector(vi2, -1);
    std::cout<<" = ";
    std::vector<int> vir = array_easy::intersect(vi, vi2);
    array_easy::printVector(vir, -1);

    //plus one
    vi = {9,9,9};
    std::cout<<"\nplus one digits of ";
    array_easy::printVector(vi, -1);
    std::cout<<" = ";
    vir = array_easy::plusOne(vi);
    array_easy::printVector(vir, -1);

    //move zeroes
    vi = {0,1,0,3,12,0};
    std::cout<<"\nmove zeroes of ";
    array_easy::printVector(vi, -1);
    std::cout<<" = ";
    array_easy::moveZeroes(vi);
    array_easy::printVector(vi, -1);

    //twosum
    vi = {2, 7, 11, 15};
    int target = 9;
    std::cout<<"\ntwo sum of ";
    array_easy::printVector(vi, -1);
    std::cout<<" with target "<<target<<" = ";
    vir = array_easy::twoSum(vi, target);
    array_easy::printVector( vir, -1);

}