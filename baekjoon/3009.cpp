#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int x[3], y[3], retX, retY;
    for(int i=0; i<3; i++){
        cin >> x[i] >> y[i];
    }
    sort(x, x+3);
    sort(y, y+3);
    if(x[0] == x[1]) retX = x[2];
    else retX = x[0];
    if(y[0] == y[1]) retY = y[2];
    else retY = y[0];
    cout << retX << " " << retY;
    return 0;
}