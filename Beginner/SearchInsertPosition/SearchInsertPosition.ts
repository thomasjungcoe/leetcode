function SearchInsertPosition(nums: number[], target: number): number {
    let left = 0;
    let right = nums.length - 1;

    while (left <= right) {
        const mid: number = Math.floor((left + right)/2);
        if (target === nums[mid]) {
            return mid;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}