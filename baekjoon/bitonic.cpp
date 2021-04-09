#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int number[1002];
int cache[2][1002];
int n;

int main() {

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> number[i];
    }
    
    for(int i=0; i<n; i++){
        cache[0][i] = 1;
        cache[1][n-i-1] = 1;    
        for(int j=0; j<i; j++){
            if(number[i] > number[j] && cache[0][j] + 1 > cache[0][i] ){
                // up
                cache[0][i] = cache[0][j] + 1;
            }
            if(number[n-i-1] > number[n-j-1] && cache[1][n-j-1] + 1 > cache[1][n-i-1] ){
                // down
                cache[1][n-i-1] = cache[1][n-j-1] + 1;
            }
               
        }
    }
    int ret = -1;
    for(int i=0; i<n; i++){
        ret = max(ret, cache[0][i] + cache[1][i]);
    }
    cout << ret - 1 << endl;
    return 0;
}