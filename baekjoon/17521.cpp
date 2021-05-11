#include<iostream>

using namespace std;

int main() {
    long long n, w, arr[15], coin = 0;
    cin >> n >> w;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // 최고점 이전 중 가장 낮은 곳에서 사고
    // 최고점에서 팔자
    int current = 0;
    bool turn = true; // true : 사는 차례  false : 파는 차례
    while(current < n-1){
        int i;
        for(i=current; i<n-1; i++){
            if(turn){
                // 최저점을 찾자
                if(arr[i] < arr[i+1]){
                    coin += w / arr[i];
                    w %= arr[i];
                    turn = !turn;
                    break;
                }
            }else {
                // 최고점을 찾자
                if(arr[i] > arr[i+1]){
                    w += coin * arr[i];
                    coin = 0;
                    turn = !turn;
                    break;
                }
            }
        }
        current = i + 1;
    }

    w += coin * arr[n-1];
    cout << w << endl;

    return 0;
}