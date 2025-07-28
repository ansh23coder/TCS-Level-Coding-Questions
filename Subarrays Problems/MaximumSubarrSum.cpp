// USING KADANE'S ALGORITHMS
#include<iostream>
#include<vector>
using namespace std;

int maximumSubarr(vector<int> nums){
    int sum = 0;
    int maxi = nums[0];

    for(int i=0; i<nums.size(); i++){
    // kadane's approach------
        sum += nums[i];
        maxi = max(maxi, sum);
        if(sum < 0) sum = 0;
    // -----------------------
    }
    return maxi;
};

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum is: " << maximumSubarr(nums);
    return 0;
}
// Maximum Subarray Sum is: 6
