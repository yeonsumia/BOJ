#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool check_bipartite_graph_bfs(int start, vector<int> graph[], int check[]){
    queue<int> q;
    q.push(start);
    check[start] = 1;
    int current_node;
    while(!q.empty()){
        current_node = q.front();
        q.pop();
        for(int adjacent_node : graph[current_node]){
            // bfs - unvisited
            if(check[adjacent_node] == 0){
                check[adjacent_node] = -check[current_node];
                q.push(adjacent_node);
            }
            // filtering non-bipartite graph
            else if(check[adjacent_node] == check[current_node]) return false;
        }
    }
    return true;
}

int main(){
    int K, V, E;
    int u, v, i;
    cin >> K;

    while(K--){
        cin >> V >> E;
        vector<int> graph[V+1];
        int check[V+1];
        fill(check,check+V+1,0);
        // build graph
        for(i=0;i<E;i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // check whether each sub-graph is bipartite graph or not
        // a graph is bipartite graph if and only if all of sub-graphs are bipartite graph
        for(i=1;i<=V;i++){
            // bfs - unvisited
            if(check[i] == 0){
                if (!check_bipartite_graph_bfs(i,graph,check)) {
                    cout << "NO\n";
                    break;
                }
            }
        }
        if(i==V+1) cout << "YES\n";
    }
}
