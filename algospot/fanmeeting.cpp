#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

string members, fans;

// void nomalize(vector<int>& c){
//     c.push_back(0);
//     for(int i=0; i<c.size()-1; i++){
//         if(c[i] < 0){
//             int borrow = (abs(c[i]) + 9) / 10;
//             c[i+1] -= borrow;
//             c[i] += borrow * 10;
//         }else{
//             c[i+1] += c[i]/10;
//             c[i] = c[i] % 10;
//         }
//     }
//     while( c.size() > 1 && c.back() == 0) c.pop_back();
// }

vector<int> multifly(vector<int>& A, vector<int> &B){
    vector<int> C(A.size()+B.size()+1, 0);

    for(int i=0; i<A.size(); i++){
        for(int j=0; j<B.size(); j++){
            C[i+j] += A[i] * B[j];
        }
    }

    //nomalize(C);
    return C;
}

void addTo(vector<int> &a, vector<int> &b, int k){
    a.resize(max(a.size(), b.size() + k));
    for(int i=0; i<b.size(); i++){
        a[i+k] += b[i];
    }
}
void subFrom(vector<int> &a, vector<int> &b){
    //a.resize(max(a.size(), b.size() + 1));
    for(int i=0; i<b.size(); i++){
        a[i] -= b[i];
    }
}

vector<int> karatsuba( vector<int> &A,  vector<int> &B){
    int an = A.size(), bn = B.size();
    if(an < bn) return karatsuba(B, A);
    if(an == 0 || bn == 0) return vector<int> ();
    if(an <= 50) return multifly(A, B);
    
    int half = an /2 ;
    vector<int>a0(A.begin(), A.begin()+half);
    vector<int>a1(A.begin()+half, A.end());
    vector<int>b0(B.begin(), B.begin()+min<int>(half, bn));
    vector<int>b1(B.begin()+min<int>(half, bn), B.end());

    vector<int>z2 = karatsuba(a1, b1);
    vector<int>z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0); addTo(b0, b1, 0);

    vector<int>z1 = karatsuba(a0, b0);
    
    subFrom(z1, z0); subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half * 2);
    
    return ret;
}

int hugs(string &members, string &fans){
    int M = members.size(), F = fans.size();
    vector<int> A(M), B(F);
    for(int i=0; i<M; i++) A[i] = (members[i] == 'M');
    for(int i=0; i<F; i++) B[F-i-1] = (fans[i] == 'M');

    vector<int> C = karatsuba(A, B);

    int hug = 0;
    for(int i=M-1; i<F; i++){
        if(C[i] == 0)
            hug++;
    }
    return hug;
}

int main(){
    fastio;

    int c;
    cin >> c;
    while(c--){
        cin >> members;
        cin >> fans;
        cout << hugs(members, fans) << endl;
    }
    return 0;
}
