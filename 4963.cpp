#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

void count_sub_graph_dfs(int start_r, int start_c, int* map, bool* check, int h, int w) {
    if(start_r < 0 || start_r >= h || start_c < 0 || start_c >= w) return;
    if(*(map + start_r * w + start_c) == 0) return;
    if(*(check + start_r * w + start_c)) return;
    *(check + start_r * w + start_c) = true;

    // up, down, left, right
    count_sub_graph_dfs(start_r-1, start_c, map, check, h, w);
    count_sub_graph_dfs(start_r,start_c+1, map, check, h, w);
    count_sub_graph_dfs(start_r+1, start_c, map, check, h, w);
    count_sub_graph_dfs(start_r,start_c-1, map, check, h, w);
    // cross-directions
    count_sub_graph_dfs(start_r-1, start_c-1, map, check, h, w);
    count_sub_graph_dfs(start_r-1, start_c+1, map, check, h, w);
    count_sub_graph_dfs(start_r+1, start_c-1, map, check, h, w);
    count_sub_graph_dfs(start_r+1, start_c+1, map, check, h, w);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h;
    int i, j;
    int count_islands = 0;
    cin >> w >> h;

    do {
        count_islands = 0;
        int map[h][w];
        bool check[h][w];
        for(i=0;i<h;i++)
            memset(check[i], false, sizeof(bool)*w);

        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                cin >> map[i][j];
            }
        }

        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                if(map[i][j] == 1 && !check[i][j]){
                    count_sub_graph_dfs(i,j,(int*)map,(bool*)check,h,w);
                    count_islands++;
                }
            }
        }
        cout << count_islands << "\n";

        cin >> w >> h;
    } while(w != 0 || h != 0);

    return 0;
}