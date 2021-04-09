#include<iostream>
#include<algorithm>

using namespace std;

int N, M, wook[301][301], dp[301][301];

int solve(int row, int col) {
    if(row > N || col > M) return 0;
    
    if(dp[row][col] != -1) return dp[row][col];
    dp[row][col] = 0;
    if(wook[row][col]) dp[row][col]++;
    return dp[row][col] += max(solve(row+1, col), solve(row, col+1));
}

int main() {
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> wook[i][j];
            dp[i][j] = -1;
        }
    }
    cout << solve(1,1) << endl;
    return 0;
    
}