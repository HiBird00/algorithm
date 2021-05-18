#include<iostream>
#include<string.h>

#define MOD 1000000000

using namespace std;

int N, K, cache[201][201];

int solve(int n, int k) {
    if(k == 1 || n == 0) {
        return cache[n][k] = 1;
    }
    if(cache[n][k] != -1) return cache[n][k];

    cache[n][k] = 0;
    for(int i=0; i<=n; i++){
        cache[n][k] += solve(i, k-1);
        cache[n][k] %= MOD;
    }
    return cache[n][k];
}

int main() {
    cin >> N >> K;
    memset(cache, -1, sizeof(cache));

    cout << solve(N, K) << endl;

    return 0;
}