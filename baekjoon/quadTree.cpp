#include <iostream>

using namespace std;

char video[64][64];

char equal(int ff, int fl, int lf, int ll) {
    char s = video[ff][lf];
    for(int i=ff; i<fl; i++){
        for(int j=lf; j<ll; j++){
            if(s != video[i][j]) return 'q';
        }
    }
    return s;
}

void solve(int ff, int fl, int lf, int ll) {
    if(ff == fl) return;

    char eq = equal(ff, fl, lf, ll);
    if(eq != 'q'){cout << eq; return;};

    cout << "(";
    int fmid = (ff+fl) / 2;
    int lmid = (lf+ll) / 2;

    solve(ff, fmid, lf, lmid);
    solve(ff, fmid, lmid, ll);
    solve(fmid, fl, lf, lmid);
    solve(fmid, fl, lmid, ll);
    
    cout << ")";    
}

int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> video[i][j];
        }
    }
    
    solve(0,n,0,n);

    return 0;
}