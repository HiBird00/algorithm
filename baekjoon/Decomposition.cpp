#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int i;
    for(i=1; i<n; i++){
        int num = i;
        int sum = i;
        while(num / 10 != 0){
            sum += num % 10;
            num = num / 10;
        }
        sum += num % 10;
        if(sum == n) break;
    }
    if(i == n){
        cout << 0 << endl;
    }else{
        cout << i << endl;
    }
    

    return 0;
}