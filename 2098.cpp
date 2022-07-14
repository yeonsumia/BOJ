#include<iostream>
#include<cstring>

using namespace std;
int max_value = 1e9;
int N;
int W[16][16];
int dp[16][1<<16];

int TSP(int curr, int visited){
    int cost, min_cost = dp[curr][visited];
    if(min_cost != -1) return min_cost;
    // memoization
    if(visited == (1<<N)-1){
        cost = W[curr][0];
        dp[curr][visited] = cost == 0 ? max_value : cost;
        return dp[curr][visited];
    }
    min_cost = max_value;
    for(int i=0;i<N;i++){
        cost = W[curr][i];
        if(cost != 0 && (visited & 1<<i) == 0){
            min_cost = min(min_cost, TSP(i, visited | 1<<i) + cost);
        }
    }
    // memoization
    dp[curr][visited] = min_cost;
    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int i, j;
    for(i=0;i<N;i++) for(j=0;j<N;j++) cin >> W[i][j];

    memset(dp, -1, sizeof(dp));

    cout << TSP(0, 1);

    return 0;
}