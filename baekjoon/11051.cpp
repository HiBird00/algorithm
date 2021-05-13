#include<iostream>
#include<string.h>

using namespace std;

#define MOD 10007

int n, k, cache[1001][1001];

int solve(int N, int K) {
    if(K == 0 || K == N){
        return cache[N][K] = 1;
    }
    if(K == 1) return cache[N][K] = N;

    if(cache[N][K] != -1) return cache[N][K]; 

    return cache[N][K] = (solve(N-1, K) % MOD + solve(N-1, K-1) % MOD) % MOD;
}

int main() {
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    cout << solve(n, k) << endl;;


    return 0;
}