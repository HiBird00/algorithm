#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 300000

int N, K;
int bag[MAX];
pair<int, int> ruby[MAX];
priority_queue<int> pq;

int main(){
    cin >> N >> K;

    for(int i = 0; i < N; i++)
        cin >> ruby[i].first >> ruby[i].second;

    for(int i = 0; i < K; i++)
        cin >> bag[i];

    sort(ruby, ruby + N);
    sort(bag, bag + K);

    long long ret = 0;
    int idx = 0;
    for(int i=0; i<K; i++){
        while(idx < N && bag[i] >= ruby[idx].first){
            pq.push(ruby[idx].second);
            idx++;
        }
        if(!pq.empty()){
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << endl;
 
    return 0;

}
