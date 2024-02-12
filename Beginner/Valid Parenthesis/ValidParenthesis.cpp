// Using string
// T: O(n) 
// S: O(1) 

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(std::string s) {
        int i = -1;
        for (auto& ch: s) {
            if (ch == '(' || ch == '{' || ch == '[')
                s[++i] = ch;
            else {
                if (i>=0 && (ch==')' && s[i]=='(' || ch=='}' && s[i]=='{' || ch==']' && s[i]=='['))
                    i--;
                else
                    return false;
            }
        }
        return i==-1;
    }

};

int main() {
    Solution s;
    std::string expr = "{()}[]";

    if (s.isValid(expr))
        std::cout << "Valid";
    else
        std::cout << "Invalid";

    return 0;
}