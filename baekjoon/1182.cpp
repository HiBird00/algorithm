#include<iostream>

using namespace std;

int n, s, arr[20];
int cnt = 0;

void solve(int start, int total){
    if(total == s){
        cnt++;
    }
    for(int i=start+1; i<n; i++){
        solve(i, total + arr[i]);
    }
}

int main() {
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        solve(i, arr[i]);
    }
    cout << cnt << endl;
    return 0;
}