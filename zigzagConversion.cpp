#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // If only one row, return the string as-is
        if (numRows == 1) return s;

        // Create a vector of strings for each row
        vector<string> rows(min(numRows, int(s.size())));

        int currentRow = 0;
        bool goingDown = false;

        // Distribute characters to appropriate rows
        for (char c : s) {
            rows[currentRow] += c;
            // Change direction when reaching top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into result string
        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};