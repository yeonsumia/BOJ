#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

pair<int,int> get_distance_bfs(int start, vector<pair<int,int>> tree[], bool check[], int V){
    int i, diameter = -1, end;
    int distance[V+1];
    memset(distance, 0, sizeof(int)*(V+1));

    queue<int> q;
    q.push(start);
    check[start] = true;

    // bfs - calculate distances from start node
    int current, next;
    while(!q.empty()){
        current = q.front();
        q.pop();
        for(i=0;i<tree[current].size();i++){
            next = tree[current][i].first;
            if(!check[next]){
                int d = tree[current][i].second;
                check[next] = true;
                distance[next] = distance[current] + d;
                q.push(next);
            }
        }
    }

    // find the longest distance and end node from start node
    for(i=1;i<=V;i++){
        if(distance[i] > diameter){
            diameter = distance[i];
            end = i;
        }
    }
    return {diameter, end};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, diameter;
    int i, u, v, d;
    cin >> V;

    vector<pair<int,int>> tree[V+1];
    bool check[V+1];

    for(i=0;i<V;i++){
        cin >> u >> v;
        while(v != -1){
            cin >> d;
            tree[u].emplace_back(v,d);
            cin >> v;
        }
    }

    // find the farthest node from any node(1)
    int node;
    memset(check, false, sizeof(bool)*(V+1));
    node = get_distance_bfs(1, tree, check, V).second;

    // find diameter of the tree
    memset(check, false, sizeof(bool)*(V+1));
    diameter = get_distance_bfs(node, tree, check, V).first;

    cout << diameter << "\n";

    return 0;
}