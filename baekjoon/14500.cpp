#include<iostream>
#include<limits.h>
#include<algorithm>

using namespace std;

int N, M, arr[500][500], visited[500][500] = {0,};
int dx[4] = { 1, 0, -1, 0 }; // 동 남 서 북
int dy[4] = { 0, 1, 0, -1 };
int ret = INT_MIN;

int expX[4][2] = {
    {-1, -1}, { 0, 0 }, { 1, 0 }, { 1, 0 }
};
int expY[4][2] = {
    { -1, 1 }, { -1, 1 }, { 0, 1 }, { 0, -1 }
};

void expDfs(int row, int col){
    int total = arr[row][col];
    int nextX = col + dx[0]; int nextY = row + dy[0];
    if(nextY >= 0 && nextY < N && nextX >= 0 && nextX < M){
        total += arr[nextY][nextX];
    }else{
        return ;
    }

    for(int i=0; i<4; i++){
        int x_1 = nextX + expX[i][0]; int x_2 = nextX + expX[i][1];
        int y_1 = nextY + expY[i][0]; int y_2 = nextY + expY[i][1];
        if(y_1 >= 0 && y_1 < N && x_1 >= 0 && x_1 < M  && y_2 >= 0 && y_2 < N && x_2 >= 0 && x_2 < M ){
            ret = max(ret, total + arr[y_1][x_1] + arr[y_2][x_2]);
        }
    }
}

void dfs(int row, int col, int cnt, int total) {
    if(cnt == 4){
        ret = max(ret, total);
        return ;
    }
    
    for(int i=0; i<4; i++){
        int nextX = col + dx[i]; int nextY = row + dy[i];
        if(nextY >= 0 && nextY < N && nextX >= 0 && nextX < M && !visited[nextY][nextX]){
            visited[nextY][nextX] = true;
            dfs(nextY, nextX, cnt+1, total + arr[nextY][nextX]);
            visited[nextY][nextX] = false;
        }
    }

}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visited[i][j] = true;
            dfs(i, j, 1, arr[i][j]);
            visited[i][j] = false;
            expDfs(i, j);
        }
    }

    cout << ret << endl;

    return 0;
}