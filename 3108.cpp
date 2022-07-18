#include<iostream>

using namespace std;

int count_group;
bool point[2001][2001];
int px[4] = {1,0,-1,0};
int py[4] = {0,1,0,-1};

void dfs_logo(int curr_i, int curr_j){
    point[curr_i][curr_j] = false;
    for(int i=0;i<4;i++){
        int next_i = curr_i + px[i];
        int next_j = curr_j + py[i];
        if(next_i < 0 || next_i > 2000) continue;
        if(next_j < 0 || next_j > 2000) continue;
        if(!point[next_i][next_j]) continue;
        dfs_logo(next_i, next_j);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i, j;
    int x1, x2, y1, y2;
    cin >> N;

    for(i=0;i<N;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = (x1 + 500) * 2;
        y1 = (y1 + 500) * 2;
        x2 = (x2 + 500) * 2;
        y2 = (y2 + 500) * 2;
        for(j=x1;j<=x2;j++){
            point[j][y1] = true;
            point[j][y2] = true;
        }
        for(j=y1;j<=y2;j++){
            point[x1][j] = true;
            point[x2][j] = true;
        }
    }

    if(point[1000][1000]) dfs_logo(1000, 1000);

    for(i=0;i<2001;i++){
        for(j=0;j<2001;j++){
            if(point[i][j]){
                dfs_logo(i, j);
                count_group++;
            }
        }
    }

    cout << count_group;

    return 0;
}