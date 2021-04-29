#include<iostream>
#include<queue>

using namespace std;

// 1. 0과 양수는 곱하지 않는다.
// 2. 0과 음수는 곱한다.
// 3. 양수는 양수끼리, 음수는 음수끼리 곱한다.
// 4. 양수 중 큰 애들끼리 곱한다.
// 5. 음수 중 절대값이 큰 애들끼리 곱한다.
// 6. 1은 그냥 더하는게 크다

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>> p_pq;
    priority_queue<int, vector<int>, greater<int>> n_pq;
    bool zero = false;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(num == 0){
            zero = true;
        }else if(num > 0){
            p_pq.push(num);
        }else{
            n_pq.push(num);
        }
    }

    int ret = 0;
    while(p_pq.size() > 1){
        int a = p_pq.top(); p_pq.pop();
        int b = p_pq.top(); p_pq.pop();
        if(a == 1 || b == 1){
            ret += a + b;
            continue;
        }
        ret += a * b;
    }

    while(n_pq.size() > 1){
        int a = n_pq.top(); n_pq.pop();
        int b = n_pq.top(); n_pq.pop();
        ret += a * b;
    }
    if(p_pq.size() == 1) ret += p_pq.top();
    if(!zero && n_pq.size() == 1) ret += n_pq.top();

    cout << ret << endl;
    return 0;   

}