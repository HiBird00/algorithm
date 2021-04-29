#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--) {
        long long x1, y1, r1, x2, y2, r2;
        int ret;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        if(d == 0) {
            if(r1 == r2) ret = -1;
            else ret = 0;
        }else{
            if(d == r1+r2 || d == abs(r1-r2)) ret = 1;
            else if(d > r1+r2) ret = 0;
            else if(d < r1+r2 || d>abs(r1-r2)) ret = 2;
        }
        cout << ret << endl;
    }
    return 0;
}