#include<iostream>

using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        if(a == 1) continue;
        if(a == 2){
            sum++;
        }else{
            int j;
            for(j=2; j<a; j++){
                if(a % j == 0){
                    break;
                }
            }
            if(j == a) sum++;
        }
    }
    cout << sum << endl;
    return 0;
}