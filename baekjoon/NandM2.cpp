#include<iostream>

using namespace std;

int n,m;
bool cache[9];

void solve(int start, int cnt) {
    if(cnt == m){
        for(int i=1; i<=n; i++){
            if(cache[i]) cout << i << " ";
        }
        cout << '\n';
    }
    
    for(int next=start+1; next<=n; next++){
        if(!cache[next]){
            cache[next] = true;
            solve(next, cnt+1);
            cache[next] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    solve(0, 0);

    return 0;    
}