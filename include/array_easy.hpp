#pragma once
#include <vector>

namespace array_easy{

//print a vector
template <typename T>
void printVector(std::vector<T>& V, int upto){
    (upto < 0)?upto = V.size():upto = upto;
    std::cout<<"[ ";
    for (int i = 0; i<upto; i++){
        std::cout<<V[i]<<" ";
    }
    std::cout<<"]"<<std::endl;
}

//Remove duplicates in a sorted array
int removeSortedDuplicates(std::vector<int>&);

int maxProfit(std::vector<int> &prices);

int maxProfit2(std::vector<int> &prices);

void rotate(std::vector<int> &nums, int k);

bool containsDuplicate(std::vector<int> &nums);

int singleNumber(std::vector<int> &nums);

std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2);

std::vector<int> plusOne(std::vector<int> &digits);

void moveZeroes(std::vector<int> &nums);

} // namespace array_easy