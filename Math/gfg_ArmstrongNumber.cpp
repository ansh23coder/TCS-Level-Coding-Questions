// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int original = n;
        int sum = 0;
        
        while(n > 0){
            int digit = n % 10;
            sum += digit * digit * digit;
            n /= 10;
        }
        return sum == original;
    }
};
int main(){
    int n = 153;
    Solution sol;
    cout << sol.armstrongNumber(n);

    return 0;
}