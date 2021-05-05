#include<iostream>

using namespace std;

#define MOD 10007;

int main() {
    int arr[1000];
    int n;
    cin >> n;
    arr[0] =1; arr[1] = 3;
    for(int i=2; i<n; i++){
        arr[i] = (arr[i-1] + arr[i-2] * 2) % MOD;
    }
    cout << arr[n-1] << endl;
    return 0;
}