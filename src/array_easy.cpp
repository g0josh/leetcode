#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

namespace array_easy{

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
int removeSortedDuplicates(std::vector<int>& nums){
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

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
//Assuming one CANNOT buy and sell on the same day.
int maxProfit(std::vector<int>& prices) {
    if (prices.size() < 2){
        return 0;
    }
    std::vector<int>::iterator bought = prices.begin();
    int profit = 0;
    while (bought < prices.end()-1){
        int _profit = 0;
        auto new_bought = bought;
        for (auto try_sell = bought+1; try_sell < prices.end(); try_sell++){
            if ((*try_sell) <= (*bought) && _profit == 0){
                new_bought = try_sell;
                break;
            }
            int new_profit = (*try_sell) - (*bought);
            if (new_profit > _profit){
                _profit = new_profit;
                if (try_sell+1 == prices.end()){
                    new_bought = try_sell;
                }
            }else if (_profit > 0 && new_profit <= _profit ){
                new_bought = try_sell;
                break;
            }
        }
        profit += _profit;
        (new_bought == bought)?bought++:bought = new_bought;
    }
    return profit;
}

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//Assuming one can buy and sell in the same day.
int maxProfit2(std::vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int profit = 0;
    for (int i = 1; i<prices.size();++i){
        if (prices[i]>prices[i-1]){
            profit += prices[i]-prices[i-1];
        }
    }
    return profit;
}

//https://leetcode.com/problems/rotate-array/
void rotate(std::vector<int>& nums, int k) {
    if (nums.size() < 2 || k % nums.size() == 0){
        return;
    }
    int index = -1;
    int next = nums[0];
    int started = 0;
    for (int i = 0; i < nums.size(); i++){
        if (index == -1){
            index = 0;
        }else if (index == started){
            // next = nums[index+1];
            started = ++index;
            next = nums[index];
        }
        index = (index+k)%nums.size();
        int _next = nums[index];
        nums[index] = next;
        next = _next;
    }
}

//https://leetcode.com/problems/contains-duplicate/
bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_map<int,int> map;
    for (int i = 0; i < nums.size(); i++){
        auto got = map.find(nums[i]);
        if (got == map.end()){
            map[nums[i]] = nums[i];
        }else{
            return true;
        }
    }
    return false;
}

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/
int singleNumber(std::vector<int>& nums) {
    // std::unordered_map<int, int> map;
    // for (int num:nums){
    //     std::unordered_map<int, int>::iterator got = map.find(num);
    //     if (got == map.end()){
    //         map[num] = 1;
    //     }else{
    //         map.erase(num);
    //     }
    // }
    // if (map.empty()){
    //     return 0;
    // }else{
    //     return map.begin()->first;
    // }

    //better approach with XOR
    //if a == b, a xor b = 0
    //and a xor 0 = a
    int result = 0;
    for (int num:nums){
        result = result ^ num;
    }
    return result;
}

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/
std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> result;
    std::unordered_map<int,int> big_map;
    std::unordered_map<int,int> small_map;
    std::vector<int> big = nums1;
    std::vector<int> small = nums2;
    if (nums1.size()<nums2.size()){
        big = nums2;
        small = nums1;
    }
    std::unordered_map<int,int>::iterator got_big, got_small;
    for (int i = 0; i<big.size(); i++){
        if (i < small.size() && big[i] == small[i]){
            result.push_back(big[i]);
            continue;
        }
        got_big = big_map.find(big[i]);
        got_small = small_map.find(big[i]);

        if (got_small != small_map.end()){
            if (got_small->second > 1){
                got_small->second -= 1;
            }else{
                small_map.erase(got_small);
            }
            result.push_back(got_small->first);
        }else if (got_big == big_map.end()){
            big_map[big[i]] = 1;
        }else{
            big_map[big[i]] += 1;
        }

        if (i+1 > small.size()){
            continue;
        }
        got_big = big_map.find(small[i]);
        got_small = small_map.find(small[i]);

        if (got_big != big_map.end()){
            if (got_big->second > 1){
                got_big->second -= 1;
            }else{
                big_map.erase(got_big);
            }
            result.push_back(got_big->first);
        }else if (got_small == small_map.end()){
            small_map[small[i]] = 1;
        }else{
            small_map[small[i]] += 1;
        }
    }
    return result;
}

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/
std::vector<int> plusOne(std::vector<int>& digits) {
    int carry = 1;
    std::vector<int> result (digits.size());
    std::vector<int>::reverse_iterator rev_result = result.rbegin();
    for (auto i=digits.rbegin(); i<digits.rend();i++){
        int j = (*i) + carry;
        if (j>9){
            (*rev_result) = 0;
            carry = 1;
        }else{
            (*rev_result) = j;
            carry = 0;
        }
        rev_result++;
    }
    if (carry == 1){
        result.insert(result.begin(), 1);
    }
    return result;
}

//move zeroes
void moveZeroes(std::vector<int>& nums) {
    int* curr_pos = nums.data();
    std::vector<int*> empty_spots;
    int next_empty_spot = 0;
    int zero_count = 0;
    for (int i = 0; i < nums.size(); i++){
        if (*curr_pos == 0){
            empty_spots.push_back(curr_pos);
            zero_count++;
        }else{
            if (empty_spots.size() != 0 && next_empty_spot < empty_spots.size()){
                *(empty_spots[next_empty_spot]) = *curr_pos;
                empty_spots.push_back(curr_pos);
                next_empty_spot++;
            }
        }
        curr_pos++;
    }
    std::vector<int>::reverse_iterator rev_nums = nums.rbegin();
    for (;zero_count>0;zero_count--){
        *rev_nums = 0;
        rev_nums++;
    }
}

// close namespace
}

// int main(){
//     std::vector<int> al = {4,9,5};
//     array_easy::printVector(al, -1);
//     array_easy::rotate(al, 2);
//     array_easy::printVector(al, -1);
//     std::cout<<"Contains duplicate : "<<array_easy::containsDuplicate(al)<<"\n";

//     //find the only number that appears once
//     std::cout <<"The number that only appears once = "<<array_easy::singleNumber(al)<<"\n";

//     //find intersection of arrays
//     std::vector<int> al2 = {9,4,9,8,4};
//     array_easy::printVector(al2, -1);
//     std::cout<<"Intersecting elements = ";
//     array_easy::printVector(array_easy::intersect(al, al2), -1);

//     //plus one
//     al = {9,9,9};
//     std::cout<<"plus one digits of ";
//     array_easy::printVector(al, -1);
//     std::cout<<"= ";
//     array_easy::printVector(array_easy::plusOne(al), -1);

//     //move zeroes
//     al = {0,1,0,3,12,0};
//     std::cout<<"move zeroes of ";
//     array_easy::printVector(al, -1);
//     std::cout<<"= ";
//     array_easy::moveZeroes(al);
//     array_easy::printVector(al, -1);
// }