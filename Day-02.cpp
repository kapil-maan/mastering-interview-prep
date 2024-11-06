// Ques 2 . Given an array arr[] of n integers where arr[i] represents the number of chocolates in ith packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:

// Each student gets exactly one packet.
// The difference between the maximum and minimum number of chocolates in the packets given to the students is minimized.

// Sample:-
// Input: arr[] = {7, 3, 2, 4, 9, 12, 56}, m = 3
// Output: 2
// Explanation: If we distribute chocolate packets {3, 2, 4}, we will get the minimum difference, that is 2.

// Input: arr[] = {7, 3, 2, 4, 9, 12, 56}, m = 5
// Output: 7
// Explanation: If we distribute chocolate packets {3, 2, 4, 9, 7}, we will get the minimum difference, that is 9 – 2 = 7.




#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int findMinDifference(int arr[], int n, int m) {
    // If there are no chocolates or students
    if (m == 0 || n == 0)
        return 0;

    // Sort the given packets
    sort(arr, arr + n);

    // Number of students cannot be more than number of packets
    if (n < m)
        return -1;

    // Find the minimum difference
    int min_diff = INT_MAX;

    // Iterate through the array and find the minimum difference
    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

int main() {
    int n, m;
    cout << "Enter the number of packets: ";
    cin >> n;

    int arr[n];
    cout << "Enter the number of chocolates in each packet: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number of students: ";
    cin >> m;

    int result = findMinDifference(arr, n, m);
    if (result == -1)
        cout << "Number of students is more than the number of packets." << endl;
    else
        cout << "The minimum difference is: " << result << endl;

    return 0;
}
