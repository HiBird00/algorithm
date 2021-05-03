#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<math.h>

using namespace std;

int N, M;
vector<pair<int, int>> bbq;
vector<pair<int, int>> home;
pair<int, int> selected[14];
int ret = INT_MAX;

// 조합
// 먼저 치킨집 M 개를 고른 뒤, home과의 거리를 계산한다.

void dfs(int idx, int cnt) {
    if(cnt == M){
        int total = 0;
        vector<int> diff(home.size(), INT_MAX);
        for(int i=0; i<M; i++){
            for(int j=0; j<home.size(); j++){
                diff[j] = min(diff[j], abs(selected[i].first - home[j].first) + abs(selected[i].second - home[j].second));
            }
        }
        for(int i=0; i<diff.size(); i++){
            total += diff[i];
        }
        ret = min(ret, total);
        return;
    }

    for(int i=idx; i<bbq.size(); i++){
        selected[cnt] = make_pair(bbq[i].first, bbq[i].second);
        dfs(i+1, cnt + 1);
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            if(temp == 1) {
                home.push_back(make_pair(i, j));
            }else if(temp == 2){
                bbq.push_back(make_pair(i, j));
            }
        }
    }

    dfs(0, 0);
    cout << ret << endl;
    return 0;
}