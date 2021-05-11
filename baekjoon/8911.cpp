#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        string str;
        vector<pair<int, int>> pos;
        cin >> str;
        int dir = 0; // 북 0  동 1 남 2 서 3
        pair<int, int> current = make_pair(0,0);
        pos.push_back(current);

        for(int i=0; i<str.length(); i++){
            if(str[i] == 'F'){
                switch (dir) {
                    case 0 : {
                        current.second++;
                        break;
                    } 
                    case 1 : {
                        current.first++;
                        break;
                    }
                    case 2 : {
                        current.second--;
                        break;
                    }
                    case 3 : {
                        current.first--;
                        break;
                    }
                }
                pos.push_back(current);
            }else if(str[i] == 'B') {
                switch (dir) {
                    case 0 : {
                        current.second--;
                        break;
                    } 
                    case 1 : {
                        current.first--;
                        break;
                    }
                    case 2 : {
                        current.second++;
                        break;
                    }
                    case 3 : {
                        current.first++;
                        break;
                    }
                }
                pos.push_back(current);
            }else if(str[i] == 'L') {
                dir = (dir == 0) ? 3 : dir-1;
            }else if(str[i] == 'R') {
                dir = (dir+1) % 4;
            }
        }

        sort(pos.begin(), pos.end());
        int diffX = pos[pos.size()-1].first - pos[0].first;

        sort(pos.begin(), pos.end(), comp);
        int diffY = pos[pos.size()-1].second - pos[0].second;

        cout << diffX * diffY << endl;
    }
    return 0;
}