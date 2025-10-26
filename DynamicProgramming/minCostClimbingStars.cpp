// https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1
// https://leetcode.com/problems/min-cost-climbing-stairs/

/*
class Solution {
  public:
    int mincost(vector<int>& cost, int i){
        if(i >= cost.size()) 
            return 0; // reached at top
        return cost[i] + min(mincost(cost, i+1), mincost(cost, i+2));
    } 
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        return min(mincost(cost, 0), mincost(cost, 1));
    }
};
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mincost(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size()) 
            return 0; // reached the top
        if (dp[i] != -1) 
            return dp[i];
        return dp[i] = cost[i] + min(mincost(cost, i + 1, dp), mincost(cost, i + 2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(mincost(cost, 0, dp), mincost(cost, 1, dp));
    }
};
int main() {
    Solution sol;
    // Example input
    vector<int> cost = {10, 15, 20};
    // Output result
    cout << "Minimum Cost to Climb Stairs: " << sol.minCostClimbingStairs(cost) << endl;
    // You can test with another example
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum Cost to Climb Stairs: " << sol.minCostClimbingStairs(cost2) << endl;
    return 0;
}

// Tabulation method: 
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
}; 
// TC: O(n)