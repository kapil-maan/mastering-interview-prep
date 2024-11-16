// Imagine you’re developing a system to help users check if two words or phrases are rearrangements of each other—useful for games, puzzles, or even detecting potential duplicates in word-based databases. An anagram is when two strings contain the same characters in the same frequency but in a different order.

// For this task, write a function that checks if two given strings are anagrams. If all letters in one string can be rearranged to form the other, the function should return true; otherwise, it should return false.

// Example Scenarios:
// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Explanation: By rearranging the letters of "anagram," we can form "nagaram," so the two strings are anagrams.
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// Explanation: The letters in "rat" cannot be rearranged to form "car" since the two strings do not contain the same characters.
// Constraints:
// Each string will contain only lowercase English letters.
// The lengths of the strings s and t will be between 1 and 50,000 characters.




#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(const string& s, const string& t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, int> charCount;

    // Count characters in the first string
    for (char c : s) {
        charCount[c]++;
    }

    // Decrease count based on characters in the second string
    for (char c : t) {
        charCount[c]--;
        if (charCount[c] < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s, t;
    cout << "Enter the first string: ";
    cin >> s;
    cout << "Enter the second string: ";
    cin >> t;

    if (isAnagram(s, t)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
