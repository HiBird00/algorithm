#include<iostream>

using namespace std;

int n,m;
int number[8];

void solve(int start, int cnt){
    if(cnt == m) {
        for(int i=0; i<cnt; i++){
            cout << number[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int next=start; next<=n; next++){
        number[cnt] = next;
        solve(next, cnt+1);
    }
}

int main() {
    cin >> n >> m;
    solve(1, 0);
    return 0;
}