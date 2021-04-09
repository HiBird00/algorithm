#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;


vector<int> ret;

int main() {
    string s;
    cin >> s;
    int cnt=0;
    
    // string을 숫자, 연산자 구분해서 벡터로 저장
    vector<string> token;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '-' || s[i] == '+'){
            token.push_back(s.substr(cnt, i-cnt));
            string temp;
            temp = s[i];
            token.push_back(temp);
            cnt = i+1;
        }
    }
    token.push_back(s.substr(cnt, s.length()));

    // -를 기준으로 먼저 더해야할 부분을 선별
    // 선별 후, 먼저 더해야 할 것을 미리 더해서 ret에 차례로 넣어준다.
    vector<int> ret;
    cnt = 0;
    for(int i=0; i<token.size(); i++){
        if(token[i] == "-"){
            int result = 0;
            for(int j = cnt; j < i; j+=2){
                result += stoi(token[j]);
            }
            ret.push_back(result);
            cnt = i+1;
        }
    }
    int result = 0;
    for(int j = cnt; j < token.size(); j+=2){
        result += stoi(token[j]);
    }
    ret.push_back(result);
   
    // 첫번째 원소에서 나머지를 차례로 다 뺀다
    int answer = ret[0];
    for(int i=1; i<ret.size(); i++){
        answer -= ret[i];
    }

    cout << answer << endl;

    return 0;
}