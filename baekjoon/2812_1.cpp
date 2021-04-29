#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
    int n, k;
    string str;
    stack<char> st;
    cin >> n >> k >> str;
    
    for(int i=0; i<n; i++){
        while(!st.empty() && k && str[i] > st.top()){
            st.pop();
            k--;
        }
        st.push(str[i]);
    }
    while(k){
        st.pop();
        k--;
    }
    
    stack<char>temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }

     while(!temp.empty()){
        cout << temp.top();
        temp.pop();
    }

    return 0;
}