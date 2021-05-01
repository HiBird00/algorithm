#include<iostream>
#include<stack>

using namespace std;

int main() {
    int n, m, arr[50][50];
    stack<pair<int,int>> st;
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    int cnt = 0;
    st.push(make_pair(r,c));
    while(!st.empty()){
        int tr = st.top().first;
        int tc = st.top().second;

        // 벽
        if(arr[tr][tc] == 1){
            break;
        }
        // 청소
        if(arr[tr][tc] == 0){
            arr[tr][tc] = -1;
            cnt++;
        }

        bool check = false;
        int dir = d;
        do {
            if(dir == 0 && tc - 1 >= 0 && arr[tr][tc-1] == 0){
                st.push(make_pair(tr, tc-1));
                check = true;
                break;
            } else if(dir == 1 && tr - 1 >= 0 && arr[tr-1][tc] == 0){
                st.push(make_pair(tr-1, tc));
                check = true;
                break;
            } else if(dir == 2 && tc + 1 < m && arr[tr][tc+1] == 0){
                st.push(make_pair(tr, tc+1));
                check = true;
                break;
            } else if(dir == 3 && tr + 1 < n  && arr[tr+1][tc] == 0){
                st.push(make_pair(tr+1, tc));
                check = true;
                break;
            }
            dir = (dir == 0 ? 3 : dir-1);
        } while(dir != d);

        if(!check){
            // 다 돌았는데 없으면
            // 후진
            if(d==0){
                st.push(make_pair(tr+1, tc));
            }else if(d == 1) {
                st.push(make_pair(tr, tc-1));
            }else if(d == 2) {
                st.push(make_pair(tr-1, tc));
            }else if(d == 3) {
                st.push(make_pair(tr, tc+1));
            }
        }else {
            d = (dir == 0 ? 3 : dir-1);
        }
    }
    cout << cnt << endl;


    return 0;
}