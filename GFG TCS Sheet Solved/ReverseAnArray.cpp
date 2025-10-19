// https://www.geeksforgeeks.org/dsa/program-to-reverse-an-array/

#include<bits/stdc++.h>
using namespace std;

void reverseArr(vector<int>& arr){
    int n=arr.size();

    reverse(arr.begin(), arr.end());
    
}

int main(){
    vector<int> arr = {4, 41, 30, 12, 1};
    reverseArr(arr);
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}// 1 12 30 41 4

// method 2 :
#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr) {
    int n = arr.size();
    
    // Iterate over the first half and 
    // for every index i,
    // swap arr[i] with arr[n - i - 1]
    for(int i = 0; i < n/2; i++) {
    	swap(arr[i], arr[n - i - 1]);
    }
}
int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };
    reverseArray(arr);
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}