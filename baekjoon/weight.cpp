#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> people;
    for(int i=0; i<n; i++){
        int w, h;
        cin >> w >> h;
        people.push_back(make_pair(w, h));
    }

    vector<int> ret(n, 1);

    for(int i=0; i<n-1; i++){
        for(int j=i; j<n; j++){
            if(people[i].first > people[j].first && people[i].second > people[j].second)
                ret[j]++;
            else if(people[i].first < people[j].first && people[i].second < people[j].second)
                ret[i]++;
        }
    }
    for(int i=0; i<ret.size(); i++)
        cout << ret[i] << " ";
    
    return 0;
}