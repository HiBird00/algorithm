#include<iostream>
#include<algorithm>

using namespace std;

int T, N, st[2][100001], dp[2][100001];

int main() {
    cin >> T;
    while(T--){
        cin >> N;
        for(int j=0; j<2; j++){
            for(int i=1; i<=N; i++){
                cin >> st[j][i];
            }
        }

        st[0][0] = st[1][0] = 0;
        dp[0][1] = st[0][1];
        dp[1][1] = st[1][1];

        for(int i=2; i<=N; i++){
            dp[0][i] = max(dp[1][i-2] + st[0][i], dp[1][i-1] + st[0][i]);
            dp[1][i] = max(dp[0][i-2] + st[1][i], dp[0][i-1] + st[1][i]);
        }

        cout << max(dp[0][N], dp[1][N]) << endl;
        
    }
    return 0;
}