#!/usr/bin/env python
from typing import List

def intersect(nums1, nums2):
    smallMap = {}
    bigMap = {}
    result = []
    bigList = nums2
    smallList = nums1
    if len(nums1) > len(nums2):
        bigList = nums1
        smallList = nums2
    for i, e in enumerate(bigList):
        if i<len(smallList) and e== smallList[i]:
            result.append(e)
            continue
        if e in smallMap:
            if smallMap[e] > 1:
                smallMap[e] -= 1
            else:
                del smallMap[e]
            result.append(e)
        elif e in bigMap:
            bigMap[e] += 1
        else:
            bigMap[e] = 1
        
        if i+1 > len(smallList):
            continue
        
        if smallList[i] in bigMap:
            if bigMap[ smallList[i] ] > 1:
                bigMap[ smallList[i] ] -= 1
            else:
                del bigMap[ smallList[i] ]
            result.append(smallList[i])
        elif smallList[i] in smallMap:
            smallMap[ smallList[i] ] += 1
        else:
            smallMap[ smallList[i] ] = 1
    return result

#""""""""""""""""""""""""""""""""""""

# MEDIUM

#""""""""""""""""""""""""""""""""""""

def threeSum(nums: List[int]) -> List[List[int]]:
    result = []
    nums = sorted(nums)
    for i in range(len(nums)-2):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        j = i + 1
        k = len(nums) - 1
        while j < k:
            _sum = nums[i] + nums[j] + nums[k]
            if _sum == 0: 
                result.append([nums[i], nums[j], nums[k]])
            if _sum < 0:
                j += 1
                while j < k and nums[j] == nums[j-1]: j += 1
            else:
                k-=1
                while k > i and nums[k] == nums[k+1]: k -= 1
    return result


def lengthOfLongestSubstring(s: str) -> int:
    if not s:
        return 0
    table = {}
    result = 0
    start = 0
    for end, char in enumerate(s):
        r = table.get(char, None)
        if r is not None:
            if r+1 > start:
                start = r+1
        table[char] = end
        result = max(result, end-start+1)
    return result

def longestPalindrome(s: str) -> str:
    if not s:
        return ""
    result = ""
    def temp(s, start, end):
        st = start
        en = end
        while st>-1 and en < len(s) and s[st] == s[en]:
            st -= 1
            en += 1
        if start == st and end == en:
            return ""
        return s[st+1:en]

    for i in range(len(s)):
        sub1 = temp(s, i, i)
        sub2 = temp(s, i, i+1)
        sub = sub1 if len(sub1) > len(sub2) else sub2
        result = sub if len(sub) > len(result) else result
    return result

def increasingTriplet(nums):
    first = second = float('inf')
    for n in nums:
        if n <= first:
            first = n
        elif n <= second:
            second = n
        else:
            return True
    return False

if __name__ == "__main__":
    # l1 = [4,9,5,4]
    # l2 = [9,4,9,8,4]
    # print(intersect(l1, l2))
    print(threeSum([0,0,0,0,0,0,0,0]))
    # print(longestPalindrome("cbbd"))
    # print(increasingTriplet([2, 7, 3, 0, 1, 1, 3]))
