#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int px[4] = {0,1,0,-1};
int py[4] = {1,0,-1,0};

bool arranged(const string& puzzle){
    return puzzle == "123456780";
}

int bfs_puzzle(const string& puzzle){
    int pos, i, r, c, neighbor_r, neighbor_c;
    string prev_puzzle;
    queue<string> q;
    map<string, int> m;
    q.push(puzzle);
    m[puzzle] = 0;
    while(!q.empty()){
        prev_puzzle = q.front();
        if(arranged(prev_puzzle)) return m[prev_puzzle];
        pos = prev_puzzle.find('0');
        q.pop();
        for(i=0;i<4;i++){
            r = pos/3; c = pos%3;
            neighbor_r = r + px[i];
            neighbor_c = c + py[i];
            if(neighbor_r < 0 || neighbor_r >= 3) continue;
            if(neighbor_c < 0 || neighbor_c >= 3) continue;

            // allocate memory
            string curr_puzzle = prev_puzzle;

            // swap
            swap(curr_puzzle[3*neighbor_r+neighbor_c], curr_puzzle[pos]);

            if(m.count(curr_puzzle) == 0){
                q.push(curr_puzzle);
                // insert to the map with its depth
                m[curr_puzzle] = m[prev_puzzle] + 1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    int** puzzle = new int*[3];
    for(i=0;i<3;i++) puzzle[i] = new int[3];

    for(i=0;i<3;i++) for(j=0;j<3;j++) cin >> puzzle[i][j];

    string s;
    for(i=0;i<3;i++) for(j=0;j<3;j++) s += to_string(puzzle[i][j]);
    cout << bfs_puzzle(s);

    // free memory
    for(i=0;i<3;i++) delete[] puzzle[i];
    delete[] puzzle;

    return 0;
}