#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int N, dp[100001];

int solve(int n){
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    int j = sqrt(n);
    dp[n] = solve(n-1) + 1;
    for(int i=1; i<=j; i++){
        dp[n] = min(dp[n], solve(n-i*i) + 1);
    }
    return dp[n];
}

int main() {
    cin >> N;
    for(int i=1; i<=N; i++){
        dp[i] = -1;
    }
    cout << solve(N);
    return 0;
}