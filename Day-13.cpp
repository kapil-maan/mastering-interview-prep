// Imagine you're building a code editor or syntax checker that needs to validate if all brackets in a piece of code are correctly paired and properly nested. This is crucial for ensuring that code blocks open and close as expected, preventing syntax errors and making sure the code can run without issues.

// To achieve this, you need a function that takes a string containing only brackets ('()[]{}') and determines if the brackets are used correctly. For the string to be "valid," it must meet these criteria:

// Each opening bracket ((, {, [) must have a matching closing bracket (), }, ]).
// Brackets must close in the correct order (i.e., nested or sequentially closed).
// Example Scenarios:
// Example 1:

// Input: s = "()"
// Output: true
// Explanation: The single pair of parentheses is correctly opened and closed.
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Explanation: Each type of bracket is correctly opened and closed in sequence.
// Example 3:

// Input: s = "(]"
// Output: false
// Explanation: The brackets are mismatched because a parenthesis was opened but then incorrectly closed with a square bracket.
// Example 4:

// Input: s = "([])"
// Output: true
// Explanation: The brackets are properly nested, with each type of bracket opening and closing correctly.
// Constraints:
// The length of the string s will be between 1 and 10,000 characters.
// The string consists only of the characters ()[]{}.



#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            // Push opening brackets onto the stack
            st.push(c);
        } else {
            // If stack is empty, there's no opening bracket for the closing bracket
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // Check if the top of the stack matches the current closing bracket
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    // If the stack is empty, all brackets are matched properly
    return st.empty();
}

int main() {
    string s;
    cout << "Enter a string containing brackets: ";
    cin >> s;

    bool result = isValid(s);

    if (result) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    return 0;
}
