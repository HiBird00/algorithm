#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int cache[500][500];
int number[500][500];
int n;

int solve(int row, int col) {
    if(row == n-1) {
        return number[row][col];
    }
    int &ret = cache[row][col];
    if(ret != -1) return ret;

    for(int i=0; i<2; i++){
        ret = max(ret, number[row][col] + solve(row+1, col+i));
    }

    return ret;
}

int main() {
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<n ;i++){
        for(int j=0; j<=i%n; j++){
             cin >> number[i][j];
        }
    }
    cout << solve(0,0) << endl;;

    return 0;
}