#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int cache[1000001];

int solve(int n){
    if(n == 1) return 0;

    int &ret = cache[n];
    if(ret != -1) return ret;

    ret = 987654321;
    if(n % 3 == 0) ret = min(ret, solve(n/3)+1);
    if(n % 2 == 0) ret = min(ret, solve(n/2)+1);
    ret = min(ret, solve(n-1)+1);

    return ret;
}

int main() {
    int n;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << solve(n) << endl;

    return 0;
}