#include <iostream>

using namespace std;

long long N, K;
const long long P = 1000000007;

long long solve(long long B, long long mul){
    if(mul == 1) return B;
    long long mid = mul / 2;
    long long left = mul % 2;
    long long ret = solve(B, mid);
    ret = (ret*ret) % P;

    if(left == 1)
        ret = (ret * B)%P;
    
    return ret;
}

int main() {
    cin >> N >> K;

    long long a = 1, b = 1;
    for(long long i=1; i<=N; i++){
        a *= i;
        a %= P;
    }

    for(long long i=1; i<=K; i++){
        b *= i;
        b %= P;
    }

    for(long long i=1; i<=N-K; i++){
        b *= i;
        b %= P;
    }
    cout << (a * solve(b, P-2)) % P << endl;

    return 0;
}