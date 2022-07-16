#include<iostream>
#include<queue>

using namespace std;

const int MAX = 100001;
int depth[MAX];
int count_case;
int min_depth = 1e9;

int bfs_depth(int N, int K){
    int i, next;
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int n = q.front();
        q.pop();
        // execute bfs until depth is less than or equal to (minimum depth)
        if(depth[n] >= min_depth) break;
        for(i=0;i<3;i++){
            next = i == 0 ? n+1 : i == 1 ? n-1 : 2*n;
            if(next < 0 || next >= MAX) continue;
            // visit next number if it is unvisited number or its path has minimum depth
            if(next != N && depth[next] == 0 || depth[next] == depth[n] + 1){
                q.push(next);
                depth[next] = depth[n] + 1;
                if(next == K){
                    count_case++;
                    min_depth = depth[next];
                }
            }
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

    cout << bfs_depth(N, K) << '\n' << (count_case == 0 ? 1 : count_case);

    return 0;
}