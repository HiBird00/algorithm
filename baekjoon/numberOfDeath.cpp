#include<iostream>
#include<string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ret = 1;
    int cnt = 0;
    while(1){
        if(to_string(ret).find("666") != string::npos){
            cnt++;
            if(cnt==n) break;
        }
        ret++;
    }
    
    cout << ret << endl;

    return 0;
}