#include<iostream>
#include<algorithm>

using namespace std;

int L, C;
char ret[15], arr[15];
char mList[5] = { 'a', 'e', 'i', 'o', 'u'};

void crypto(int start, int mCnt, int cnt) {
    if(cnt == L) {
        if(mCnt == 0 || L-mCnt < 2) return;
        for(int i=0; i<cnt; i++){
            cout << ret[i];
        }
        cout << endl;
        return;
    }
    
    for(int i=start+1; i<C; i++) {
        ret[cnt] = arr[i];
        if(find(mList, mList+5, arr[i]) != mList+5){
            // 모음이면
            crypto(i, mCnt+1, cnt+1);
        }else{
            crypto(i, mCnt, cnt+1);
        }
    }
}


int main() {
    cin >> L >> C;
    for(int i=0; i<C; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+C);

    crypto(-1, 0, 0);

    return 0;
}
