#include<iostream>
#include<string.h>

using namespace std;

int N, M, map[500][500], cache[500][500];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solve(int row, int col) {
    if(row == N-1 && col == M-1) return 1;

    int &ret = cache[row][col];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=0; i<4; i++){
        int nextX = col + dx[i];
        int nextY = row + dy[i];
        if(nextY >= 0 && nextY < N && nextX >= 0 && nextX < M){
            if(map[row][col] > map[nextY][nextX]){
                ret += solve(nextY, nextX);
            }
        }
    }
    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d", solve(0,0));
  
    return 0;
}