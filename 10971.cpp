#include<iostream>
#include<cstring>

using namespace std;

int min_cost = 1e9;

void tsp_backtracking(int start, int curr, const int* W, bool visit[], int N, int count, int sum_cost){
    if(count == N){
        int cost = *(W + curr*(N+1) + start);
        if(cost != 0) min_cost = min(min_cost, sum_cost + cost);
        else return;
    }
    for(int i=1;i<=N;i++){
        if(!visit[i] && *(W + curr*(N+1) + i) != 0){
            visit[i] = true;
            tsp_backtracking(start, i, W, visit, N, count+1, sum_cost + *(W + curr*(N+1) + i));
            visit[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i, j;
    cin >> N;

    int W[N+1][N+1];
    for(i=1;i<=N;i++) for(j=1;j<=N;j++) cin >> W[i][j];

    bool visit[N+1];
    memset(visit, false, sizeof(bool)*(N+1));

//    for(i=1;i<=N;i++){
//        visit[i] = true;
//        tsp_backtracking(i, i, (int*) W, visit, N, 1, 0);
//        visit[i] = false;
//    }

    visit[1] = true;
    tsp_backtracking(1, 1, (int*) W, visit, N, 1, 0);

    cout << min_cost;

    return 0;
}