// Imagine you are managing a playlist for a music event, where each song has a distinct duration in minutes. The songs are arranged in a specific order according to their original duration, but due to a technical glitch, the playlist got rotated at an unknown point. Now, to adjust the event timing, you need to see if there are two songs in the playlist whose durations together match a specific target time.

// For example:

// You have a playlist with song durations as [11, 15, 6, 8, 9, 10] minutes, and you want to find out if there are any two songs that add up to 16 minutes. Here, you would find that the songs with durations 6 and 10 add up to 16, so it's possible to meet your timing goal.
// In another case, your playlist has song durations [11, 15, 26, 38, 9, 10], and the target duration is 35 minutes. Here, the songs with durations 26 and 9 add up to 35, so you can meet this timing.
// But if your target duration were 45 minutes with the same playlist [11, 15, 26, 38, 9, 10], there would be no pair of songs adding up to 45, meaning you'd need to reconsider your target.
// Input :- First line of input contains T - number of test cases.
// Each test case contains n size of playlist and target integer.
// In next line given array.
// Output: Print Yes if sum of the duration of two song is equal to target otherwise No.


#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void findPairs(const vector<int>& playlist, int target) {
    unordered_set<int> seen;
    for (int duration : playlist) {
        int complement = target - duration;
        if (seen.find(complement) != seen.end()) {
            cout << "Yes" << endl;
            return;
        }
        seen.insert(duration);
    }
    cout << "No" << endl;
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while (T--) {
        int n, target;
        cout << "Enter the size of the playlist: ";
        cin >> n;
        cout << "Enter the target duration: ";
        cin >> target;

        vector<int> playlist(n);
        cout << "Enter the durations of the songs: ";
        for (int i = 0; i < n; ++i) {
            cin >> playlist[i];
        }

        findPairs(playlist, target);
    }

    return 0;
}
