#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

void find_parent_dfs(int curr, int prev, vector<int> graph[], int parent[], bool check[]){
    check[curr] = true;
    parent[curr] = prev;
    for(auto adjacent: graph[curr]){
        if(!check[adjacent]){
            find_parent_dfs(adjacent, curr, graph, parent, check);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int i, u, v;
    cin >> N;
    vector<int> tree[N+1];
    int parent[N+1];
    bool check[N+1];
    memset(check, false, sizeof(bool)*(N+1));

    for(i=1;i<N;i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    find_parent_dfs(1, -1, tree, parent, check);

    for(i=2;i<=N;i++)
        cout << parent[i] << "\n";


    return 0;
}