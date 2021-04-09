#include<iostream>
#include<string.h>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int N, M,num[2001], dp[2001][2001];

int solve(int start, int end) {
    if(start >= end) return 1;

    if(dp[start][end] != -1) return dp[start][end];

    if(num[start] != num[end]) return 0;
    dp[start][end] = 1;

    return dp[start][end] = solve(start+1, end-1);
}

int main() {
    fastio;
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=N; i++){
        cin >> num[i];
    }
    cin >> M;
    for(int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        cout << solve(s, e) << endl;
    }
    
    return 0;
}