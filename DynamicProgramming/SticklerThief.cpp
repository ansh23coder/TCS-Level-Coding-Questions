// https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1
// https://leetcode.com/problems/house-robber/

// Memoization method:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxloot(vector<int>& arr, vector<int>& dp, int idx) {
        if (idx >= arr.size()) 
            return 0;

        if (dp[idx] != -1) 
            return dp[idx];

        int steal = arr[idx] + maxloot(arr, dp, idx + 2);
        int skip = maxloot(arr, dp, idx + 1);

        return dp[idx] = max(steal, skip);
    }

    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return maxloot(arr, dp, 0);
    }
};

int main() {
    Solution s;
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout << s.findMaxSum(arr) << endl;  // Output: 110
    return 0;
}

// Tabulation method:
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;         // No houses
        if (n == 1) return nums[0];   // Only one house

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
