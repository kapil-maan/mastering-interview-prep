// Imagine you're developing a search engine or autocomplete feature that needs to find common patterns in users' search queries or typed phrases. To help refine search suggestions, you want a function that finds the longest common prefix among a list of strings. This prefix could hint at shared topics or categories that might help anticipate the user's needs.

// Problem Description:
// Write a function that accepts an array of strings and returns the longest prefix that all the strings have in common. If there's no common prefix, it should return an empty string ("").

// Example Scenarios:
// Example 1:

// Input: strs = ["flower", "flow", "flight"]
// Output: "fl"
// Explanation: The strings share the prefix "fl", which is the longest common starting sequence.
// Example 2:

// Input: strs = ["dog", "racecar", "car"]
// Output: ""
// Explanation: The strings have no letters in common at the beginning, so the result is an empty string.
// Constraints:
// The number of strings in strs is between 1 and 200.
// Each string has a length between 0 and 200 characters.
// All strings consist only of lowercase English letters.



#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0]; // Start with the first string as the prefix
    for (int i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings: ";
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);

    if (result.empty()) {
        cout << "There is no common prefix." << endl;
    } else {
        cout << "The longest common prefix is: " << result << endl;
    }

    return 0;
}
