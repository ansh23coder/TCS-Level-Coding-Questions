// https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

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
