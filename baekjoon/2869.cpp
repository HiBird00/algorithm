#include <iostream>
#include<math.h>

using namespace std;

int main() {
    double A, B, V;
    cin >> A >> B >> V;
    cout << (int)ceil((V-B)/(A-B));
    return 0;
}