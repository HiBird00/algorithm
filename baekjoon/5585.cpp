#include<iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ret = 0;
    int left = 1000 - N;
    int arr[6] = {500, 100, 50, 10, 5, 1};
    for(int i=0; i<6; i++){
        while(left/arr[i]){
            ret += left/arr[i];
            left = left % arr[i];
        }
    }
    cout << ret << endl;
    return 0;
}