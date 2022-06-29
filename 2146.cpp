#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int pr[4] = {1,0,-1,0};
int pc[4] = {0,1,0,-1};

int inference(int inf_pos_r, int inf_pos_c, const int* pos, bool* visit, const bool* current_island, int N){
    if(inf_pos_r < 0 || inf_pos_r >= N || inf_pos_c < 0 || inf_pos_c >= N) return 0;
    if(*(current_island + inf_pos_r * N + inf_pos_c)) return 0;
    if(*(pos+inf_pos_r*N+inf_pos_c) == 1) return -1;
    if(*(visit + inf_pos_r * N + inf_pos_c)) return 0;

    // visit
    *(visit + inf_pos_r * N + inf_pos_c) = true;

    return 1;
}

bool make_bridge(int inf_pos_r, int inf_pos_c, const int* pos, bool* visit, bool* current_island, int N){
    if(inf_pos_r < 0 || inf_pos_r >= N || inf_pos_c < 0 || inf_pos_c >= N) return false;
    if(*(pos+inf_pos_r*N+inf_pos_c) == 0) return false;
    if(*(visit + inf_pos_r * N + inf_pos_c)) return false;

    // visit
    *(visit + inf_pos_r * N + inf_pos_c) = true;
    *(current_island+inf_pos_r*N+inf_pos_c) = true;
    return true;
}

vector<pair<int,int>> visit_island_bfs(pair<int,int> start_pos, int* pos, bool* visit, bool* current_island, int N){
    vector<pair<int,int>> visit_area;
    int start_pos_r = start_pos.first;
    int start_pos_c = start_pos.second;

    queue<pair<int,int>> q;
    q.push(start_pos);
    visit_area.push_back(start_pos);
    *(visit + start_pos_r * N + start_pos_c) = true;
    *(current_island + start_pos_r * N + start_pos_c) = true;
    while(!q.empty()){
        pair<int,int> current_node = q.front();
        q.pop();

        int pos_r = current_node.first;
        int pos_c = current_node.second;

        for(int i=0;i<4;i++){
            int inf_pos_r = pos_r + pr[i];
            int inf_pos_c = pos_c + pc[i];

            if(make_bridge(inf_pos_r, inf_pos_c, pos, visit, current_island, N)){
                q.emplace(inf_pos_r, inf_pos_c);
                visit_area.emplace_back(inf_pos_r,inf_pos_c);
            }
        }
    }

    return visit_area;
}

int get_bridge_from_current_island_bfs(pair<int,int> start_pos, int* pos, bool* visit, int* depth, int N){
    int i, j;
    int bridge_length;
    bool current_island[N][N];
    for(i=0;i<N;i++)
        memset(current_island[i], false, sizeof(bool)*N);
    vector<pair<int,int>> visit_area = visit_island_bfs(start_pos, pos, visit, (bool*) current_island, N);
    vector<int> bridge_lengths;

    for(auto island_pos: visit_area){
        queue<pair<int,int>> q;
        bridge_length = 0;
        for(i=0;i<N;i++) for(j=0;j<N;j++) *(depth+i*N+j) = 0;
        for(i=0;i<N;i++) for(j=0;j<N;j++) if(*(pos+i*N+j) == 0) *(visit + i * N + j) = false;

        q.push(island_pos);

        while(!q.empty()){
            pair<int,int> current_node = q.front();
            q.pop();

            int pos_r = current_node.first;
            int pos_c = current_node.second;
            int inference_type;
            for(i=0;i<4;i++){
                int inf_pos_r = pos_r + pr[i];
                int inf_pos_c = pos_c + pc[i];
                inference_type = inference(inf_pos_r, inf_pos_c, pos, visit, (bool*) current_island, N);
                if(inference_type == 1){
                    *(depth+inf_pos_r*N+inf_pos_c) = *(depth+pos_r*N+pos_c) + 1;
                    q.emplace(inf_pos_r, inf_pos_c);
                }
                else if(inference_type == -1) {
                    bridge_length = *(depth+pos_r*N+pos_c);
                    break;
                }
            }
            if(inference_type == -1) break;
        }

        if(bridge_length != 0)
            bridge_lengths.push_back(bridge_length);
    }

    return *min_element(bridge_lengths.begin(), bridge_lengths.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int i, j;
    cin >> N;

    int map[N][N];
    int depth[N][N];
    bool visit[N][N];
    vector<int> bridge_lengths;
    for(i=0;i<N;i++) memset(visit[i], false, sizeof(bool) * N);

    for(i=0;i<N;i++) for(j=0;j<N;j++) cin >> map[i][j];

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(map[i][j] == 1 && !visit[i][j]){
                // initialize previous bfs histories

                int length = get_bridge_from_current_island_bfs(pair<int, int>(i, j), (int *) map, (bool *) visit,
                                                           (int *) depth, N);
                bridge_lengths.push_back(length);
            }
        }
    }

    cout << *min_element(bridge_lengths.begin(), bridge_lengths.end()) << "\n";

    return 0;
}