// https://www.geeksforgeeks.org/problems/number-of-paths0926/1
// https://leetcode.com/problems/unique-paths/description/

/*
class Solution {
  public:
    int paths(int m, int n, vector<int>& dp) {
        // Code Here
        if(m==1 && n==1) return 1;
        if(m==0 || n==0) return 0;
        int rightways = paths(m, n-1, dp);
        int downways = paths(m-1, n, dp);
        return rightways + downways;
    }
    int numberOfPaths(int m, int n) {
        return paths(m, n, dp);
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int paths(int m, int n) {
        // Base cases
        if (m == 1 && n == 1) return 1;
        if (m == 0 || n == 0) return 0;

        // Memoization check
        if (dp[m][n] != -1) return dp[m][n];

        // Recursive calls
        int rightWays = paths(m, n-1);
        int downWays = paths(m-1, n);

        // Store in dp table
        return dp[m][n] = rightWays + downWays;
    }
    int numberOfPaths(int m, int n) {
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return paths(m, n);
    }
};
int main() {
    int t;
    cin >> t; // number of test cases
    while (t--) {
        int m, n;
        cin >> m >> n;
        Solution ob;
        cout << ob.numberOfPaths(m, n) << endl;
    }
    return 0;
}

// Tabulation method:
class Solution {
public:
    int numberOfPaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1)); // initialize with 1 for first row/col
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};