#include<iostream>
#include<queue>

using namespace std;

int F, S, G, U, D;
bool visit[1000001];
int depth[1000001];

int bfs_elevator(int curr){
    if(curr == G) return 0;
    queue<int> q;
    q.push(curr);
    visit[curr] = true;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr+U == G) return depth[curr]+1;
        if(curr+U <= F && !visit[curr+U]){
            visit[curr+U] = true;
            depth[curr+U] = depth[curr] + 1;
            q.push(curr+U);
        }
        if(curr-D == G) return depth[curr]+1;
        if(curr-D >= 1 && !visit[curr-D]){
            visit[curr-D] = true;
            depth[curr-D] = depth[curr] + 1;
            q.push(curr-D);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> F >> S >> G >> U >> D;

    int ans = bfs_elevator(S);

    if(ans == -1) cout << "use the stairs";
    else cout << ans;

    return 0;
}