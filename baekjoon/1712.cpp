#include<iostream>

using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    if(C>B){
        int N = A / (C-B);
        cout << N+1 << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;  
}