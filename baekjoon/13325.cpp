#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 2097152

int K, arr[MAX];

int solve(int k, int cur) {
    if(k == K) return arr[cur];

    // k == 0
    // left
    int left_idx = cur*2;
    int right_idx = left_idx + 1;
    int left = arr[cur] + solve(k+1, left_idx);
    int right = arr[cur] + solve(k+1, right_idx);
    
    int diff = abs(left - right);
    if(diff != 0) {
        if(left < right) {
            arr[left_idx] += diff;
        }else{
            arr[right_idx] += diff;
        }
    }
    return max(left, right);
}

int main() {
    cin >> K;
    arr[1] = 0;
    for(int i=2; i<=pow(2, K+1)-1; i++){
        cin >> arr[i];
    }
    solve(0, 1);
    int sum = 0;
  
    for(int i=2; i<=pow(2, K+1)-1; i++){
        sum += arr[i];
    }
    cout << sum << endl;
    return 0;
}