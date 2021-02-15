#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int cache[10003] = {0,};
int drink[10003] = {0,};

int main() {
    int n;
    cin >> n;
      
    for(int i=3; i<n+3; i++){
        cin >> drink[i];
    }

    for(int i=3; i<n+3; i++){
        cache[i] = max(drink[i] + drink[i-1] + cache[i-3], drink[i] + cache[i-2]); // 2, 1번 연속
        cache[i] = max(cache[i], cache[i-1]); // 0번 연속 (n번째꺼를 안마신다는 것은 이전 cache와 동일함)
    }

    cout << cache[n+2] << endl;

    return 0;
}