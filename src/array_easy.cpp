#include <iostream>
#include <vector>
namespace array_easy{

int removeSortedDuplicates(std::vector<int>& nums){
    if (nums.size() < 2){
        return nums.size();
    }
    int prv = nums[0];
    int count = 1;
    for (auto i=nums.begin()+1; i<nums.end(); i++){
        if (prv == *i){
            nums.erase(i--);
        }else{
            prv = *i;
            count++;
        }
    }
    return count;
}

int removeSortedDuplicatesF(std::vector<int>& nums){
    if (nums.size() < 2){
        return nums.size();
    }
    std::vector<int>::iterator currPos = nums.begin();
    std::vector<int>::iterator pos = nums.begin()+1;
    while (pos < nums.end()){
        if (*(pos) > *(currPos)){
            *(++currPos) = *(pos++);
        }else{
            pos++;
        }
    }
    return currPos - nums.begin() + 1;
}

}

// int main(){
//     std::vector<int> al = {1,1};
//     int c = array_easy::removeSortedDuplicatesF(al);
//     std::cout<<c<<std::endl;
//     for (int i = 0; i < c; i++){
//         std::cout<<al[i];
//     }
// }