#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long K, N;
vector<long long> line;

int main() {
    cin >> K >> N;
    line.assign(K, 0);
    for(long long i=0; i<K; i++)
        cin >> line[i];
    sort(line.begin(), line.end());

    long long min_len = line[0]/N;
    if(min_len == 0) min_len = 1;
    long long max_len = line[K-1];
    long long answer = min_len;

    while(min_len <= max_len){
        long long mid_len = (min_len + max_len) / 2;
        long long sum=0;
        for(long long i=0; i<K; i++){
            sum += line[i] / mid_len;
        }
        
        // 개수가 부족하면
        if(sum < N){
            max_len = mid_len-1;
        }else{
            if(answer < mid_len) answer = mid_len;
            min_len = mid_len + 1;
        }
    }
    cout << answer << endl;

    return 0;
}