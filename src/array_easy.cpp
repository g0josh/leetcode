#include <iostream>
#include <vector>

namespace array_easy{

template <typename T>
void printVector(const std::vector<T>& V, int upto){
    (upto < 0)?upto = V.size():upto = upto;
    std::cout<<"[ ";
    for (int i = 0; i<upto; i++){
        std::cout<<V[i]<<" ";
    }
    std::cout<<"]"<<std::endl;
}

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

// close namespace
}

int main(){
    std::vector<int> al = {1,2,3,4,5,6};
    array_easy::printVector(al, -1);
    array_easy::rotate(al, 2);
    array_easy::printVector(al, -1);
}