#include<iostream>
#include<algorithm>

using namespace std;

long long N, K;

int main() {
    cin >> N >> K;
    
    long long min_num = 1;
    long long max_num = N*N;
    long long answer = min_num;

    while(min_num <= max_num) {
        long long mid = (min_num+max_num)/2;
        long long cnt = 0;
        for(int i=1; i<=N; i++){
            cnt += min(mid/i, N);
        }
        if(cnt < K) {
            min_num = mid+1;
        }else{
            answer = mid;
            max_num = mid-1;
        }
    }
    cout << answer << endl;
    return 0;
}