#include<iostream>
#include<algorithm>

using namespace std;

int n, arr[100000], cache[100000];

int solve(int idx) {
    if(idx == 0) return cache[idx] = arr[idx];

    return cache[idx] = max(arr[idx], solve(idx-1) + arr[idx]);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    solve(n-1);
    cout << *max_element(cache, cache+n) << endl;

    return 0;
}