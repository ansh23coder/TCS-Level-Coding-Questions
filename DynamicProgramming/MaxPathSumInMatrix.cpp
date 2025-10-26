// https://www.geeksforgeeks.org/problems/path-in-matrix3805/1
// https://leetcode.com/problems/maximum-matrix-sum/description/

/*
class Solution {
public:
    int path(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        // base case
        if (r == n || c < 0 || c == m) return INT_MIN;
        if (r == n - 1) return mat[r][c];
        
        int left = path(mat, r + 1, c - 1);
        int down = path(mat, r + 1, c);
        int right = path(mat, r + 1, c + 1);
        
        return mat[r][c] + max(left, max(down, right));
    }

    int maximumPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = INT_MIN;
        for (int j = 0; j < m; j++) {
            ans = max(ans, path(mat, 0, j));
        }
        return ans;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;  // DP table for memoization

    int path(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();

        // base cases
        if (r == n || c < 0 || c == m) return INT_MIN; // out of bounds
        if (r == n - 1) return mat[r][c];              // bottom row

        // check memo
        if (dp[r][c] != INT_MIN) return dp[r][c];

        int left = path(mat, r + 1, c - 1);
        int down = path(mat, r + 1, c);
        int right = path(mat, r + 1, c + 1);

        return dp[r][c] = mat[r][c] + max({left, down, right});
    }

    int maximumPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        dp.assign(n, vector<int>(m, INT_MIN));  // initialize DP table

        int ans = INT_MIN;
        for (int j = 0; j < m; j++) {
            ans = max(ans, path(mat, 0, j));
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // number of test cases
    while (t--) {
        int n;
        cin >> n;  // matrix size (n x n)
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.maximumPath(mat) << "\n";
    }
    return 0;
}

// Tabulation method:
