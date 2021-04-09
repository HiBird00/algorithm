#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int chess[50][50];

int main() {
    // n : 세로
    // m : 가로
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char a;
            cin >> a;
            chess[i][j] = (a=='W' ? 0 : 1);
        }
    }

    int ret = 987654321;
    for(int i=0; i<=n-8; i++){
        for(int j=0; j<=m-8; j++){
            // 8 x 8 탐색
            for(int start=0; start<2; start++){
                int prev = !start;
                int cnt = 0;
                for(int h=i; h<i+8; h++){
                    for(int w=j; w<j+8; w++){
                        if(prev == chess[h][w]){
                            cnt++;
                            prev = !chess[h][w];
                        }else{
                            prev = chess[h][w];
                        }
                    }
                    prev = !prev;
                }
                ret = min(ret, cnt);                
            }

        }
    }
    cout << ret << endl;
    return 0;
}