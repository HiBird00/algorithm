#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A, B;
vector<bool> ret;

bool solve(int find, int start, int end)
{
    if(start > end) return false;

    int mid = (start+end) / 2;
    if(A[mid] == find) return true;
    if(A[mid] > find) return solve(find, start, mid-1);
    if(A[mid] < find) return solve(find, mid+1, end);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        A.push_back(n);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        B.push_back(n);
    }
    ret.assign(M, -1);

    sort(A.begin(), A.end());
   
    for(int i=0; i<M; i++){
        ret[i] = solve(B[i], 0, N-1);
    }

    for(int i=0; i<M; i++){
        cout << ret[i] << '\n';
    }
    return 0;
}