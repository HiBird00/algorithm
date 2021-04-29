#include<iostream>

using namespace std;
// 소수 0
int arr[246913]={0,};

int main() {
    while(1){
        int n;
        cin >> n;
        if(n==0) return 0;
        arr[1] = true;
        for(int i=2; i*i<=246913; i++){
            if(!arr[i]) {
                for(int j=i*i; j<=2*n; j+=i){
                    arr[j] = true;
                }
            }
        }
        int sum=0;
        for(int i=n+1; i<=2*n; i++){
            if(!arr[i]) sum++;
        }
        cout << sum << endl;

    }

    return 0;
}