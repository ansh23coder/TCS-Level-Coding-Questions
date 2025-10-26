// https://www.geeksforgeeks.org/problems/prime-factors5052/1

/*
First, divide n by 2 repeatedly and store 2 as a unique prime factor if it divides n. Then, check odd numbers from 3 to √n, for each that divides n, store it and divide n completely by it. Finally, if n is still greater than 2, store it as it is a prime factor.

Step by step approach:

Start by checking if n is divisible by 2.
If yes, store 2 as a unique prime factor and divide n repeatedly by 2.
Loop through odd numbers i from 3 to √n:
If i divides n, store i as a unique prime factor.
Keep dividing n by i until it's no longer divisible.
After the loop, if n > 2, it is a prime and should be stored.
This ensures all unique prime factors are captured efficiently.
The algorithm avoids duplicates by fully removing each prime factor once found.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primeFac(int n){
    vector<int> res;
    // check for factor 2
    if(n%2 == 0){
        res.push_back(2);
        while(n % 2 == 0) n/=2;
    }
    // check for odd prime factors
    for(int i=3; i*i<=n; i+=2){
        if(n%i == 0){
            res.push_back(i);
            while(n % i == 0) n/= i;
        }
    }
    // if remaining n is a prime number > 2
    if(n > 2) res.push_back(n);
    return res;
}
int main(){
    int n=100;
    vector<int> result = primeFac(n);
    for(int factor : result){
        cout << factor <<" ";
    }
    return 0;
}