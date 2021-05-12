#include<iostream>
#include<queue>

using namespace std;

int n, k, arr[102][102] = {0,};
int dx[4] = { 1, 0, -1, 0};  // 오, 아, 왼, 위
int dy[4] = { 0, 1, 0, -1};
int time = 0, current = 0, cx, cy;
queue<pair<int, int>> snake;
queue<pair<int, char>> dir;

int main() {
    cin >> n >> k;
    // 벽
    for(int i=0; i<n+2; i++){
        arr[0][i] = -1;
        arr[n+1][i] = -1;
        arr[i][0] = -1;
        arr[i][n+1] = -1;
    }
    // 사과
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    int p;
    cin >> p;

    for(int i=0; i<p; i++){
        int a; char b;
        cin >> a >> b;
        dir.push(make_pair(a, b));
    }

    cx = 1; cy = 1;
    snake.push(make_pair(cy, cx));
    arr[cy][cx] = -1;
    cx += dx[current]; cy += dy[current];
    while(arr[cy][cx] != -1){
        time++; // 1초
        if(arr[cy][cx] == 0) {
            // 사과가 없다면
            arr[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }
        arr[cy][cx] = -1;
        snake.push(make_pair(cy, cx));
        
        if(!dir.empty() && time == dir.front().first){
            if(dir.front().second == 'D'){
                current = (current+1) % 4;
            }else{
                current = (current == 0) ? 3 : current-1;
            }
            dir.pop();
        }
        cx += dx[current]; cy += dy[current];
    }

    cout << time + 1 << endl;

    return 0;
}