// Imagine you're building a text analysis tool that identifies the longest unique sequence of characters in a document, which could help in detecting varied word patterns or unique phrases within long blocks of text. For instance, if you're analyzing customer feedback or log files, finding long, non-repeating substrings might highlight interesting or diverse phrases used by users.

// Problem Description:
// Write a function that, given a string s, finds the length of the longest substring (a continuous part of the string) that has no repeating characters.

// Example Scenarios:

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The longest substring without repeating characters is "abc", which has a length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The longest substring without repeating characters is "b", with a length of 1, since all characters are the same.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The longest substring without repeating characters is "wke", with a length of 3. Note that "pwke" is not a valid substring as it is not continuous.

// Constraints:
// The length of the string s is between 0 and 50,000 characters.
// The string can include English letters, digits, symbols, and spaces.



#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {
        char currentChar = s[end];

        // If the character is found in the map and is within the current window
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
            // Move the start to the next position of the last occurrence of currentChar
            start = charIndexMap[currentChar] + 1;
        }

        // Update the last occurrence of currentChar
        charIndexMap[currentChar] = end;

        // Calculate the maximum length of the current window
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);

    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}
