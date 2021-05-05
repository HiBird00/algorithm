#include<iostream>

using namespace std;

int main() {
    int N, j, h;
    int round = 0;
    cin >> N >> j >> h;
    
    while(N) {
        j = (j+1)/2; h = (h+1)/2;
        if(j == h){
            round++;
            break;
        }

        round++;
        N /= 2;
    }

    cout << round << endl;

    return 0;
}