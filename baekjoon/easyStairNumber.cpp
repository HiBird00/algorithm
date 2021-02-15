#include<iostream>

using namespace std;

#define MOD 1000000000

long long cache[101][10];

int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<10; i++){
       cache[1][i] = 1;
    }
    for(int i=2; i<=n; i++){
        cache[i][0] = cache[i-1][1];
        cache[i][9] = cache[i-1][8];
        for(int j=1; j<9; j++){
            cache[i][j] = (cache[i-1][j+1] + cache[i-1][j-1]) % MOD;
        }
    }
    long long sum = 0;
    for(int i=1; i<10; i++){
        sum += cache[n][i];
    }
    
   cout << sum % MOD << endl;
    return 0;

}