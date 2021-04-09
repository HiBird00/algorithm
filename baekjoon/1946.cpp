#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, N;

int main() {
    cin >> T;
    while(T--) {
        cin >> N;
        vector<pair<int, int>> arr;
        for(int i=0; i<N; i++){
            int a, b;
            cin >> a >> b;
            arr.push_back(make_pair(a,b));
        }
        sort(arr.begin(), arr.end());
        
        int sum = 1;
        int test = arr[0].second;
        for(int i=1; i<N; i++){
            if(arr[i].second < test){
                sum++;
                test = arr[i].second;
            }
        }
        cout << sum << endl;
    }
    return 0;

}