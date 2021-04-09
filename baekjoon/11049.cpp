#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int N, dp[501][501];
pair<int,int> arr[501];

int solve(int tx, int ty) {
    if(tx == ty) return 0;

    if(tx + 1 == ty) return dp[tx][ty] = arr[tx].first * arr[tx].second * arr[ty].second;
    if(dp[tx][ty] != 0x3f3f3f3f) return dp[tx][ty];

    for(int mid = tx; mid < ty; mid++) {
        int left = solve(tx, mid);
        int right = solve(mid+1, ty);
        dp[tx][ty] = min(dp[tx][ty], left + right + (arr[tx].first * arr[mid].second * arr[ty].second));
    }
    return dp[tx][ty];
}

int main() {
    cin >> N;
    memset(dp, 0x3f, sizeof(dp));
    for(int i=0; i<N; i++){
        int r, c;
        cin >> r >> c;
        arr[i] = make_pair(r, c);
    }
    cout << solve(0, N-1);

    return 0;
}