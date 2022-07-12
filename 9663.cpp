#include<iostream>
#include<cstring>

using namespace std;

int n_queen_backtracking(int i, int visit[], int N){
    int j, k;
    int ans = 0;
    bool forbidden;
    for(j=0;j<N;j++){
        if(visit[i] == -1){
            forbidden = false;
            for(k=0;k<i;k++){
                if(visit[k] != -1){
                    if(visit[k] == j || visit[k]+k-i == j || visit[k]+i-k == j){
                        forbidden = true;
                        break;
                    }
                }
            }
            if(forbidden) continue;
            visit[i] = j;
            if(i == N-1) ans++;
            else ans += n_queen_backtracking(i+1, visit, N);
            visit[i] = -1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int visit[N];
    memset(visit, -1, sizeof(int)*N);

    cout << n_queen_backtracking(0, visit, N);

    return 0;
}