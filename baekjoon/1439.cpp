#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt = 1;
    for(int i=1; i<str.length(); i++){
        if(str[i-1] != str[i]) cnt++;
    }
    cout << cnt /2 << endl;
   
    return 0;
}