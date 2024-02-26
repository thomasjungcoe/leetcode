function SearchInsertPosition(nums, target) {
    var left = 0;
    var right = nums.length - 1;
    while (left <= right) {
        var mid = Math.floor((left + right) / 2);
        if (target === nums[mid]) {
            return mid;
        }
        else if (target > nums[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}
