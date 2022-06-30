#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

pair<int,int> get_distance_dfs(int current, int distance, vector<pair<int,int>> tree[], bool check[]){
    int max_distance = 0, next;
    check[current] = true;
    for(auto p: tree[current]){
        if(!check[p.first]){
            pair<int,int> next_dfs = get_distance_dfs(p.first, distance + p.second, tree, check);
            int d = next_dfs.second;
            if(d > max_distance) {
                max_distance = d;
                next = next_dfs.first;
            }
        }
    }
    if(max_distance == 0) return {current, distance};
    else return {next, max_distance};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int i, u, v, d;
    cin >> n;
    vector<pair<int,int>> tree[n+1];
    bool check[n+1];

    for(i=0;i<n-1;i++){
        cin >> u >> v >> d;
        tree[u].emplace_back(v,d);
        tree[v].emplace_back(u,d);
    }

    // find the farthest node from any node(1)
    memset(check, false, sizeof(bool)*(n+1));
    pair<int,int> find_farthest_dfs = get_distance_dfs(1, 0, tree, check);

    // find diameter of the tree
    memset(check, false, sizeof(bool)*(n+1));
    cout << get_distance_dfs(find_farthest_dfs.first, 0, tree, check).second << "\n";

    return 0;
}