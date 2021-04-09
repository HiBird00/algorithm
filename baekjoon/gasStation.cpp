#include <iostream>
#include <vector>

using namespace std;

vector<long long> dist;
vector<long long> price;

int main() {
    int n;
    cin >> n;
    dist.push_back(0);
    for(int i=1; i<n; i++){
        long long distance;
        cin >> distance;
        dist.push_back(distance);
    }   
    for(int i=0; i<n; i++){
        long long cost;
        cin >> cost;
        price.push_back(cost);
    }
    long long sum = 0;
    long long curPrice = price[0];
    for(int i=1; i<n; i++){
        sum += curPrice * dist[i];
        if(curPrice > price[i]){
            curPrice = price[i];
        }
    }
    cout << sum << endl;
    return 0;
}