from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l = 1

        if len(nums) == 0:
            return 0
        
        for r in range(1, len(nums)):
            if nums[r] != nums[r-1]:
                nums[l] = nums[r]
                l += 1
        return l 


s = Solution()
print("The new list is: ", s.removeDuplicates([1, 1, 2]))
print("The new list is: ", s.removeDuplicates([0,0,1,1,1,2,2,3,3,4]))