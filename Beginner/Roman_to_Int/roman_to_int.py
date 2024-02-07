class Solution:
    def romanToInt(self,  s:str) -> int:
        roman = {
            "I":1,
            "V":5,
            "X":10,
            "L":50,
            "C":100,
            "D":500,
            "M":1000
        }

        N = len(s)
        i = N-1
        output = 0;
        while i >= 0:
            if i < N-1 and roman[s[i]] < roman[s[i+1]]:
                output -= roman[s[i]]
            else:
                output += roman[s[i]]
            i -= 1
        return output

num = input("Please enter the roman numeral: ")
s = Solution()
print(f"The number is: {s.romanToInt(num)}");
