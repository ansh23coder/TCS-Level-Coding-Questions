// https://leetcode.com/problems/remove-element/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0; // Position to insert the next non-val element
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[index++] = nums[i];
            }
        }
        
        return index; // The new size of the array after removing `val`
    }
};
// Logic: Just replace with that non-equal value, when condition of value will not match

int main(){
    vector<int>nums = {3, 2, 2, 3};
    int value = 3;
    
    Solution sol;  // Create an instance of the Solution class
    int newSize = sol.removeElement(nums, value);  // Call the removeElement function
    
    // Output the result to check the new array size
    cout << "New size: " << newSize << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
