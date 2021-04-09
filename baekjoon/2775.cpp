#include<iostream>

using namespace std;

int solve(int row, int col) {
    if(row == 0) return col;

    int ret = 0;
    for(int i=1; i<=col; i++){
        ret += solve(row-1, i);
    }
    return ret;
}

int main() {
    int c, k, n, arr[15];
    cin >> c;
    while(c--) {
        cin >> k >> n;
        cout << solve(k, n) << endl;
    }
    return 0;
}  