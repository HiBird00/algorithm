#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=3 ;i++) {
        if(i % 2 == 1) {
            for(int j=1; j<=n; j++) {
                cout << (i-1)*n + j << " ";
            }
        }else {
            for(int j=0; j<n; j++) {
                cout << i*n - j << " ";
            }
        }
        cout << endl;
    }


    return 0;
}