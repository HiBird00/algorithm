#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int score[300];
int cache[300];
int n;

int solve(int floor) {
    if(floor < 0) return 0;
    if(floor == 0) return score[0];

    int &ret = cache[floor];
    if(ret != -1) return ret;

    ret = max(ret, solve(floor-2)+score[floor]);
    ret = max(ret, solve(floor-3) + score[floor] + score[floor-1]);

    return ret;
}

int main() {
    cin >> n;
    memset(cache, -1, sizeof(cache));

    for(int i=0; i<n ;i++){
        cin >> score[i];
    }

    cout << solve(n-1) << endl;;


    return 0;
}