#include<iostream>

using namespace std;

int R, C;
char board[20][20];
bool visit[20][20];
bool alphabet[26];
int px[4] = {1,0,-1,0};
int py[4] = {0,1,0,-1};
int max_length;

bool dfs_2d_backtracking(int curr_i, int curr_j, int length){
    max_length = max_length >= length ? max_length : length;
    visit[curr_i][curr_j] = true;
    alphabet[board[curr_i][curr_j]-'A'] = true;
    bool no_way = true;
    for(int i=0;i<4;i++){
        int next_i = curr_i + px[i];
        int next_j = curr_j + py[i];
        if(next_i < 0 || next_i >= R) continue;
        if(next_j < 0 || next_j >= C) continue;
        if(alphabet[board[next_i][next_j]-'A']) continue;
        if(visit[next_i][next_j]) continue;
        no_way = false;
        if(!dfs_2d_backtracking(next_i, next_j, length + 1))
            visit[next_i][next_j] = false;
    }
    visit[curr_i][curr_j] = false;
    alphabet[board[curr_i][curr_j]-'A'] = false;
    return !no_way;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;

    cin >> R >> C;
    for(i=0;i<R;i++) for(j=0;j<C;j++) cin >> board[i][j];

    dfs_2d_backtracking(0, 0, 1);

    cout << max_length;

    return 0;
}