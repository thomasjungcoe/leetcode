#include <iostream>
#include <string>

using namespace std;

class Solution {
    public: 
        int lengthOfLastWord(std::string s) {
            int end = s.size() - 1;
            
            while (end >= 0 && s[end] == ' ') {
                end--;
            }

            if (end < 0) {
                return 0;
            }

            int newEnd = end;
            while(newEnd >= 0 && s[newEnd] != ' ') {
                newEnd--;
            }

            return end - newEnd;

        }
};

int main() {
    Solution sol = Solution();  
    std::cout << sol.lengthOfLastWord("Hello World") << std::endl;
    return 0;
}
