// Imagine you're a hiker walking along a mountainous path, where each step can either go uphill (positive numbers) or downhill (negative numbers). You want to find the longest stretch of this path where the sum of your upward steps outweighs the downward ones, giving you the best overall elevation gain without stopping midway.

// Given an integer array nums representing the elevation changes, find the segment (subarray) of consecutive steps with the highest total elevation gain and return its value.

// Examples:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The best subarray is [4, -1, 2, 1], giving the maximum gain of 6.

// Input: nums = [1]
// Output: 1
// Explanation: Since there's only one elevation change, the largest sum is simply 1.

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The entire path [5, 4, -1, 7, 8] gives the largest sum, 23.


// Constrains :- 1<= length of given array <= 10000,



#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(const vector<int>& nums) {
    int maxSum = nums[0]; // Initialize maxSum to the first element
    int currentSum = nums[0]; // Initialize currentSum to the first element

    for (int i = 1; i < nums.size(); ++i) {
        currentSum = max(nums[i], currentSum + nums[i]); // Update currentSum
        maxSum = max(maxSum, currentSum); // Update maxSum
    }

    return maxSum;
}

int main() {
    vector<int> nums;
    int n, element;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        nums.push_back(element);
    }
    
    int result = maxSubArray(nums);
    cout << "Maximum elevation gain: " << result << endl;

    return 0;
}
