#include <vector>
#include <iostream>

class Solution {
    public:
        int searchInsert(std::vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size()-1;
            
            while (left <= right) {
                int mid = (left + right) / 2;
                if (target == mid) {
                    return mid;
                } else if (target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid-1;
                }
            }
            return left;
        }
};

int main() {
    Solution s;
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    std::cout << s.searchInsert(nums, target) << std::endl;
    return 0;
}