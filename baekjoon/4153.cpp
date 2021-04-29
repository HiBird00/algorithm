#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    while(1) {
        int arr[3];
        for(int i=0; i<3; i++){
            cin >> arr[i];
        }
        if(!arr[0] && !arr[1] && !arr[2]) break;
        sort(arr, arr+3);
        if(arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]) cout << "right" << endl;
        else cout << "wrong" << endl;
    }
    return 0;
}