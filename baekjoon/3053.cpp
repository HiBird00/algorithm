#include<iostream>

#define _USE_MATH_DEFINES
#include<math.h>

using namespace std;

int main() {
    int r;
    cin >> r;
    printf("%f\n" ,pow(r,2)*M_PI);
    printf("%f", 2*pow(r,2));
    return 0;
}