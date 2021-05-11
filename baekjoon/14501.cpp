#include<iostream>
#include<limits.h>
#include<algorithm>

using namespace std;

int N, arr[16][2];
int ret = INT_MIN;

int solve(int start, int total){
    if(start > N){
        return 0;
    }

    if(start == N){
        return total;
    }

    for(int i = start; i<N; i++){
        ret = max({ret, total, solve(i + arr[i][0], total + arr[i][1])});
    }

    return ret;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i=0; i<N; i++){
        int next = arr[i][0];
        ret = max(ret,solve(i + next, arr[i][1]));
    }
    
    cout << ret << endl;

    return 0;
}