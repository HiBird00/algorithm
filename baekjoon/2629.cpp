#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int C, M, weight[31], dp[31][40001];

int solve(int cnt, int ret) {
    if(cnt > C) return 0;

    if(dp[cnt][ret] != 0) return dp[cnt][ret];

    dp[cnt][ret] = true;

    solve(cnt+1, ret+weight[cnt+1]);
    solve(cnt+1, ret);
    solve(cnt+1, abs(ret - weight[cnt+1]));

    return 0;
}

int main() {
    cin >> C;
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=C; i++){
        cin >> weight[i];
    }
    cin >> M;
    solve(0,0);
    for(int i=0; i<M; i++){
        int find;
        cin >> find;
        if(dp[C][find]){
            cout << "Y";
        }else{
            cout << "N";
        }
        cout << " ";
    }
    return 0;
}