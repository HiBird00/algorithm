#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

typedef vector<vector<long long>> Temp;

long long N;
Temp B = {{0,1},{1,1}};

Temp multi(Temp a, Temp b) {
    Temp ret(2, vector<long long>(2, 0));
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                ret[i][k] += (a[i][j] * b[j][k]) % MOD;
            }
        }
    }
    return ret;
}

Temp solve(long long len){
    if(len == 1) return B;

    if(len % 2 > 0) return multi(solve(len-1), B);
    Temp ret = solve(len/2);
    return multi(ret, ret);
}

int main() {
    cin >> N;

    if(N==0) {cout << 0; return 0;}
    if(N==1) {cout << 1; return 0;}
    vector<long long> A = {0,1};
    Temp temp(2, vector<long long>(2, 0));
        
    Temp result = solve(N-1);
    cout << result[1][1] % MOD;

    return 0;
}