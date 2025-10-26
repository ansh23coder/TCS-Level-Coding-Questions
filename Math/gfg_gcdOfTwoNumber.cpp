// https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1

#include<iostream>
using namespace std;

class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        if (b == 0) {
            return a;
        } 
        else {
            return gcd(b, a % b);
        }
    }
};
int main(){
    int a, b;
    cin >> a >> b;
    Solution obj;
    cout << obj.gcd(a, b);
    return 0;
}
/*
Output:
4 2
= 2

8 5
= 1

5 15
= 5
*/