class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
           int index = 0;
        for (int num : nums) {
            if (num != val) {
                nums[index++] = num;
            }
        }
        return index;
    
    }
};

/*Two-pointer approach: Uses an index variable that starts at 0 to track where to place the next "good" element
Loop through each number: Goes through every number in the original array one by one
Keep or skip:

If the current number is NOT equal to the target value (num != val), it keeps it by copying it to position index and then moves index forward
If the current number IS equal to the target value, it just skips it (doesn't copy it anywhere)


Return the count: At the end, index represents how many elements were kept, so it returns that number

Example:
If you have array [3, 2, 2, 3] and want to remove 3:

Start with index = 0
See 3 → skip it
See 2 → copy to position 0, index becomes 1
See 2 → copy to position 1, index becomes 2
See 3 → skip it
Return 2 (meaning 2 elements left)
Array becomes [2, 2, ?, ?] (the last two spots don't matter)*/