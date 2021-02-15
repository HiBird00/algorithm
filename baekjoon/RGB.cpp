#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int cache[3];;
int color[1000][3];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }
    // 첫 번째
    memcpy(cache, color[0], sizeof(cache));
    
    for(int i=1; i<n; i++){
        int temp[3];
        temp[0] = min(cache[1]+color[i][0], cache[2]+color[i][0]); // R
        temp[1] = min(cache[0]+color[i][1], cache[2]+color[i][1]); // G
        temp[2] = min(cache[0]+color[i][2], cache[1]+color[i][2]); // B
        memcpy(cache, temp, sizeof(cache));
    }
    int mini = 987654321;
    for(int i=0; i<3; i++){
        mini = min(mini, cache[i]);
    }
    cout << mini << endl;
    return 0;
}