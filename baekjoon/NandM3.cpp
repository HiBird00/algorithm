#include<iostream>

using namespace std;

int n,m;
int number[8];

void solve(int cnt){
    if(cnt == m) {
        for(int i=0; i<cnt; i++){
            cout << number[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int next=1; next<=n; next++){
        number[cnt] = next;
        solve(cnt+1);
    }
}

int main() {
    cin >> n >> m;
    solve(0);
    return 0;
}