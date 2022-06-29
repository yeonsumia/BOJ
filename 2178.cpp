#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int pr[4] = {1,0,-1,0};
int pc[4] = {0,1,0,-1};

bool inference(int inf_pos_r, int inf_pos_c, const int* pos, bool* check, int N, int M){
    if(inf_pos_r < 0 || inf_pos_r >= N || inf_pos_c < 0 || inf_pos_c >= M) return false;
    if(*(pos+inf_pos_r*M+inf_pos_c) == 0) return false;
    if(*(check+inf_pos_r*M+inf_pos_c)) return false;

    // visit
    *(check+inf_pos_r*M+inf_pos_c) = true;

    return true;
}

void bfs(pair<int,int> start_pos, int* pos, bool* check, int* depth, int N, int M){
    int start_pos_r = start_pos.first;
    int start_pos_c = start_pos.second;

    queue<pair<int,int>> q;
    q.push(start_pos);
    *(check+start_pos_r*M+start_pos_c) = true;

    while(!q.empty()){
        pair<int,int> current_node = q.front();
        q.pop();

        int pos_r = current_node.first;
        int pos_c = current_node.second;

        for(int i=0;i<4;i++){
            int inf_pos_r = pos_r + pr[i];
            int inf_pos_c = pos_c + pc[i];

            if(inference(inf_pos_r, inf_pos_c, pos, check, N, M)){
                *(depth+inf_pos_r*M+inf_pos_c) = *(depth+pos_r*M+pos_c) + 1;
                q.emplace(inf_pos_r, inf_pos_c);
            }

        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int i, j;
    string s;
    cin >> N >> M;
    cin.ignore();

    int maze[N][M];
    int depth[N][M];
    bool check[N][M];
    // initialization
    for(i=0;i<N;i++)
        memset(depth[i], 0, sizeof(int)*M);
    for(i=0;i<N;i++)
        memset(check[i], false, sizeof(bool)*M);

    // input
    for(i=0;i<N;i++){
        getline(cin, s);
        for(j=0;j<M;j++){
            maze[i][j] = s[j] - '0';
        }
    }

    // go through the maze using bfs
    bfs(pair<int,int>(0,0), (int*) maze, (bool*) check, (int*) depth, N, M);

    cout << depth[N-1][M-1] + 1 << "\n";

    return 0;
}