// https://www.hackerrank.com/contests/oriental-campus-181025/challenges/moving-siever

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e6+1;
vector<bool> isprime(MAX, true);
vector<int> primecount(MAX, 0);

void sieve(){
    isprime[0] = isprime[1] = false;
    for(int i=2; i*i < MAX; ++i){
        if(isprime[i]){
            for(int j=i*i; j<MAX; j+=i){
                isprime[j] = false;
            }
        }
    }
    
    for(int i=1; i<MAX; ++i){
        primecount[i] = primecount[i-1] + (isprime[i] ? 1 : 0);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; 
    cin >> t;
    sieve();
    while(t--){
        int n;
        cin >> n;
        if(n <= 2) cout << 0<< endl;
        else if (n<MAX){
            cout << primecount[n-1] << endl;
        }
        else {
            double approx = n / log((n)-1);
            cout << (int) approx << endl;
        }
    }
    return 0;
}
