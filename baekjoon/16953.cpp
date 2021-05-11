#include<iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int cnt = 0;
    while(B > A){
        if(B % 10 == 1){
            B /= 10;
            cnt++;
        }else if(B % 2 == 1){
            break;
        }else {
            B /= 2;
            cnt++;
        }
    }
    
    if(A == B){
        cout << cnt + 1 << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}