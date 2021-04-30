#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
    string str;
    cin >> str;
    stack<char> st;
    bool check = false;
    int tmp = 1;
    int ret = 0;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '('){
            tmp *= 2;
            st.push(str[i]);
        }else if(str[i] == '['){
            tmp *= 3;
            st.push(str[i]);
        }else if(str[i] == ')'){
            if(st.empty() || st.top() != '('){
                check = true;
                break;
            }
            if(str[i-1] == '(') ret += tmp;
            tmp /= 2;
            st.pop();
        }else if(str[i] == ']'){
            if(st.empty() || st.top() != '['){
                check = true;
                break;
            }
            if(str[i-1] == '[') ret += tmp;
            tmp /= 3;
            st.pop();
        }
    }
    if(check || !st.empty()){
        cout << 0 << endl;
    }else {
        cout << ret << endl;
    }

    return 0;
}