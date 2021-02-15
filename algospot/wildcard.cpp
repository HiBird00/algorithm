#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int cache[101][101];
string wildcard;
string word;
vector<string> result;

int solve(int w, int s);

int main(){
    int c;
    cin >> c;
    while(c--){
        cin >> wildcard;
        int n;
        cin >> n;
        
        while(n--){
            cin >> word;
            memset(cache, -1, sizeof(cache));
            if(solve(0,0) == 1)
                result.push_back(word);
        }
        sort(result.begin(), result.end());
        for(int i=0; i<result.size(); i++){
            cout << result[i] << endl;
        }
    }
    
    
    return 0;
}

int solve(int w, int s){
    int& ret = cache[w][s];
    if(ret != -1){
        return ret;
    }

    //wildcard랑 word랑 한 칸씩 비교
    if(w < wildcard.length() && s<word.length() && (wildcard[w] == word[s] || wildcard[w] == '?')){
        return ret = solve(w+1, s+1);
    }
    //틀리다면
    //끝에 동시에 도달해서 끝나야함
    if(w == wildcard.length() && s == word.length()){
        return ret = 1;
    }
    // wildcard[w] == * 이라면?
    if(wildcard[w] == '*'){
        // wildcard는 그대로 *에 머물고, wildcard[w+1] == word[s+1] 인 경우 wildcard를 한 칸 넘겨준다.
        if(solve(w+1, s) || (s < word.length() && solve(w, s+1))){
           return ret = 1;
        }  
    }
    
   return ret = 0;
    
}