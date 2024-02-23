#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }    
};

int main () {
    Solution s;
    std::vector<int> nums = {3, 2, 2, 3};
    std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 3;
    int result = s.removeElement(nums, val);
    int result2 = s.removeElement(nums2, val);
    std::cout << result << std::endl;
    std::cout << result2 << std::endl;

    return 0;
}