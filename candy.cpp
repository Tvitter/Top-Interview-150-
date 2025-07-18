#include <vector>
#include <algorithm> // for std::max and std::fill
#include <numeric>   // for std::accumulate

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        std::vector<int> candies(n, 1); // Step 1: Initialize all with 1 candy

        // Step 2: Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum all candies
        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};
/*Initialization:

We create a candies vector initialized with 1 candy for each child (same as Java's Arrays.fill)

Left to Right Pass:

Compares each child with their left neighbor

If a child has higher rating, they get one more candy than their left neighbor

This ensures the increasing sequence property

Right to Left Pass:

Compares each child with their right neighbor

If a child has higher rating, they get the maximum of:

Their current candy count (from left pass)

One more than their right neighbor

This ensures the decreasing sequence property while preserving left pass results

Summing Candies:

Uses std::accumulate to sum all values in the candies vector

Equivalent to Java's manual summation loop but more concise

Why It Works:

The two-pass approach guarantees both left and right neighborhood constraints

The max operation in the second pass preserves the results from the first pass

This is the most efficient O(n) time solution for this problem

Complexity Analysis:

Time Complexity: O(n) - Three linear passes through the data

Space Complexity: O(n) - Additional array to store candy counts

Edge Cases Handled:

Handles empty input vector

Correctly processes strictly increasing/decreasing ratings

Maintains minimum candy count of 1 for all children

This implementation efficiently solves the candy distribution problem while satisfying all the given constraints. The algorithm follows the same logical flow as the Java version but uses C++ standard library functions for cleaner code.*/