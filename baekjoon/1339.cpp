#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

bool comp(pair<char, int> a, pair<char, int> b){
    return a.second > b.second;
}
bool comp2(pair<char, int> a, pair<char, int> b){
    return a.first < b.first;
}

int main() {
    int n;
    pair<char, int> arr[26];
    for(int i=0; i<26; i++){
        arr[i] = make_pair(char(i+65), -1);
    }

    cin >> n;
    string strArr[10];
    for(int i=0; i<n; i++){
        cin >> strArr[i];
        string temp = strArr[i];
        for(int j=0; j<temp.length(); j++){
            arr[int(temp[j])-65].second = max(arr[int(temp[j])-65].second, (int)temp.length()-j);
        }
    }

    sort(arr, arr+26, comp);
    int num = 9;
    for(int i=0; i<26; i++){
        if(arr[i].second == -1) break;
        arr[i].second = num;
        num--;
    }
    sort(arr, arr+26, comp2);

    long long ret = 0;
    for(int i=0; i<n; i++){
        string temp = strArr[i];
        for(int j=0; j<temp.length(); j++){
            ret += arr[int(temp[j])-65].second * round(pow(10, temp.length()-j-1));
        }
    }
    cout << ret << endl;

    
    return 0;
}