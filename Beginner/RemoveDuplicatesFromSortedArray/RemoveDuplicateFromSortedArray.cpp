#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public: 
        int removeDuplicates(std::vector<int>& nums) {
            int l = 0;

            for (const int num: nums) {
                if (l < 1 || num > nums[l - 1])
                    nums[l++] = num;
            }
            return l;
        }
};

int main() {
    Solution s;
    std::vector<int> nums1 = {1, 1, 2};
    std::vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};            
    std::cout << s.removeDuplicates(nums1) << std::endl;
    std::cout << s.removeDuplicates(nums2) << std::endl;

    return 0;
}
