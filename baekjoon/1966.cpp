#include<iostream>
#include<deque>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        deque<pair<int, int>> qu;
        int a, b;
        cin >> a >> b;
        for(int i=0; i<a; i++){
            int temp;
            cin >> temp;
            qu.push_back(make_pair(temp, i));
        }

        int cnt = 0;
        while(!qu.empty()){
            int idx = 1;
            while(idx < qu.size()){
                if(qu.front().first < qu[idx].first){
                    // 하나라도 큰게 있으면 맨 뒤로
                    qu.push_back(make_pair(qu.front().first, qu.front().second));
                    qu.pop_front();
                    break;
                }
                idx++;
            }
            if(idx == qu.size()){
                cnt++;
                if(qu.front().second == b) break;
                qu.pop_front();
            }
        }
        
        cout << cnt << endl;
    }
    return 0;

}