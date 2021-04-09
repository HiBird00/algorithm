#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    string a, b;
    int arr[10000]={0,}, brr[10000]={0,}, sum[10001]={0,};
    cin >> a >> b;

    for(int i=0; i<a.length(); i++){
        arr[i] = a[a.length()-1-i] - '0';
    }
    for(int i=0; i<b.length(); i++){
        brr[i] = b[b.length()-1-i] - '0';
    }
    
    int maxLen = max(a.length(), b.length());
    for(int i=0; i<maxLen; i++){
        int temp = arr[i] + brr[i];
        sum[i] += temp;
        if(sum[i] >= 10){
            sum[i+1]++;
            sum[i] %= 10;
        }
    }
    for(int i=maxLen; i>=0; i--){
        if(i == maxLen && sum[i] == 0) continue;
        cout << sum[i];
    }
    
    return 0;
}