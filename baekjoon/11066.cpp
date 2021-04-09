#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int T, K, cost[501], sum[501], dp[501][501];

int solve(int tx, int ty) {
    if(tx == ty) return dp[tx][ty] = 0;

    if(tx + 1 == ty) return dp[tx][ty] = cost[tx] + cost[ty];

    int &ret = dp[tx][ty];
    if(ret != 0x3f3f3f3f) return ret;

    for(int mid=tx; mid<ty; mid++){
        int left = solve(tx, mid);
        int right = solve(mid+1, ty);
        ret = min(ret, left+right);
    }

    return ret += sum[ty] - sum[tx-1];
}

int main() {
    cin >> T;
    while(T--) {
        cin >> K;
        memset(dp, 0x3f, sizeof(dp));
        for(int i=1; i<=K; i++){
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
        }

        cout << solve(1, K) << endl;
    }

    return 0;
}