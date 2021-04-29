#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[1000000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
  
    int ret = 0;
    for(int i=0; i<N; i++){
        if(ret+1 < arr[i]) break;
        ret += arr[i];
    }
    cout << ret+1 << endl;
    return 0;
}