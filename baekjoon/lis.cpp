#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int num[1000];
int cache[1000];
int n;

int solve(int start) {
    int &ret = cache[start];

    if(ret != -1) return ret;
    
    ret = 1;
    for(int next=start+1; next<n; next++){
        if(num[start] < num[next]){
            ret = max(ret, solve(next) + 1);
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    memset(cache, -1, sizeof(cache));
    
    int ret = 0;
    for(int i=0; i<n; i++){
        ret = max(ret, solve(i));
    }
    cout << ret << endl;

    return 0;
}