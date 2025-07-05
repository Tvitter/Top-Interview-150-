#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int totalTank = 0;    // Tracks total gas - total cost for entire circuit
        int currentTank = 0;  // Tracks gas - cost for current segment
        int startStation = 0; // Potential starting station index
        
        for (int i = 0; i < gas.size(); i++) {
            int netGain = gas[i] - cost[i];
            totalTank += netGain;
            currentTank += netGain;
            
            // If we can't reach next station from current start
            if (currentTank < 0) {
                // Reset starting station to next position
                startStation = i + 1;
                currentTank = 0;
            }
        }
        
        // Only possible if total gas >= total cost
        return totalTank >= 0 ? startStation : -1;
    }
};
/*Variables:

totalTank: Accumulates the total gas minus total cost for the entire circuit

currentTank: Tracks the gas balance for the current segment being evaluated

startStation: Stores the potential starting position that might complete the circuit

Algorithm Logic:

For each station, calculate the net gas gain (gas[i] - cost[i])

Update both totalTank and currentTank with this net gain

If currentTank becomes negative, reset the starting station to the next position

After processing all stations, check if totalTank is non-negative (circuit possible)

Why It Works:

The solution leverages the fact that if total gas >= total cost, a solution exists

By tracking where we run out of gas (currentTank < 0), we can identify potential starting points

The last valid starting point found will be able to complete the circuit

Complexity Analysis:

Time Complexity: O(n) - Single pass through the stations

Space Complexity: O(1) - Constant space used regardless of input size

Edge Cases Handled:

Returns -1 if total gas is insufficient (totalTank < 0)

Handles the case where the circuit must start at station 0

Correctly identifies when no solution exists

This implementation efficiently solves the gas station problem using a greedy approach that finds the optimal starting point in linear time.*/