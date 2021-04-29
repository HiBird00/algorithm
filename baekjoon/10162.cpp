#include<iostream>

using namespace std;

int arr[3] = {300, 60, 10};

int main() {
    int T;
    cin >> T;
    if(T % 10 != 0) {
        cout << -1 << endl;
        return 0;
    }
    int ret[3] = {0,};
    for(int i=0; i<3; i++){
        while(arr[i] <= T && T != 0){
            ret[i] += T / arr[i];
            T = T % arr[i];
        }
    }
    for(int i=0; i<3; i++){
        cout << ret[i] << " ";
    }
    return 0;
}