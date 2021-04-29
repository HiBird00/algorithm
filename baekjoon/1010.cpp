#include<iostream>
#include<string.h>

using namespace std;

int N, M;

int main() {
    int T;
    cin >> T;
    while(T--){
        cin >> N >> M;
        int cache[31][31]={0};
        for(int i=0; i<=M; i++) cache[1][i] = i;
        for(int i=2; i<=N; i++){
            for(int j=i; j<=M; j++){
                for(int k=j; k>=i ;k--){
                    cache[i][j] += cache[i-1][k-1];
                }
            }
        }
        cout << cache[N][M] << endl;
    }

    return 0;
}