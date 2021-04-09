#include<iostream>
#include<vector>

using namespace std;

int board[9][9] = {0,};
vector<pair<int, int>> zeroIdx;

bool check(int row, int col) {
    bool Rvisited[10] = {0,};
    bool Cvisited[10] = {0,};
    for(int i=0; i<9; i++){
        if(board[row][i] != 0 && Rvisited[board[row][i]]) return false; 
        if(board[i][col] != 0 && Cvisited[board[i][col]]) return false;
        Rvisited[board[row][i]] = Cvisited[board[i][col]] = true;
    }
    // 3*3
    bool Tvisited[10] = {0,};
    for(int i=row-(row%3); i<row-(row%3)+3; i++){
        for(int j=col-(col%3); j<col-(col%3)+3; j++){
            if(board[i][j] != 0 && Tvisited[board[i][j]]) return false;
            Tvisited[board[i][j]] = true;
        }
    }
    return true;
}

int solve(int idx) {
    if(idx == zeroIdx.size()) return -1;

    int row = zeroIdx[idx].first;
    int col = zeroIdx[idx].second;

    for(int i=1; i<=9; i++){
        board[row][col] = i;
        if(check(row, col)){
           if(solve(idx+1) == -1) return -1;
        }
        board[row][col] = 0;
    }

    return 1;
}

int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) zeroIdx.push_back(make_pair(i,j));
        }
    }

    solve(0);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}