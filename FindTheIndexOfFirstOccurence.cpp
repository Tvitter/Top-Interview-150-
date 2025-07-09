#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.size();
        int nLen = needle.size();

        // If needle is empty, return 0
        if (nLen == 0) {
            return 0;
        }

        // Loop through haystack and check substrings
        for (int i = 0; i <= hLen - nLen; i++) {
            // Check if substring matches the needle
            bool match = true;
            for (int j = 0; j < nLen; j++) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }

        // If no match is found, return -1
        return -1;
    }
};