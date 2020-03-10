#!/usr/bin/env python

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

def plusOne(digits):
    

if __name__ == "__main__":
    l1 = [4,9,5,4]
    l2 = [9,4,9,8,4]
    print(intersect(l1, l2))

