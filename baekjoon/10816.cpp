#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

int N, M;
vector<int> A, B, CNT;

int solve(int find, int start, int end) {
    if(start > end) return 0;

    int mid = (start + end) / 2;
    if(A[mid] == find) return CNT[mid];
    if(A[mid] > find) return solve(find, start, mid-1);
    if(A[mid] < find) return solve(find, mid+1, end);
}

int main() {
    cin >> N;
    vector<int> temp(N, 0);
    for(int i=0; i<N; i++){
        cin >> temp[i];
    }
    sort(temp.begin(), temp.end());
    
    A.push_back(INT_MIN);
    CNT.push_back(INT_MIN);
    for(int i=0; i<N; i++){
        if(A.back() == temp[i]) {
            CNT.back()++;
        }else{
            A.push_back(temp[i]);
            CNT.push_back(1);
        }
    }
    cin >> M;
    B.assign(M, -1);
    for(int i=0; i<M; i++){
        cin >> B[i];
    }   

    vector<int> ret;
    for(int i=0; i<M; i++) {
        ret.push_back(solve(B[i], 1, A.size()-1));
    }
    for(int i=0; i<M; i++) {
        cout << ret[i] << " ";
    }
    
    return 0;
    
}