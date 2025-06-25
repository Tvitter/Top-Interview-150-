class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
        vector<int> ans(n);
        ans[0]=1;
        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]*=right;
            right*=nums[i];
        }
        return ans;
    }
};
/*Step 1: Compute Left Products
ans[0] = 1 (no elements to the left of nums[0]).

For each next element (i = 1 to n-1):

ans[i] = ans[i-1] * nums[i-1]

This stores the product of all left elements for each position.

Example (Left Pass):

ans[0] = 1

ans[1] = ans[0] × nums[0] = 1 × 1 = 1

ans[2] = ans[1] × nums[1] = 1 × 2 = 2

ans[3] = ans[2] × nums[2] = 2 × 3 = 6

After Left Pass: ans = [1, 1, 2, 6]

Step 2: Compute Right Products & Final Answer
Initialize right = 1 (no elements to the right of nums[n-1]).

Traverse from right to left (i = n-1 to 0):

Multiply ans[i] with right (this gives left × right).

Update right = right * nums[i] (accumulating right products).

Example (Right Pass):

i = 3:

ans[3] = 6 × 1 = 6

right = 1 × 4 = 4

i = 2:

ans[2] = 2 × 4 = 8

right = 4 × 3 = 12

i = 1:

ans[1] = 1 × 12 = 12

right = 12 × 2 = 24

i = 0:

ans[0] = 1 × 24 = 24

right = 24 × 1 = 24

Final Answer: [24, 12, 8, 6]*/