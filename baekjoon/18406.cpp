#include<iostream>
#include<string>

using namespace std;

string N;

int main() {
    cin >> N;
    int left = 0, right = 0;
    for(int i=0; i<N.length()/2; i++) {
        left += N[i] - '0';
        right += N[N.length() - (i+1)] - '0';
    }
    if(left == right) {
        cout << "LUCKY" << endl;
    }else {
        cout << "READY" << endl;
    }

    return 0;
}