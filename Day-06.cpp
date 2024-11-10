// Imagine you have a line of people standing one behind the other, facing a specific direction. Now, you want to make the person in the front go to the end of the line, the second person move just before them, and so on, essentially flipping the order of the line.

// Given an array arr[], your task is to reverse the order of elements so that the first element becomes the last, the second element becomes the second-to-last, and so forth.

// Examples:
// Input: arr[] = {1, 4, 3, 2, 6, 5}
// Output: {5, 6, 2, 3, 4, 1}
// Explanation: The first element, 1, moves to the last position, the second element, 4, becomes second-last, and so on.

// Input: arr[] = {4, 5, 1, 2}
// Output: {2, 1, 5, 4}
// Explanation: The first element, 4, moves to the last position, the second element, 5, moves to second-last, etc.



#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; ++i) {
        swap(arr[i], arr[n - i - 1]);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr);

    reverseArray(arr);

    cout << "Reversed array: ";
    printArray(arr);

    return 0;
}
