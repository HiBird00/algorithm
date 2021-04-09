#include<iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    for(int i=N/5; i>=0; i--){
        if((N-5*i) % 3 == 0) {
            cout << i+((N-5*i) / 3) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}