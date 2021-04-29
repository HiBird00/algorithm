#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        pq.push(num);
    }

    int ret = 0;
    while(pq.size() != 1){
        int a = pq.top(); 
        pq.pop();
        int b = pq.top(); 
        pq.pop();
        pq.push(a+b);
        ret += a+b; 
    }
    cout << ret << endl;

    return 0;
}