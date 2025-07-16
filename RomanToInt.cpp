#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            int current = romanMap[s[i]];
            if (i + 1 < s.length() && current < romanMap[s[i + 1]]) {
                total -= current;
            } else {
                total += current;
            }
        }
        return total;
    }
};

/*Mapping Roman Numerals: The unordered_map romanMap stores the integer values corresponding to each Roman numeral character.

Initialization: total is initialized to 0 to accumulate the result.

Loop Through String: The loop runs from the first character to the last character of the string.

Current Value: For each character at position i, its value is retrieved from romanMap.

Subtraction Check: If the current character's value is less than the next character's value, subtract the current value from total (handling cases like IV (4), IX (9), etc.).

Addition: Otherwise, add the current value to total.

Return Result: After processing all characters, total holds the converted integer value, which is returned.*/