#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main() {
    cin.tie(NULL); cin.sync_with_stdio(false);
    int n, k;
    vector<pair<int, int>> arr;
    cin >> n >> k;
    string str;
    cin >> str;

    for(int i=0; i<n; i++){
        arr.push_back(make_pair(i, str[i]-'0'));
    }

    int left = 0, right = k+1;
    while(right < n+1) {
        vector<pair<int,int>> temp = arr;
        sort(temp.begin()+left, temp.begin()+right, comp);
        cout << temp[left].second;
        left = temp[left].first+1;
        right++;
    }

    return 0;
}