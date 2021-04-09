#include<iostream>
#include<limits.h>
#include<algorithm>

using namespace std;

int N, num[11], oper[4];
int minR = INT_MAX;
int maxR = INT_MIN;

void solve(int idx, int sum) {
    if(idx == N)  {
        minR = min(minR, sum);
        maxR = max(maxR, sum);
        return;
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<oper[i]; j++){
            oper[i]--;
            switch (i) {
            case 0:
                solve(idx+1, sum+num[idx]);
                break;
            case 1:
                solve(idx+1, sum-num[idx]);
                break;
            case 2:
                solve(idx+1, sum*num[idx]);
                break;
            case 3:
                solve(idx+1, sum/num[idx]);
                break;
            }
            oper[i]++;
        }
    }
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num[i];
    }
    for(int i=0; i<4; i++){
        cin >> oper[i];
    }

    solve(1, num[0]);

    cout << maxR << '\n';
    cout << minR << '\n';
    
    return 0;

}