class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0

        for i in range(len(haystack) + 1 - len(needle)):
            for j in range(len(needle)):
                if haystack[i+j] != needle[j]:
                    break
                if j == len(needle)-1:
                    return i
        return -1

    def strStr2(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i+len(needle)] == needle:
                return i
        return -1

s = Solution()
haystack = "sadbutsad"
needle = "sad"

haystack2 = "leetcode"
needle2 = "leeto"


print(s.strStr(haystack, needle));
print(s.strStr(haystack2, needle2));

print(s.strStr2(haystack, needle));
print(s.strStr2(haystack2, needle2));
