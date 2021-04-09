#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

vector<int> height;

int solve(int left, int right) {
    if(left >= right) return height[left];

    int mid = (left+right)/2;
    int res = max(solve(left, mid), solve(mid+1, right));

    int oL = mid; int oR = mid+1;
    int minH = min(height[oL], height[oR]);
    res = max(res, minH * 2);

    while(oL > left || oR < right){
        if(oR < right || (oL == left) || height[oL-1] < height[oR+1]){
            minH = min(minH, height[++oR]);
        }else{
            minH = min(minH, height[--oL]);
        }
        res = max(res, minH*(oR-oL+1));
    }
    return res;
}

int main() {
    fastio;
    while(1){
        height.clear();
        int n;
        cin >> n;
        if(n == 0) break;
        
        for(int i=0; i<n; i++){
            int h;
            cin >> h;
            height.push_back(h);
        }

        cout << solve(0, height.size()-1) << endl;;
    }

    return 0;
}