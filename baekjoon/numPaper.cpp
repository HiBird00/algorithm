#include <iostream>
#include <vector>

using namespace std;

int paper[2187][2187];
int ret[3] = {0,};

bool equal(int ff, int fl, int lf, int ll) {
    int s = paper[ff][lf];
    for(int i=ff; i<fl; i++){
        for(int j=lf; j<ll; j++){
            if(s != paper[i][j]) return false;
        }
    }
    return true;
}

void solve(int ff, int fl, int lf, int ll){
    if(equal(ff, fl, lf, ll)) { ret[paper[ff][lf]]++; return;}

    int dist = (fl-ff)/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
           solve(ff+(dist*i), ff+(dist*(i+1)), lf+(dist*j), lf+(dist*(j+1)));
        }
    }

}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> paper[i][j];
            paper[i][j]++;
        }
    }

    solve(0,n,0,n);

    for(int i=0; i<3; i++){
        cout << ret[i] << endl;
    }
    
    return 0;   
}