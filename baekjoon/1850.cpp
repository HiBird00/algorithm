#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    
    while(a != 0 && b != 0) {
        if(a >= b) {
            a -=b *(a/b);
        }else {
            b -=a *(b/a);
        }
    }

    int ret = max(a, b);
    for(int i=0; i<ret; i++){
        cout << 1;
    }
 

    return 0;
}