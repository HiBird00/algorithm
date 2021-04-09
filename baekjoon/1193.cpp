#include<iostream>
#include<math.h>

using namespace std;

int main() {
    double x;
    cin >> x;
    double ret = ceil((-1+sqrt(1+8*x))/2);
    double total = ret*(ret+1)/2;
    double diff = total-x;
    double a = 1; double b = ret;
    a += diff; b -= diff;
    if((int)ret % 2){
        // 홀수
        cout << a << "/" << b;
    }else{
        // 짝수
        cout << b << "/" << a;
    }
    return 0;
}