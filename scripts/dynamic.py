from typing import List

def climbStairs(n: int) -> int:
    # https://www.youtube.com/watch?v=NFJ3m9a1oJQ
    if n < 2:
        return 1
    result = 1
    prv_result = 1
    for i in range(2, n+1):
        r = result+prv_result
        prv_result = result
        result = r
    return result

def maxProfit(prices: List[int]) -> int:
    profit = 0
    bought = float('inf')
    for i in range(len(prices)):
        if bought < prices[i]:
            profit += prices[i] - bought
        bought = prices[i]
    return profit

def maxProfitOneTx(prices: List[int]) -> int:
    profit = 0
    bought = float('inf')
    for i in range(len(prices)):
        if prices[i] < bought:
            bought = prices[i]
        elif profit < prices[i] - bought:
            profit = prices[i] - bought
    return profit

def maxSubArray(nums: List[int]) -> int:
    if not nums:
        return 0
    result = nums[0]
    _sum = nums[0]
    for i in range(1, len(nums)):
        _sum = max( nums[i] + _sum, nums[i])
        result = max(_sum, result)
    return result
    # better solution
    # for i in range(1, len(nums)):
    #     if nums[i] + nums[i-1] > nums[i]:
    #         nums[i] = nums[i] + nums[i-1]

def rob(nums: List[int]) -> int:
    # https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/576/

    if not nums:
        return 0
    elif len(nums) < 3:
        return max(nums)
    nums[1] = max(nums[0], nums[1])
    for i in range(2, len(nums)):
        nums[i] = max(nums[i]+nums[i-2], nums[i-1])
    return nums[-1]

    # [n_2, n_1, n, n+1, n+2, ...]
    # n_2 = n_1 = 0
    # for n in nums:
    #     temp = max(n+n_2, n_1)
    #     n_2 = n_1
    #     n_1 = temp
    # return n_1

if __name__ == "__main__":
    # print(climbStairs(6))
    # print(maxProfit([7,1,5,3,6,4]))
    # print(maxProfitOneTx([7,1,5,3,6,4]))
    # print(maxProfitOneTx([1,2]))
    # print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
    print(rob([2,1,1,2]))
    print(rob([1,3,1,3,100]))
    print(rob([2,7,9,3,1]))