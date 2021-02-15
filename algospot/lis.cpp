#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int cache[501];
int number[501];
int n;

int lis(int start);

int main(){
    int c;
    cin >> c;
    while(c--){
        cin >> n;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<n; i++){
            cin >> number[i];
        }
        
        cout << lis(-1)-1 << endl;
    }
    

    return 0;
}

int lis(int start){
    int& ret = cache[start+1];
    
    if(ret != -1){
        return ret;
    }

    ret = 1;
    for(int next = start+1; next<n; next++){
        if(start == -1 || number[start] < number[next]){
            ret = max(ret, lis(next)+1);
        }
    }
    return ret;

}