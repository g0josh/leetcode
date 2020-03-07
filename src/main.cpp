#include<iostream>
#include <vector>
#include "../include/array_easy.hpp"

// namespace array_easy{
// int removeSortedDuplicates(std::vector<int>& nums){
//     if (nums.size() < 2){
//         return nums.size();
//     }
//     int prv = nums[0];
//     int count = 1;
//     for (auto i=nums.begin()+1; i<nums.end(); i++){
//         if (prv == *i){
//             nums.erase(i--);
//         }else{
//             prv = *i;
//             count++;
//         }
//     }
//     return count;
// }
// }

int main(int argc, char** argv){
    //Arrays
    std::vector<int> vi = {1,1};
    int c = array_easy::removeSortedDuplicatesF(vi);
    for (auto i = vi.begin();i<vi.end();i++){
        std::cout<<*i;
    }
    std::cout<<"\n"<<c<<"\n";
}