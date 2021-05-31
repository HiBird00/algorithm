#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    string str;
    vector<char> s;
    cin >> str;
    
    for(int i=0; i<str.length(); i++) {
        s.push_back(str[i]);
    }
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); i++ ){
        cout << s[i];
    }

    return 0;
}