#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int calculate_adjacent_sum(vector<short>& v){
    int ans = 0;
    short a = v[0];
    for(short& b: v){
        ans += abs(a-b);
        a = b;
    }
    return ans;
}

int dfs_backtracking(short num[], bool visit[], vector<short>& v, int N){
    int ans = 0;
    for(int i=0;i<N;i++){
        if(!visit[i]){
            visit[i] = true;
            v.push_back(num[i]);
            if(v.size() == N) ans = calculate_adjacent_sum(v);
            else ans = max(ans, dfs_backtracking(num, visit, v, N));
            v.pop_back();
            visit[i] = false;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short N, i, x;
    cin >> N;

    short num[N];
    bool visit[N];
    memset(visit, false, sizeof(bool)*N);

    for(i=0;i<N;i++) cin >> num[i];

    vector<short> v;
    cout << dfs_backtracking(num, visit, v, N);

    return 0;
}