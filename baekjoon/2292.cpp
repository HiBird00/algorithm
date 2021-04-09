#include<iostream>
#include<math.h>

using namespace std;

int main() {
    double N;
    cin >> N;
    double ret = ceil((3+sqrt(12*N-3)) / 6);
    cout << ret << endl;
    return 0;
}