// Ques 4. You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.



#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        // Update minPrice if the current price is lower
        if (price < minPrice) {
            minPrice = price;
        }
        // Calculate profit if selling at the current price
        int profit = price - minPrice;
        // Update maxProfit if the calculated profit is higher
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }
    return maxProfit;
}

int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices for each day: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = maxProfit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}
