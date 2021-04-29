#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    int sum = 0;
    int mini = INT_MAX;
    for (int i = M; i <= N; i++)
    {
        if(i == 1) continue;
        
        int j;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if(j == i){
            sum += i;
            mini = min(mini, i);
        }
    }

    if (sum == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << sum << endl;
    cout << mini << endl;
    return 0;
}