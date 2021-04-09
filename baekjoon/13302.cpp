#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

#define ONE 10000
#define THREE 25000
#define FIVE 37000

int N, M, dis[101]={0,}, dp[102][102];

int solve(int start, int coupon) {
    if(start > N) return 0;
    if(dp[start][coupon] != 0x3f3f3f3f) return dp[start][coupon];

    if(dis[start]) {
        return dp[start][coupon] = solve(start+1, coupon);
    }else {
        if(coupon >= 3) {
            dp[start][coupon] = min(dp[start][coupon], solve(start+1, coupon-3));
        }
        dp[start][coupon] = min({dp[start][coupon], ONE + solve(start+1, coupon), THREE + solve(start+3, coupon+1), FIVE + solve(start+5, coupon+2)});
    }

    return dp[start][coupon];
}

int main() {
    cin >> N >> M;
    memset(dp, 0x3f, sizeof(dp));
    for(int i=0; i<M; i++){
        int temp;
        cin >> temp;
        dis[temp] = true;
    }

    cout << solve(1, 0) << endl;
    return 0;    
}