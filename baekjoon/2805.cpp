#include<iostream>
#include<algorithm>

using namespace std;

long long N, M;
long long height[1000000];

int main() {
    cin >> N >> M;
    for(long long i=0; i<N; i++){
        cin >> height[i];
    }
    sort(height, height+N);

    long long min_len = 0;
    long long max_len = height[N-1];
    long long answer = min_len;

    while(min_len <= max_len){
        long long mid_len = (min_len + max_len) / 2;
        long long sum = 0;
        for(long long i=0; i<N; i++){
            if(height[i] > mid_len) sum += height[i] - mid_len;
        }
        // 부족하면
        if(sum < M){
            max_len = mid_len - 1;
        }else{
            if(answer < mid_len) answer = mid_len;
            min_len = mid_len + 1;
        }
    }
    cout << answer << endl;
    return 0;
}