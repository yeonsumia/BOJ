#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int count_mem = 0;
int count_group = 0;

void count_sub_graph_dfs(int start_r, int start_c, int* map, bool* check, int N) {
    if(start_r < 0 || start_r >= N || start_c < 0 || start_c >= N) return;
    if(*(map + start_r * N + start_c) == 0) return;
    if(*(check + start_r * N + start_c)) return;
    *(check + start_r * N + start_c) = true;
    count_mem++;
    count_sub_graph_dfs(start_r-1, start_c, map, check, N);
    count_sub_graph_dfs(start_r,start_c+1, map, check, N);
    count_sub_graph_dfs(start_r+1, start_c, map, check, N);
    count_sub_graph_dfs(start_r,start_c-1, map, check, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i, j;
    string s;
    vector<int> count_members;
    cin >> N;
    cin.ignore();
    int map[N][N];
    bool check[N][N];
    for(i=0;i<N;i++)
        memset(check[i], false, sizeof(bool)*N);
    for(i=0;i<N;i++){
        getline(cin, s);
        for(j=0;j<N;j++)
            map[i][j] = s[j] - '0';
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(map[i][j] == 1 && !check[i][j]){
                count_sub_graph_dfs(i,j,(int*)map,(bool*)check,N);
                count_group++;
                count_members.push_back(count_mem);
                count_mem = 0;
            }
        }
    }

    cout << count_group << "\n";
    sort(count_members.begin(),count_members.end());
    for(i=0;i<count_members.size();i++)
        cout << count_members[i] << "\n";

    return 0;
}