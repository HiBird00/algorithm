#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    int N, K, sensor[10000], dist[10000], ret = 0;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> sensor[i];
    }
    sort(sensor, sensor+N);

    for(int i=1; i<N; i++){
        dist[i-1] = sensor[i]-sensor[i-1];
    }
    
    sort(dist, dist+N-1, comp);
    for(int i=K-1; i<N-1; i++){
        ret += dist[i];
    }

    cout << ret << endl;

    return 0;
}