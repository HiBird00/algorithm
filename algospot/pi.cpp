#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int cache[10001];
string number;
int INF = 987654321;

int levelCheck(int start, int last){
    string M = number.substr(start, last-start);
    //cout << M << endl;
    // level1
    bool sameNumber = true;
    for(int i=0; i<M.length()-1; i++){
        if(M[i] != M[i+1]){
            sameNumber = false;
            break;
        }
    }
    if(sameNumber) return 1;

    // level 5 and 2
    bool level5 = true;
    int d = M[1] - M[0];
    for(int i=0; i<M.length()-1; i++){
        if(M[i+1] != M[i]+d){
            level5 = false;
            break;
        }
    }
    if(level5){
        if(d == 1 || d == -1){
            return 2;
        }
        return 5;
    }

    // level 4
    bool level4 = true;
    for(int i=0; i<M.length(); i++){
       if(M[i] != M[i%2]){
           level4 = false;
           break;
       }
    }
    if(level4) return 4;

    return 10;
}

int solve(int start){
    if(start == number.length()){
        return 0;
    }

    int& ret = cache[start];
    if(ret != -1){
        return ret;
    }
    ret = INF;

    for(int next = start+3; next<start+6; next++){
        if(next <= number.length()){
            ret = min(ret, levelCheck(start, next)+solve(next));
        }
    }

    return ret;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        memset(cache, -1, sizeof(cache));
        cin >> number;
        cout << solve(0) << endl;
    }  
    return 0; 

}
