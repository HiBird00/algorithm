#include<iostream>
#include<limits.h>
#include<algorithm>
#include<cstdlib>

using namespace std;

int N, stat[20][20], index[10];
bool isPair[20]={0,};
int ret = INT_MAX;

void solve(int cnt, int idx){
    if(cnt == N/2) {
        int start = 0;
        int link = 0;
        int linkTeam[10], lCnt = 0;
        for(int i=0; i<N; i++){
            if(!isPair[i]) linkTeam[lCnt++] = i;
        }
        for(int i=0; i<cnt; i++){
            for(int j=i+1; j<cnt; j++){
                start += stat[index[i]][index[j]] + stat[index[j]][index[i]];
                link += stat[linkTeam[i]][linkTeam[j]] + stat[linkTeam[j]][linkTeam[i]];
            }
        }
        ret = min(ret, abs(start-link));
        return;
    }

    for(int i=idx+1; i<N; i++){
        if(!isPair[i]) {
            isPair[i] = true;
            index[cnt] = i;
            solve(cnt+1, i);
            isPair[i] = false;
        }
    }
    return;
}

int main() {
    cin >> N;
    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            cin >> stat[i][j];
        }
    }

    isPair[0] = true;
    index[0] = 0;
    solve(1, 0);
    cout << ret << endl;

    return 0;
}