// https://www.geeksforgeeks.org/problems/perfect-numbers3207/1
// https://leetcode.com/problems/perfect-number/description/

#include <iostream>
using namespace std;

// Function to check if the number is perfect
bool isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int main() {
    int n = 15;
    cout << (isPerfect(n) ?"true" : "false");
    return 0;
}

/*
// more optimized:
class Solution {
  public:
    bool isPerfect(int n) {
        if (n == 1) return false;
        
        int sum = 1;
        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0) {
                sum += i;
                if(i != n/i){
                    sum += n/i;
                }
            }
        }
        return sum == n;
    }
};
*/