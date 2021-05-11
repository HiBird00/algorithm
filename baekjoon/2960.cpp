#include<iostream>

using namespace std;

int main() {
    int N, K, isErased[1001] = {0,};
    cin >> N >> K;
    int cnt = 0;
    while(1) {
        int i;
        for(i=2; i<=N; i++){
            if(!isErased[i]){
                break;
            }
        }
        if(i == N+1) break;
        for(int j=1; ; j++){
            if(i*j > N) break;
            if(!isErased[i*j]){
                isErased[i*j] = true;
                cnt++;
                if(cnt == K){
                    cout << i*j << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}