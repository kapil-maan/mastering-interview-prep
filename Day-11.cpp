// Imagine you're developing a system that helps people check if phrases, book titles, or any sequence of text are "mirrored," or palindromic—meaning they read the same forwards and backwards. This can be handy for apps that play with words or create patterns in text.

// Here's the challenge: Write a function that determines if a given phrase is a palindrome. This function should:

// Ignore all spaces, punctuation, and special characters.
// Treat uppercase and lowercase letters the same.
// So, if given any phrase, the function should return true if it's a palindrome and false otherwise.

// Example Scenarios:
// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true
// Explanation: If we remove spaces, punctuation, and convert everything to lowercase, the string becomes "amanaplanacanalpanama," which is the same forwards and backwards.
// Example 2:

// Input: "race a car"
// Output: false
// Explanation: After processing, the string becomes "raceacar," which is not the same forwards and backwards.




#include <iostream>
#include <string>
#include <cctype> // For isalnum and tolower
using namespace std;

// Function to check if a given phrase is a palindrome
bool isPalindrome(string s) {
    // Remove non-alphanumeric characters and convert to lowercase
    string filtered = "";
    for (char c : s) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }

    // Check if the filtered string is a palindrome
    int left = 0;
    int right = filtered.size() - 1;
    while (left < right) {
        if (filtered[left] != filtered[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a phrase: ";
    getline(cin, s);

    bool result = isPalindrome(s);

    if (result) {
        cout << "The input string is a palindrome." << endl;
    } else {
        cout << "The input string is not a palindrome." << endl;
    }

    return 0;
}
