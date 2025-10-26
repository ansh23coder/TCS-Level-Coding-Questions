// https://www.geeksforgeeks.org/problems/prime-number2314/1

#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i=3; i*i <= n; i+=2){
        if(n % i == 0) 
            return false;
    }
    return true;
}
int main(){
    int n;
    cin>> n;
    cout << isPrime(n);
    return 0;
}