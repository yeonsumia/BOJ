#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M, K;
int count_case;

int px[4] = {1,0,-1,0};
int py[4] = {0,1,0,-1};

string s;
char c[101][101];
int dp[101][101][81];

class searcher{
public:
    int i;
    int j;
    int length;
    searcher(int i, int j, int length){
        this->i = i;
        this->j = j;
        this->length = length;
    }
};

void bfs_word(){
    int curr_i, curr_j, curr_depth, next_i, next_j;
    queue<searcher> q;
    for(int a=0;a<N;a++){
        for(int b=0;b<M;b++){
            if(c[a][b] == s[0]){
                q.emplace(a, b, 1);
                while(!q.empty()){
                    searcher s_c = q.front();
                    curr_i = s_c.i; curr_j = s_c.j; curr_depth = s_c.length;
                    q.pop();
                    for(int i=0;i<4;i++){
                        for(int k=1;k<=K;k++){
                            next_i = curr_i + px[i]*k;
                            next_j = curr_j + py[i]*k;
                            if(next_i < 0 || next_i >= N) continue;
                            if(next_j < 0 || next_j >= M) continue;
                            if(c[next_i][next_j] == s[curr_depth]){
                                if(curr_depth+1 == s.length()) count_case++;
                                else q.emplace(next_i, next_j, curr_depth+1);
                            }
                        }
                    }
                }
            }
        }
    }
}

int dfs_word(int curr_i, int curr_j, int curr_depth){
    if(curr_depth == s.length()) return 1;
    // dp value:
    // -1 -> not visited
    //  0 -> visited but there is no possible path
    // >0 -> number of path
    if(dp[curr_i][curr_j][curr_depth] != -1) return dp[curr_i][curr_j][curr_depth];
    dp[curr_i][curr_j][curr_depth] = 0;
    int next_i, next_j;
    for(int a=0;a<4;a++){
        for(int k=1;k<=K;k++){
            next_i = curr_i + px[a]*k;
            next_j = curr_j + py[a]*k;
            if(next_i < 0 || next_i >= N) continue;
            if(next_j < 0 || next_j >= M) continue;
            if(c[next_i][next_j] == s[curr_depth]){
                dp[curr_i][curr_j][curr_depth] += dfs_word(next_i, next_j, curr_depth+1);
            }
        }
    }
    return dp[curr_i][curr_j][curr_depth];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    int i, j;

    for(i=0;i<N;i++) for(j=0;j<M;j++) cin >> c[i][j];

    cin >> s;
    memset(dp, -1, sizeof(dp));
//    bfs_word(c, s);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(c[i][j] == s[0]){
                count_case += dfs_word(i, j, 1);
            }
        }
    }
    cout << count_case;

    return 0;
}