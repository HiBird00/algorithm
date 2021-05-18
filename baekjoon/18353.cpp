#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n, arr[2000],cache[2000];
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int result = 0;
    cache[0] = 1;
    for(int i=1; i<n; i++){
        cache[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] < arr[j]) {
                cache[i] = max(cache[i], cache[j]+1);
            }
        }
        result = max(result, cache[i]);
    }

    cout << n - result;

    return 0;
}