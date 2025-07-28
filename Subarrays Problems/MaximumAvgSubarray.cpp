#include <bits/stdc++.h>
#include<math.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;

        // Step 1: Get sum of the first 'k' elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;  // Step 2: Initialize maxSum with the first window

        int startIndex = 0;
        int endIndex = k;

        // Step 3: Slide the window
        while (endIndex < nums.size()) {
            sum -= nums[startIndex];   // remove element leaving the window
            sum += nums[endIndex];     // add new element entering the window
            maxSum = max(maxSum, sum); // update max if needed

            startIndex++;
            endIndex++;
        }

        // Step 4: Return the average of the max sum
        return (double) maxSum / k;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int k = 4;

    Solution sol;
    cout << "Maximum Average Subarray is: " << sol.findMaxAverage(nums, k) << endl;

    return 0;
}
