#include<iostream>
#include<math.h>

using namespace std;

int main() {
    long long T, x, y;
    cin >> T;
    while(T--) {
        cin >> x >> y;
        long long diff = y-x; // 4 ,5
        long long a = sqrt(diff); // 2
        if(diff == a*a){
            cout << a*2-1<< endl;
        }else if(diff > a*a && diff <= a*a+a){
            cout << 2*a << endl;
        }else if(diff > a*a+a && diff <= (a+1)*(a+1)){
            cout << 2*a + 1 << endl;
        }
    }
    return 0;
}