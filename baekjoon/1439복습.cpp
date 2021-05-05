#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt[2] = {0,};
    char temp = str[0];
    cnt[temp-'0']++;
    for(int i=1; i<str.length(); i++){
        if(temp != str[i]){
            temp = str[i];
            cnt[temp-'0']++;
        }
    }
    cout << min(cnt[0], cnt[1]) << endl;
    return 0;   
}