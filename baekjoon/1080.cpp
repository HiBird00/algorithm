#include<iostream>
#include<string>

using namespace std;

int N, M, arr[50][50], ret[50][50], cnt=0;

void reversing(int row, int col) {
    for(int i=row; i<row+3; i++){
        for(int j=col; j<col+3; j++){
            arr[i][j] = !arr[i][j];
        }
    }
}

bool checkRet() {
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] != ret[i][j]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<M; j++){
            arr[i][j] = str[j]-'0';
        }
    }
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<M; j++){
            ret[i][j] = str[j]-'0';
        }
    }

    if(checkRet()) {
        cout << 0 << endl;
        return 0;
    }

    if(N < 3 || M < 3){
        cout << -1 << endl;
        return 0;
    }

    for(int i=0; i<=N-3; i++){
        for(int j=0; j<=M-3; j++){
            if(arr[i][j] != ret[i][j]){
                reversing(i, j);
                cnt++;
                if(checkRet()) {
                    cout << cnt << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;

    return 0;
}