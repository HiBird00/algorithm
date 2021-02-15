#include <iostream>

using namespace std;

long long cache[100];

int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        cache[0] = cache[1] = cache[2] = 1;
        cache[3] = cache[4] = 2;
        for(int i=5; i<n; i++){
            cache[i] = cache[i-5] + cache[i-1];
        }

        cout << cache[n-1] << endl;
    }
    return 0;
}