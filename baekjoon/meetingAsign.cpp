#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>> meeting;

// 두번째 값이 작은 순, 같다면 첫번째가 작은 순
bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        meeting.push_back(make_pair(a, b));
    }

    sort(meeting.begin(), meeting.end(), comp);

    int count = 1;
    int end = meeting[0].second;
    for(int i=1; i<n; i++){
        if(meeting[i].first >= end){
            end = meeting[i].second;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}