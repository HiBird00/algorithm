#include<iostream>
#include<cmath>

using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    long long z = 100*y/x;
    if(z>=99){
        cout << -1 << endl;
    }else {
        cout << (int)ceil((x * (z+1) - 100 * y) / (double)(99 - z)) << endl;
    }

    return 0;
}