#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int chess[16][16];
int cnt = 0;

void validation(int col, int row, int state) {
    int i=1;
    while(col+i<n){
        chess[col+i][row] += state;
        if(row-i >= 0) chess[col+i][row-i] += state;
        if(row+i < n) chess[col+i][row+i] += state;
        i++;
    }
}

void queen(int col) {
    if(col == n){ cnt++; return; }
    for(int row=0; row<n; row++){
        if(chess[col][row] == 1){
            validation(col, row, -1);
            queen(col+1);
            validation(col, row, 1);
        }
    }

}

int main() {
    cin >> n;
    fill(chess[0],chess[0]+(16*16),1); 

    queen(0);
    cout << cnt << endl;

    return 0;
}