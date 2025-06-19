class Solution {
public:
    void rotate(vector<int>& nums, int k) {
           k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
/*Adjust k to avoid unnecessary full rotations:

If k is larger than the array size, rotating by k is the same as rotating by k % nums.size().

Example: If nums = [1, 2, 3] and k = 4, then 4 % 3 = 1, so we only rotate once.

Reverse the entire array:

This brings the last k elements to the front but in reverse order.

Example: nums = [1, 2, 3, 4, 5], k = 2

After full reverse: [5, 4, 3, 2, 1]

Reverse the first k elements:

This corrects the order of the first k elements.

Continuing the example:

Reverse first 2 elements: [4, 5, 3, 2, 1]

Reverse the remaining n - k elements:

This corrects the order of the remaining elements.

Final step:

Reverse last 3 elements: [4, 5, 1, 2, 3]

Final rotated array: [4, 5, 1, 2, 3] (rotated right by 2 steps)

*/