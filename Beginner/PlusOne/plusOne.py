from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num_digits = len(digits)

        for i in range(num_digits -1, -1, -1):
            digits[i] += 1

            digits[i] %= 10

            if digits[i] != 0:
                return digits
        return [1] + digits

s = Solution()
print(s.plusOne([1,2,3])) # [1,2,4]
print(s.plusOne([9])) # [1,0]
print(s.plusOne([9,9])) # [1,0]
print(s.plusOne([9,8]))
