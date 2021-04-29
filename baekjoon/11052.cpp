#include<iostream>
#include<algorithm>

using namespace std;

int arr[10001], cache[10001];

int main() {
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        cache[i] = arr[i];
    }

    for(int i=1; i<=N; i++){
        for(int j=0; j<=i/2; j++){
            cache[i] = max(cache[i], cache[i-j] + cache[j]);
        }
    }
    cout << cache[N] << endl;
    return 0;
}