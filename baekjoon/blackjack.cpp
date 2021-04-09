#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int card[100];

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> card[i];
    }
    int ret = -1;
    for(int i=0; i<n-2; i++){ 
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int sum = card[i] + card[j] + card[k];
                if(sum <= m) ret = max(ret, sum);
            }
        }
    }

    cout << ret << endl;

    return 0;
}