#pragma once
#include <vector>

namespace arrays_easy{

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

std::vector<int> twoSum(std::vector<int>& nums, int target);

bool isValidSudoku(std::vector<std::vector<char>>&);

void rotateMatrix90(std::vector<std::vector<int>>&);
}
