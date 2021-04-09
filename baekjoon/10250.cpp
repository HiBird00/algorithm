#include<iostream>
#include<string>

using namespace std;

int main() {
    int c;
    cin >> c;
    while(c--) {
        int h, w, n;
        cin >> h >> w >> n;
        int ho = (n-1)/h + 1;
        int floor = (n-1)%h+1;
        string strHo;
        if(ho/10 == 0){
            strHo = "0"+to_string(ho);
        }else{
            strHo = to_string(ho);
        }
        cout << floor << strHo << endl;
    }
    return 0;
}