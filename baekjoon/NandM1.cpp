#include<iostream>
#include<vector>

using namespace std;

bool cache[9] = {false,};
int number[9];

int n,m;

int solve(int cnt){
    if(cnt == m){
        for(int i=0; i<cnt; i++){
            cout << number[i] << " ";
        }
        // cout << endl; 은 느려서 시간초과가 떴다.
        cout << '\n';
        return 0;
    }

    for(int next=1; next<=n; next++){
        // 방문 안했으면
        if(!cache[next]){
            cache[next] = true;
            number[cnt] = next;
            solve(cnt+1);
            cache[next] = false;
        }
    }

    return 0;
}

int main() {

    cin >> n >> m;
    
    solve(0);

    return 0;
}