#include <iostream>
#include <limits>
#include <algorithm>
#include <string.h>

using namespace std;

long long arrA[102];
long long arrB[102];
int n;
int m;
int cache[102][102];
const long long MIN = numeric_limits<long long>::min();

int jlis(int a, int b){
    int& ret = cache[a+1][b+1];
    if(ret != -1) return ret;

    long long aa = (a == -1 ? MIN : arrA[a]);
    long long bb = (b == -1 ? MIN : arrB[b]);
    long long maxE = max(aa, bb);

    ret = 0;
    for(int i=a+1; i<n; i++){
        if(maxE < arrA[i])
            ret = max(ret, jlis(i, b)+1);
    }

    for(int i=b+1; i<m; i++){
        if(maxE < arrB[i])
            ret = max(ret, jlis(a, i)+1);
    }
    return ret;

    
}

int main(){
    int c;
    cin >> c;
    while(c--){
        cin >> n >> m;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<n ;i++){
            cin >> arrA[i];
        }
        for(int i=0; i<m; i++){
            cin >> arrB[i]; 
        }
        cout << jlis(-1,-1) << endl;
    
    }
    return 0;
}
