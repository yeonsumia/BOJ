#include<iostream>
#include<queue>

using namespace std;

vector<pair<int,int>> v;
int sudoku[9][9];

bool check_valid(int idx, int value){
    int i, j;
    pair<int,int> pos = v[idx];
    for(i=0;i<9;i++) if(sudoku[i][pos.second] == value) return false;

    for(j=0;j<9;j++) if(sudoku[pos.first][j] == value) return false;

    int pos_r = 3*(pos.first/3);
    int pos_c = 3*(pos.second/3);
    for(i=pos_r;i<pos_r+3;i++) for(j=pos_c;j<pos_c+3;j++) if(sudoku[i][j] == value) return false;

    return true;
}

bool fill_sudoku_backtracking(int idx){
    if(idx == v.size()) return true;
    pair<int,int> pos = v[idx];
    for(int i=1;i<=9;i++){
        if(check_valid(idx, i)){
            sudoku[pos.first][pos.second] = i;
            if(!fill_sudoku_backtracking(idx + 1)) sudoku[pos.first][pos.second] = 0;
        }
    }
    return sudoku[pos.first][pos.second] != 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0) v.emplace_back(i, j);
        }
    }

    // returns true if the following sudoku problem is well-defined
    fill_sudoku_backtracking(0);

    for(i=0;i<9;i++){
        for (j=0;j<9;j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}