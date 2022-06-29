#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int pr[4] = {1,0,-1,0};
int pc[4] = {0,1,0,-1};

bool inference(int pos_r, int pos_c, int* pos, int M, int N, queue<pair<int,int>>& q){
    if(pos_r < 0 || pos_r >= N || pos_c < 0 || pos_c >= M) return false;
    // avoid visiting empty positions
    if(*(pos+pos_r*M+pos_c) == -1) return false;
    // avoid visiting ripen tomatoes
    if(*(pos+pos_r*M+pos_c) == 1) return false;

    // visit unripe tomato
    *(pos+pos_r*M+pos_c) = 1;
    q.push(pair<int,int>(pos_r,pos_c));

    return true;
}

void inference_days_bfs(vector<pair<int,int>>& v, int* pos, int* depth, int M, int N){
    queue<pair<int,int>> q;
    for(auto p : v){
        int start_r = p.first;
        int start_c = p.second;

        if(start_r < 0 || start_r >= N || start_c < 0 || start_c >= M) return;
        q.push(pair<int,int>(start_r,start_c));
    }

    while(!q.empty()){
        pair<int,int> current_node = q.front();
        q.pop();

        int pos_r = current_node.first;
        int pos_c = current_node.second;

        // inference ripe
        for(int i=0;i<4;i++){
            int inf_pos_r = pos_r + pr[i];
            int inf_pos_c = pos_c + pc[i];

            if(inference(inf_pos_r,inf_pos_c,pos,M,N, q))
                *(depth+inf_pos_r*M+inf_pos_c) = *(depth+pos_r*M+pos_c) + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    int i, j;
    cin >> M >> N;

    int pos[N][M];
    int depth[N][M];
    // initialization
    for(i=0;i<N;i++)
        memset(depth[i], 0, sizeof(int)*M);
    // input positions
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            cin >> pos[i][j];
    // calculate inference days using bfs
    vector<pair<int,int>> start_pos;
    for(i=0;i<N;i++) for(j=0;j<M;j++) if(pos[i][j]==1) start_pos.emplace_back(i,j);

    inference_days_bfs(start_pos, (int *) pos, (int *) depth, M, N);

    int count_days = -1;

    for(i=0;i<N;i++) for(j=0;j<M;j++) if(depth[i][j] > count_days) count_days = depth[i][j];

    for(i=0;i<N;i++) for(j=0;j<M;j++) if(pos[i][j]==0) count_days = -1;

    cout << count_days << "\n";

    return 0;
}