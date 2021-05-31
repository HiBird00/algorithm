#include<iostream>
#include<string.h>

using namespace std;

int n, selected[10] = {0,}, ret[10];
char ch[10];

bool solve(int cnt, int type) {
    if(cnt == n+1) {
        // 부등호 검사
        for(int i=0; i<n; i++) {
            switch(ch[i]){
                case '<' : {
                    if(ret[i] >= ret[i+1]) {
                        return false;
                    }
                    break;
                }
                case '>' : {
                    if(ret[i] <= ret[i+1]){
                        return false;
                    }
                    break;
                }
            }
        }
        for(int i=0; i<n+1; i++) {
            cout << ret[i];
        }
        cout << endl;        
        
        return true;
    }

    if(type) {
        for(int i=9; i>=0; i--) {
            if(!selected[i]) {
                // 선택x
                selected[i] = true;
                ret[cnt] = i;
                if(solve(cnt+1, type)){
                    return true;
                };
                selected[i] = false;
            }
        }
    }else{
        for(int i=0; i<10; i++) {
            if(!selected[i]) {
                // 선택x
                selected[i] = true;
                ret[cnt] = i;
                if(solve(cnt+1, type)){
                    return true;
                };
                selected[i] = false;
            }
        }
    }
    return false;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> ch[i];
    }
    // 최대
    solve(0, 1);
    // 최소
    memset(selected, 0, sizeof(selected));
    solve(0, 0);
    
    return 0;
}