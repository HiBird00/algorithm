#include<iostream>
#include<algorithm>

using namespace std;

int k, arr[12], turn[12];

void solve(int start, int cnt) {
    if(cnt == 6) {
        for(int i=0; i<6; i++){
            cout << turn[i] << " ";
        }
        cout << endl;
    }

    for(int i=start; i<k; i++){
        turn[cnt] = arr[i];
        solve(i+1, cnt+1);
    }
}

int main() {
    while(1){
        cin >> k;
        if(k == 0) return 0;

        for(int i=0; i<k; i++){
            cin >> arr[i];
        }

        solve(0, 0);
        cout << endl;
    }


    return 0;
}