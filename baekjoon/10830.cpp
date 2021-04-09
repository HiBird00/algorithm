#include <iostream> 
#include <vector>

using namespace std;

typedef vector<vector<int>> Temp;

long long N, B;

Temp multi(Temp sum, Temp temp) {
    Temp result(N, vector<int>(N,0));
    for(long long i=0; i<N; i++){
        for(long long j=0; j<N; j++){
            for(long long k=0; k<N; k++){
                result[i][k] += (sum[i][j]*temp[j][k]) % 1000;
            }

        }
    }
    return result;
}

Temp solve(Temp A, long long len) {
    if(len == 1) {
        return A;
    }

    if(len%2 > 0) {
        return multi(solve(A, len-1), A);
    }

    Temp result = solve(A, len/2);
    result = multi(result,result);
    
    return result;
}


int main() {
    cin >> N >> B;
    Temp A(N, vector<int>(N));
    for(long long i=0; i<N; i++){
        for(long long j=0; j<N; j++){
            cin >> A[i][j];
        }
    }

    Temp ret = solve(A, B);
    
    for(long long i=0; i<N; i++){
        for(long long j=0; j<N; j++){
            cout << ret[i][j] % 1000 << " ";
        }
        cout << '\n';
    }
    
    return 0;
}