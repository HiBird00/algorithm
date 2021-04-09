#include <iostream>
#include <algorithm>

using namespace std;

int atm[1000];
int cache[1000];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> atm[i];
    }
    sort(atm, atm+n);
    cache[0] = atm[0];
    for(int i=1; i<n; i++) {
        cache[i] = cache[i-1] + atm[i];
    }
    int ret = 0;
    for(int i=0; i<n; i++){
        ret += cache[i];
    }
    cout << ret << endl;

    return 0;

}