#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main() {
    int n, arr[26]={0,};
    cin >> n;
    for(int i=0; i<n ;i++){
        string str;
        cin >> str;
        for(int j=0; j<str.length(); j++){
            arr[int(str[j])-65] += pow(10, str.length()-j-1);
        }
    }
    
    sort(arr, arr+26, comp);
    int ret = 0;
    int num = 9;
    for(int i=0; i<26; i++){
        if(arr[i] == 0) break;
        ret += num * arr[i];
        num--;
    }
    cout << ret << endl;

    return 0;
}