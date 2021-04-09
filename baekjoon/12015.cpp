#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, A[1000000];

int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    } 
    
    vector<int> ret;
    ret.push_back(A[0]);

    for(int i=1; i<N; i++){
        if(ret.back() < A[i]) {
            ret.push_back(A[i]); 
        }
        else{
            vector<int>::iterator iter = lower_bound(ret.begin(), ret.end(), A[i]);
            ret[iter - ret.begin()] = A[i];
        }
    }

    cout << ret.size() << endl;

    return 0;
}