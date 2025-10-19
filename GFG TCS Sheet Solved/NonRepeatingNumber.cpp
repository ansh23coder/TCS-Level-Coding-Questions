// https://www.geeksforgeeks.org/dsa/non-repeating-element/
// https://www.geeksforgeeks.org/problems/non-repeating-element3958/1

// arr = {9, 4, 9, 6. 7. 4}

#include<bits/stdc++.h>
using namespace std;

int firstNonRepeating(int arr[], int n){
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<n; j++){
            if(i != j && arr[i] == arr[j])
                break;
        }
        if(j == n)
            return arr[i];
    }
    return -1;
}
int main(){
    int arr[] = {9,4,9,6,7,4};
    int n=sizeof(arr) / sizeof(arr[0]);
    cout << "Number that is non repeating is: " << firstNonRepeating(arr, n);
    return 0;
}
// Number that is non repeating is: 6


// method 2: 
int firstNonRepeating(int arr[], int n)
{
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++)
        mp[arr[i]]++; // inserting arr elements into "unord_map"
    for(int i=0; i<n; i++)
        if(mp[arr[i]] == 1)
            return arr[i];
    return -1;
}