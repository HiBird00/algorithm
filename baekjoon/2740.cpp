#include <iostream>

using namespace std;

int N, M, K;
int A[100][100], B[100][100], ret[100][100] = {0,};

void solve() {
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<K; k++){
                ret[i][k] += A[i][j]*B[j][k];
            }
        }
    }
}


int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> A[i][j];
        }
    }
    cin >> M >> K;
    for(int i=0; i<M; i++){
        for(int j=0; j<K; j++){
            cin >> B[i][j];
        }
    }

    solve();
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}