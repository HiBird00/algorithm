#include<iostream>

using namespace std;

int main() {
    int t = 0;
    while(1) {
        t++;
        int L, P, V;
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0)
            return 0;
        
        int sum = (V/P) * L;
        int left = V % P;
        if(left <= L){
            sum += left;
        }else {
            sum += left;
        }
        cout << "Case " << t << ": " << sum << endl;
    }
    return 0;
}