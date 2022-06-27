#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs(int start, vector<int> graph[], bool check[]) {
    stack<int> s;
    check[start] = true;
    s.push(start);

    while(!s.empty()){
        int current_node = s.top();
        vector<int> adjacent_nodes = graph[current_node];
        s.pop();
        for(int& adjacent_node : adjacent_nodes){
            if(!check[adjacent_node]){
                s.push(current_node);
                check[adjacent_node] = true;
                s.push(adjacent_node);
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    int i, x;
    cin >> T;
    int count_graph;

    while(T--){
        // input graph size
        cin >> N;
        vector<int> graph[N+1];
        bool check[N+1];
        // initialization for each test case
        fill(check,check+N+1,false);
        count_graph = 0;
        for(i=1;i<=N;i++){
            cin >> x;
            graph[i].push_back(x);
        }
        // count number of sub-graphs
        for(i=1;i<=N;i++){
            if(!check[i]){
                dfs(i,graph,check);
                count_graph++;
            }
        }
        cout << count_graph << "\n";
    }

    return 0;
}