#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int cache[500];
vector<pair<int, int>> cord; 

bool comp(pair<int, int>a, pair<int, int>b){
    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        cord.push_back(make_pair(a, b));
    }
    sort(cord.begin(), cord.end(), comp);

    int len = -1;
    for(int i=0; i<n; i++){
        cache[i] = 1;
        for(int j=0; j<i; j++){
            if(cord[i].second > cord[j].second && cache[j] + 1 > cache[i]) {
                cache[i] = cache[j] + 1;
            }
        }
        len = max(len, cache[i]);
    }
    cout << n - len << endl;
    return 0;

}