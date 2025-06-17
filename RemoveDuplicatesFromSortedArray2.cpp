class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        int uniqueCount = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[uniqueCount - 2]) {
                nums[uniqueCount] = nums[i];
                uniqueCount++;
            }
        }
        return uniqueCount;
    }
};
/* Initial Check: If the array has 2 or fewer elements, it's already valid (since you can't have more than 2 duplicates in such a small array), so the function just returns the array size as-is.

Tracking Unique Elements: The code uses a pointer uniqueCount (starting at 2) to keep track of where the next valid element should be placed in the array. This pointer represents the length of the "cleaned" array with at most two duplicates.

Loop Through Array: Starting from the third element (index 2), the code checks if the current element is different from the element two positions before uniqueCount. If they are different, it means this is a new valid element (not a third duplicate), so it gets copied to the uniqueCount position, and uniqueCount is incremented.

Result: After processing all elements, uniqueCount holds the length of the modified array where no element appears more than twice. The original array is modified in-place to contain this result.*/
