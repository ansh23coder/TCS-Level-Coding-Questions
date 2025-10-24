// https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

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

