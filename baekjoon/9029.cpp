#include<iostream>

using namespace std;

int N, T, arr[10001];

int main() {
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=0; i<10001; i++){
            arr[i] = 0;
        }
        for(int i=2; i*i<=N; i++){
            if(!arr[i]){
                for(int j=i*i; j<=N; j+=i){
                    arr[j] = true;
                }
            }
        }
        
        int mid = N/2;
        for(int i=1;; i++){
            int temp = i;
            if(N % 2 == 0){
                temp--;
            }
            if(!arr[mid-temp] && !arr[mid+temp]){
                cout << mid-temp << " " << mid+temp << endl;
                break;
            }
        }
    }
    return 0;
}