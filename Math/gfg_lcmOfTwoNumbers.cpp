// https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1

#include <iostream>
#include <vector>
#include <algorithm> // for __gcd
using namespace std;

class Solution {
public:
    vector<int> lcmAndGcd(int a, int b) {
        int gcd = __gcd(a, b);           
        // Built-in GCD function
        int lcm = (a / gcd) * b;         
        // LCM formula to avoid overflow
        return {lcm, gcd};
    }
};

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    Solution obj;
    vector<int> result = obj.lcmAndGcd(a, b);

    cout << "LCM: " << result[0] << ", GCD: " << result[1] << endl;
    return 0;
}
/*
output:
Enter two integers: 5 9 
LCM: 45, GCD: 1
*/