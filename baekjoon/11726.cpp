#include<iostream>

using namespace std;

#define MOD 10007

int N, dp[1001];

int main() {
    cin >> N;
    dp[1] = 1; dp[2] = 2;
    for(int i=3; i<=N; i++){
        dp[i] = dp[i-1] % MOD +dp[i-2] % MOD;
    }
    cout << dp[N] % MOD;
    return 0;
}