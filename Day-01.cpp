// Ques 1 : Given an array of size N. The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.

// Sample:-
// Input: arr[] = {3, 5, 4, 1, 9}
// Output: Minimum element is: 1
// Maximum element is: 9

// Input: arr[] = {22, 14, 8, 17, 35, 3}
// Output: Minimum element is: 3
// Maximum element is: 35.
// Take all the input from user.
// Write all the posible solutions.


#include <iostream>
#include <limits.h>
using namespace std;

void findMinAndMax(int arr[], int n) {
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Minimum element is: " << min << endl;
    cout << "Maximum element is: " << max << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    findMinAndMax(arr, n);
    return 0;
}
