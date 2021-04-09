#include <iostream>
#include <algorithm>

using namespace std;

int coin[10];

bool desc (int a, int b) {
    return a < b;
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> coin[i];
    }

    int count = 0;  
    for(int i=n-1; i>=0; i--){
        if(k >= coin[i]){
            int c = k/coin[i];
            k %= (coin[i] * c);
            count += c;
        }
        if(k == 0) break;
    }
    
    cout << count << endl;

    return 0;
}