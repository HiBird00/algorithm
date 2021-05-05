#include<iostream>
#include<limits.h>
#include<algorithm>

using namespace std;

int n, arr[50][9], turn[9];
int ret = INT_MIN;
bool isSelected[9] = {0,};

int solve() {
    int start = 0, total = 0;
    for(int k = 0; k<n; k++){
        int runner[6] = {0,}, out = 0;
        while(out < 3){
            int current = turn[start];
            if(arr[k][current] == 0){
                out++;
            }else if(arr[k][current] == 1){
                for(int i=3; i>0; i--){
                    runner[i] = runner[i-1];
                }
                runner[0] = 1;
            }else if(arr[k][current] == 2){
                for(int i=4; i>1; i--){
                    runner[i] = runner[i-2];
                }
                runner[1] = 1;
                runner[0] = 0;
            }else if(arr[k][current] == 3){
                for(int i=5; i>2; i--){
                    runner[i] = runner[i-3];
                }
                runner[2] = 1;
                runner[0] = runner[1] = 0;
            }else if(arr[k][current] == 4){
                for(int i=0; i<3; i++){
                    runner[3] += runner[i];
                    runner[i] = 0;
                }
                runner[3]++;
            }
            for(int i=3; i<6; i++){
                total += runner[i];
                runner[i] = 0;
            }
            start = (start+1) % 9;
        }
    }

    return total;
}

void checkTurn(int cnt) {
    if(cnt == 9) {
        // 순서가 정해졌으면 경기
        ret = max(ret, solve());
        return ;
    }

    if(cnt == 3){
        turn[cnt] = 0;
        checkTurn(cnt+1);
    }else{
        for(int i=1; i<9; i++){
            if(!isSelected[i]){
                isSelected[i] = true;
                turn[cnt] = i;
                checkTurn(cnt+1);
                isSelected[i] = false;
            }
        }
    }
    
    
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<9; j++){
            cin >> arr[i][j];
        }
    }
    checkTurn(0);

    cout << ret << endl;

    return 0;
}