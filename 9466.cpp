#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long count_cycle_mem_dfs(int start, const int graph[], int check[]) {
    int current_node = start, adjacent_node = graph[start];
    check[current_node] = start;
    vector<int> v;
    v.push_back(current_node);

    while(check[adjacent_node] == 0){
        current_node = adjacent_node;
        v.push_back(current_node);
        check[current_node] = start;
        adjacent_node = graph[current_node];
    }
    // find a cycle
    if(check[adjacent_node] == start){
        return v.end() - find(v.begin(),v.end(),adjacent_node);
    }
    // find already found cycle
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    long count, N;
    cin >> T;

    while(T--){
        cin >> N;
        count = N;
        int graph[N+1];
        // history[]
        // 0: unvisited
        // >0: start node
        int history[N + 1];
        fill(history, history + N + 1, 0);
        // build graph
        for(int i=1;i<=N;i++) cin >> graph[i];
        // find cycles starting from unvisited nodes
        for(int i=1;i<=N;i++) if(history[i] == 0) count -= count_cycle_mem_dfs(i, graph, history);

        cout << count << "\n";
    }

    return 0;
}