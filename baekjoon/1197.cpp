#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int root[10001];
int v, e, cnt = 0;
long long ret = 0;
vector<pair<pair<int, int>, long long>> weight;

bool comp(pair<pair<int, int>, long long> a, pair<pair<int, int>, long long> b) {
    return a.second < b.second;
}

int find(int x) {
    if(root[x] == x) {
        return x;
    }else {
        return find(root[x]);
    }
}

void unionFun(int x, int y) {
    int X = find(x);
    int Y = find(y);

    root[Y] = X;
}

int main() {
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        weight.push_back(make_pair(make_pair(a, b), c));
    }

    for(int i=1; i<=v; i++){
        root[i] = i;
    }

    sort(weight.begin(), weight.end(), comp);
    
    for(int i=0; i<e; i++) {
        pair<int, int> n = weight[i].first;
        if(find(n.first) != find(n.second)) {
            unionFun(n.first, n.second);
            ret += weight[i].second;
            cnt++;
        };
        if(cnt == v-1) break;
    }
 
    cout << ret << endl;

    return 0;
}