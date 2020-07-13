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
        if start <= end:
            mid = start + (end - start)//2
        if nums[mid] and not nums[mid-1] :
            return mid
        elif nums[mid] and nums[mid-1]:
            return temp(start, mid)
        elif not nums[mid] and not nums[mid-1]:
            return temp(mid+1, end)
    return temp(1, n)


if __name__ == "__main__":
    print(firstBadVersion([False, False, False, False, True, True], 5))