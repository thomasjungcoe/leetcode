#include <vector>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    // vertical scanning approach
    // Time: O(N)
    // Space: O(1)
    string longestCommonPrefix1(vector<string>& strs) {
        if (strs.size() == 0 ) return "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }

    // Binary Search Approach
    // Time: O(N)  --> O (N logN)
    // Space: O(1)
    bool isCommonPrefix(vector<string>& strs, int len) {
        string str1 = strs[0].substr(0, len);
        for(int i = 1; i < strs.size(); i++) {
            if(strs[i].rfind(str1, 0) != 0) return false;
        }
        return true;
    }
    string longestCommonPrefix2(vector<string>& strs) {
         if(strs.size() ==0) return "";
         int _min = INT_MAX;
         for(string str : strs) {
            _min = min(_min, (int)str.size());
         }
         int low = 1, high = _min;
         while(low <= high) {
            int middle = (low + high) / 2;
            if(isCommonPrefix(strs, middle)) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
         }
         return strs[0].substr(0, high);
    }
    
    int main() {
        std::vector<string> v = {"flower","flow","flight"};
        std::vector<string> v2 = {"dog","racecar","car"};
        std::cout<<"Longest common prefix of given array : "<< longestCommonPrefix1(v) <<std::endl;
        std::cout<<"Longest common prefix of given array : "<< longestCommonPrefix1(v2) <<std::endl;
        std::cout<<"Longest common prefix of given array : "<< longestCommonPrefix2(v) <<std::endl;
        std::cout<<"Longest common prefix of given array : "<< longestCommonPrefix2(v2) <<std::endl;

        return 0;
    }
};
