// Imagine you're organizing a running event where participants' completion times (in minutes) are recorded. To give recognition to the top performers, you want to find the k-th fastest runner. However, with a large number of participants, you don't want to sort the entire list, just find the specific position you're interested in—say the 3rd or 4th fastest time.

// For example:

// You have a list of times [7, 10, 4, 3, 20, 15] in minutes, and you want to find the 3rd fastest time. Here, the 3rd fastest time is 7 minutes, indicating the runner who completed the race in 7 minutes stands in 3rd position among the quickest.
// In another scenario, the list of times is [2, 3, 1, 20, 15], and you want the 4th fastest time. Here, the 4th fastest time is 15 minutes.
// Finding the k-th smallest time without fully sorting the list allows for efficient processing, especially when dealing with a large number of runners. This approach helps you quickly determine rankings or specific positions in a list of unordered data, making it practical for real-time event tracking or leaderboards.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

// Function to perform the Quickselect
int quickselect(vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = partition(arr, left, right);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickselect(arr, left, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, right, k);
    }
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while (T--) {
        int n, k;
        cout << "Enter the size of the playlist: ";
        cin >> n;
        cout << "Enter the position of the fastest time (k): ";
        cin >> k;

        vector<int> times(n);
        cout << "Enter the completion times of the runners: ";
        for (int i = 0; i < n; ++i) {
            cin >> times[i];
        }

        // Adjust k to be zero-based index
        int result = quickselect(times, 0, n - 1, k - 1);

        cout << "The " << k << "th fastest time is: " << result << " minutes" << endl;
    }

    return 0;
}
