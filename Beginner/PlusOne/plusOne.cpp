#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public: 
        std::vector<int> plusOne(std::vector<int>& digits) {
            for(int i = digits.size() -1; i >= 0; --i) {
                digits[i]++;
                digits[i] %= 10;

                if (digits[i] != 0) {
                    return digits;
                }
            }

            digits.insert(digits.begin(), 1);

            return digits;
        }
};

#include <iostream> // Include the necessary header file

int main() {
    Solution s;
    std::vector<int> digits = {1, 2, 3};
    std::vector<int> result = s.plusOne(digits);
    for (int i = 0; i  < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}