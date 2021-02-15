#include<iostream>

using namespace std;

int cache[1000001];

int main(){
    int n;
    cin >> n;
    cache[0] = 0; cache[1] = 1;
    for(int i=2; i<=n; i++){
        if(i == 2) {cache[i]=2; continue;}
        cache[i] = (cache[i-2] + cache[i-1]) % 15746;
    }
    cout << cache[n] << endl;
    return 0;
}