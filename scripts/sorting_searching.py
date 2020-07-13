from typing import List, Union
import math

def merge(nums1: List[int], m: int, nums2: List[int], n: int) -> None:
    if not nums2:
        return nums1
    nums1[m:] = nums2

    for i in range(m, m+n):
        j = i
        while j > 0:
            if nums1[j] < nums1[j-1]:
                t = nums1[j-1]
                nums1[j-1] = nums1[j]
                nums1[j] = t
                j -= 1
            else:
                break
    return nums1

 def firstBadVersion(nums:List[int], n:int) -> int:
     def temp(start, end):
        mid = math.floor((end - start)/2)
        if mid == n:
            return mid
        elif mid > n:
            pass


if __name__ == "__main__":
    print(merge([1,2,3,0,0,0], 3, [2,5,6], 3))