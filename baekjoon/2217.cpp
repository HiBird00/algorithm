#include<iostream>
#include<algorithm>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main() {
    int N, arr[100001], weight = 0;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1, comp);
    
    for(int i=1; i<=N; i++){
        weight = max(weight, arr[i]*i);
    }

    cout << weight << endl;
    return 0;
}