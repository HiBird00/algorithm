#include<iostream>

using namespace std;

// 소수 : 0
int arr[1000001]={0,};
int M, N;

int main() {
    scanf("%d %d", &M, &N);
    arr[1] = 1;

    for(int i=2; i*i<=N; i++){
        if(!arr[i]){
            for(int j=i*i; j <=N; j+=i){
                arr[j] = true; // 소수 아닌 수 : 1
            }
        }
    }
    for(int i=M; i<=N; i++){
        if(!arr[i]){
            printf("%d\n", i);
        }
    }
    
    return 0;
}