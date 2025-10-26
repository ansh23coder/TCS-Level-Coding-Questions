// https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1

/*
class Solution {
public:
    int fibo(int n, vector<int>& dp) {
        if (n <= 1) return n;
        return fibo(n - 1) + fibo(n - 2);
    }
    int nthFibonacci(int n) {
        return fibo(n, dp);
    }
};
*/

// Memoization - 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fibo(int n, vector<int>& dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
    }
    int nthFibonacci(int n) {
        vector<int> dp(n + 1, -1);
        return fibo(n, dp);
    }
};
int main() {
    Solution s;
    int n = 5;
    cout << s.nthFibonacci(n) << endl; // Output: 5
    return 0;
}

// Tabulation method DP - 
// 1. giving runtime error
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        vector<int> dp(0, n+1);
        if(n>0) dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// 2.
