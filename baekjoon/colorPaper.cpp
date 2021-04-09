#include<iostream>
#include<vector>

using namespace std;

int paper[128][128];
vector<int> result;

int equl(int f_f, int f_l, int l_f, int l_l){
    int s = paper[f_f][l_f];
    for(int i=f_f; i<f_l; i++){
        for(int j=l_f; j<l_l; j++){
            if(s != paper[i][j]) return -1;
        }
    }
    return s;
}

int solve(int f_f, int f_l, int l_f, int l_l){
    if(f_l == f_f) return -1;

    int eq = equl(f_f, f_l, l_f, l_l);
    if(eq != -1) return eq;

    int f_mid = (f_f+f_l) / 2;
    int l_mid = (l_f+l_l) / 2;

    result.push_back(solve(f_f, f_mid, l_f, l_mid));
    result.push_back(solve(f_mid, f_l, l_f, l_mid));
    result.push_back(solve(f_f, f_mid, l_mid, l_l));
    result.push_back(solve(f_mid, f_l, l_mid, l_l));
    
    return -1;
}

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> paper[i][j];
        }
    }

    solve(0,n,0,n);
    
    int w=0, b=0;
    for(int i=0; i<result.size(); i++){
        if(result[i] == 0) w++;
        if(result[i] == 1) b++;
    }

    cout << w << endl;
    cout << b << endl;

    return 0;    
}