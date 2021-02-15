#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fence(int left, int right);
vector<int> stick;

int main(){
    int c;
    cin >> c;
    vector<int> result;
    while(c--){
        int n;
        cin >> n;
        stick.clear();

        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            stick.push_back(temp);
        }
        result.push_back(fence(0, n-1));
    }
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}

int fence(int left, int right){
    if(left>=right){
        return stick[left];
    }

    int mid = (left+right)/2;
    int res = max(fence(left, mid), fence(mid+1, right));
    
    int oL = mid;
    int oR = mid+1;
    int minH = min(stick[oL], stick[oR]);
    res = max(res, minH * 2);

    while(oL > left || oR < right){
        if(oR < right && (oL == left || stick[oL-1] < stick[oR+1])){
            minH = min(minH, stick[++oR]);
        }
        else{
            minH = min(minH, stick[--oL]);
        }
        res = max(res, minH * (oR-oL+1));
    }

    return res;

}