// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
// https://www.geeksforgeeks.org/dsa/program-to-find-largest-element-in-an-array/


/*
class Solution {
  public:
    int largest(vector<int> &arr) {        
        // method 1:
        // sort(arr.begin(), arr.end());
        // return arr.back();
        
        // method 2: 
         return *max_element(arr.begin(), arr.end());
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

int maxDigit(int num) {
    string newStr = to_string(num);
    int maxDigit = 0;

    for(int i=0; i<newStr.size(); i++){
        int digit = newStr[i] - '0'; // char to str
        if(digit > maxDigit){
            maxDigit = digit;
        }
    }
    return maxDigit;
}


int main(){
    int num; // 123
    cout << "enter number: ";
    cin >> num;
    int ans = maxDigit(num);
    cout << "Max number: " << ans;
}
/*
enter number: 123654
Max number: 6
*/

