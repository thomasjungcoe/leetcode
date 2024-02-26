from typing import List

# O(logn) solution using binary search (already sorted so it's not NlogN)
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)-1

        while l <= r:
            mid = (l+r)//2
            if nums[mid] == target:
                return mid
            if target > nums[mid]:
                l = mid+1
            if target < nums[mid]:
                r = mid-1
        return l

s = Solution()
print(s.searchInsert([1,3,5,6], 5))
print(s.searchInsert([1,3,5,6], 2))
print(s.searchInsert([1,3,5,6], 7))