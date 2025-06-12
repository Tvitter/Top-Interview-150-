class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++)
            nums1[i + m] = nums2[i];
        sort(nums1.begin(),nums1.end());
    }
};

//First, it iterates through each element of nums2 (from index 0 to n-1). In each iteration, it takes an element from nums2 and places it into nums1 starting from the index m. This effectively appends all the elements of nums2 to the end of the valid elements in nums1.

//After all elements from nums2 have been copied into nums1, the nums1 array now contains all the original m elements followed by all n elements from nums2, but they are not necessarily sorted yet.

//Finally, the sort function is called on nums1. This sorts the entire nums1 array, arranging all the combined elements in ascending order.
