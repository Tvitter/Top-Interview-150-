/*Predefined Values and Symbols: Create two arrays, one for the Roman numeral symbols and another for their corresponding integer values. These arrays should be ordered from the largest value to the smallest.

String Construction: Use a loop to iterate through the values. For each value, while the remaining number is greater than or equal to the current value, append the corresponding symbol to the result string and subtract the value from the number.

Result Return: After processing all values, return the constructed Roman numeral string.*/
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string romanNumeral;
        
        int i = 0;
        while (num > 0) {
            if (num >= values[i]) {
                romanNumeral += symbols[i];
                num -= values[i];
            } else {
                i++;
            }
        }
        
        return romanNumeral;
    }
};