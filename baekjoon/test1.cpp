#include<iostream>
#include<string>
#include<vector>

using namespace std;

char moeum[5] = {'a', 'e',' i', 'o', 'u' };

int main() {
    string str;
    vector<pair<int, char>> m;
    cin >> str;
    for(int i=0; i<str.length(); i++) {
        iterator it =  find(moeum.begin(), moeum.end(), str[i]);
        if(it != moeum.end()) {
            m.push_back(make_pair(i, str[i]));
        }
    }

    for(int i=m.size()-1; i>=0; i--) {
        str[m[i].first] = m[i].second;
    }

    cout << str << endl;

    return 0;
}