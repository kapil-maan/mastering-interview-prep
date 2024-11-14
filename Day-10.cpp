// Imagine you work for a financial analysis firm, where you help clients manage their investments by balancing their portfolios. One of your clients wants to ensure their portfolio balances out to a "neutral" net exposure, meaning the sum of three selected investment positions should total zero. The positions could represent various assets, where each position's value is a gain or loss.

// To help the client, you want to identify all possible combinations of three investment positions that, when added together, balance out to zero—meaning no net gain or loss.

// For example:

// Suppose the portfolio positions are represented by [-1, 0, 1, 2, -1, -4]. Here, there are two unique sets of three positions that balance out to zero:
// [-1, -1, 2] and [-1, 0, 1]
// These combinations suggest that by holding these positions together, the client’s net gain or loss is zero.
// In a different portfolio with positions [0, 0, 0], there's only one valid triplet [0, 0, 0] that totals zero, representing a neutral position with no net impact.
// If the portfolio contains positions like [0, 1, 1], there’s no way to balance out to zero with any combination of three positions, indicating the client may need to adjust their portfolio for neutrality.
// By efficiently identifying these "neutralizing triplets" without allowing duplicate sets, you help your client explore the options they have to stabilize or adjust their portfolio according to their financial goals. This approach is particularly useful in portfolio management, where quick, balanced adjustments are needed in response to market changes.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> findTriplets(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Avoid duplicates

        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++; // Avoid duplicates
                while (left < right && nums[right] == nums[right - 1]) right--; // Avoid duplicates
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of positions: ";
    cin >> n;

    vector<int> positions(n);
    cout << "Enter the positions: ";
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    vector<vector<int>> triplets = findTriplets(positions);

    if (triplets.empty()) {
        cout << "No triplets found that sum to zero." << endl;
    } else {
        cout << "Triplets that sum to zero:" << endl;
        for (const auto& triplet : triplets) {
            cout << "(" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << ")" << endl;
        }
    }

    return 0;
}

