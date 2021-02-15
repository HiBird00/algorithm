#include<iostream>
#include<string.h>

using namespace std;

int cache[2][41];

int fibonacci(int n, int sub){
    if(n == sub) return 1;

    if(n+sub == 1) return 0;

    int &ret = cache[sub][n];
    if(ret != -1) return ret;

    ret = fibonacci(n-1, sub) + fibonacci(n-2, sub);

    return ret;
        
}
int main(){
    int c;
    cin >> c;
    memset(cache, -1, sizeof(cache));
    while(c--){
        int n;
        cin >> n;

        cout << fibonacci(n, 0) << " " << fibonacci(n, 1) << endl;
    }
    return 0;
}
