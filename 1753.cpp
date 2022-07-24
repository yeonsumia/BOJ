#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e9;
int V, E, K;

class adjacent{
public:
    int num;
    int cost;
    adjacent(int num, int cost){
        this->num = num;
        this->cost = cost;
    }
};

class node{
public:
    int num;
    int cost;
    int prev;
    vector<adjacent> neighbors;
    node(int num, int cost, int prev){
        this->num = num;
        this->cost = cost;
        this->prev = prev;
    }
};

bool operator<(const node& a, const node& b){
    return a.cost > b.cost;
}

vector<node> nodes;
bool visit[20001];

void dijkstra(){
    priority_queue<node> candidates;
    nodes[K].cost = 0;
    candidates.push(nodes[K]);
    while(!candidates.empty()){
        // add minimum cost node to the set
        int curr = candidates.top().num;
        visit[curr] = true;
        candidates.pop();
        // update costs
        for(adjacent p: nodes[curr].neighbors){
            if(!visit[p.num] && nodes[p.num].cost > nodes[curr].cost + p.cost){
                nodes[p.num].cost = nodes[curr].cost + p.cost;
                nodes[p.num].prev = curr;
                candidates.push(nodes[p.num]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, c;
    cin >> V >> E >> K;

    for(i=0;i<=V;i++) nodes.emplace_back(i, INF, NULL);

    while(E--){
        cin >> i >> j >> c;
        nodes[i].neighbors.emplace_back(j, c);
    }

    dijkstra();
    for(i=1;i<=V;i++){
        if(nodes[i].cost == INF) cout << "INF" << '\n';
        else cout << nodes[i].cost << '\n';
    }

    return 0;
}