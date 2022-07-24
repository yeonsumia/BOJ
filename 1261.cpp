#include<iostream>
#include<deque>

using namespace std;

int N, M;
char maze[100][100];
int wall[100][100];
bool visit[100][100];
int px[4] = {1,0,-1,0};
int py[4] = {0,1,0,-1};

void bfs_wall(){
    deque<pair<int,int>> q;
    q.emplace_back(0,0);
    wall[0][0] = maze[0][0] - '0';
    visit[0][0] = true;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop_front();
        for(int i=0;i<4;i++){
            int next_a = a + px[i];
            int next_b = b + py[i];
            if(next_a < 0 || next_a >= N) continue;
            if(next_b < 0 || next_b >= M) continue;
            if(visit[next_a][next_b]) continue;
            visit[next_a][next_b] = true;
            if(wall[next_a][next_b] > wall[a][b] + maze[next_a][next_b] - '0')
                wall[next_a][next_b] = wall[a][b] + maze[next_a][next_b] - '0';
            if(maze[next_a][next_b] == '0')
                q.emplace_front(next_a, next_b);
            else q.emplace_back(next_a, next_b);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    cin >> M >> N;

    for(i=0;i<N;i++) for(j=0;j<M;j++) cin >> maze[i][j];
    for(i=0;i<N;i++) for(j=0;j<M;j++) wall[i][j] = 1e9;

    bfs_wall();
    cout << wall[N-1][M-1];

    return 0;
}