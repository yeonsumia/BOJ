#include<iostream>
#include<queue>

using namespace std;

const int MAX = 100001;
bool visit[MAX];
int depth[MAX];

int bfs_depth(int N, int K){
    queue<int> q;
    visit[N] = true;
    q.push(N);
    while(!q.empty()){
        int n = q.front();
        q.pop();
        if(!visit[n+1] && n+1 >= 0 && n+1 < MAX){
            visit[n+1] = true;
            q.push(n+1);
            depth[n+1] = depth[n] + 1;
        }
        if(!visit[n-1] && n-1 >= 0 && n-1 < MAX){
            visit[n-1] = true;
            q.push(n-1);
            depth[n-1] = depth[n] + 1;
        }
        if(!visit[2*n] && 2*n >= 0 && 2*n < MAX){
            visit[2*n] = true;
            q.push(2*n);
            depth[2*n] = depth[n] + 1;
        }
    }
    return depth[K];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    cout << bfs_depth(N, K);

    return 0;
}