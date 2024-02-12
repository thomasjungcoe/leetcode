# Using Stack
# T: O(n) 
# S: O(n) for  the stack
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        lookup = {')': '(', '}': '{', ']': '['}

        for p in s:
            if p in lookup.values():
                stack.append(p)
            elif stack and lookup[p] == stack[-1]:
                stack.pop()
            else:
                return False
        return stack == []

s = Solution()
print(f"This is: {s.isValid('()')}")        # True
print(f"This is: {s.isValid('()[]{}')}")    # True
print(f"This is: {s.isValid('(]')}")        # False