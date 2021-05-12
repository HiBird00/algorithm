#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int arr[100][100], n, dead[100][100];
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

void safe(int row, int col) {
    for(int i=0; i<4; i++){
        int nextX = col + dx[i];
        int nextY = row + dy[i];
        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n){
            if(!dead[nextY][nextX]){
                dead[nextY][nextX] = true;
                safe(nextY, nextX);
            }
        }
    }
}

int main() {
    cin >> n;
    int maxNum = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(maxNum < arr[i][j]) maxNum=arr[i][j];
        }
        
    }

    int temp = 0;
    int ret = 0;
    while(temp != maxNum) {
        int cnt = 0;
        memset(dead, 0, sizeof(dead));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] <= temp){
                    dead[i][j] = true;
                }
            }
            
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!dead[i][j]){
                    cnt++;
                    safe(i, j);
                }
            }
        }
        ret = max(ret, cnt);
        temp++;
    }

    cout << ret << endl;

    return 0;
}