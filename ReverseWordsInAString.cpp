#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Trim leading and trailing whitespace
        auto start = s.find_first_not_of(" \t");
        auto end = s.find_last_not_of(" \t");
        if (start == string::npos) return ""; // All whitespace
        s = s.substr(start, end - start + 1);
        
        // Step 2: Split into words (handling multiple spaces)
        vector<string> words;
        istringstream iss(s);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        
        // Step 3: Reverse the words
        reverse(words.begin(), words.end());
        
        // Step 4: Join with single spaces
        string result;
        for (int i = 0; i < words.size(); i++) {
            if (i != 0) result += " ";
            result += words[i];
        }
        
        return result;
    }
};