#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long N, C;
vector<long long> x;
vector<long long> dist;

int main() {
    cin >> N >> C;
    x.assign(N, 0);
    for(long long i=0; i<N; i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    for(int i=1; i<N; i++){
        dist.push_back(x[i]-x[i-1]);
    }

    long long min = 1;
    long long max = x[N-1] - x[0];
    long long answer = min;
    
    while(min <= max){
        long long mid = (min+max)/2;
        long long sum = 1;
        long long start = x[0];

        for(int i=1; i<N; i++){
            long long d = x[i] - start;
            if(d >= mid){
                sum++;
                start = x[i];
            }
        }

        // 부족하면
        if(sum < C) {
            max = mid - 1;
        }else{
            if(answer < mid) answer = mid;
            min = mid + 1;
        }
    }
    cout << answer << endl;
    return 0;
}