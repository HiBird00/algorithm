#include <iostream>

using namespace std;

long long a, b, c;

long long solve(long long len) {
    if (len == 1) return a;

    long long mid = len / 2;
    long long left = len % 2;
    long long ret = solve(mid);
    ret = (ret*ret) % c;
    
    if(left == 1){
        ret = (ret * a) % c;
    }
    return ret % c;
}

int main() {
    cin >> a >> b >> c;
    cout << solve(b) % c<< endl;
    return 0;
}