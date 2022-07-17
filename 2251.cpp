#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int A, B, C;
bool visit[201][201][201];
bool c_visit[201];

class bottle{
public:
    int a, b, c;
    bottle(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

void bfs_c(int a, int b, int c){
    queue<bottle> q;
    q.emplace(a, b, c);
    visit[a][b][c] = true;
    if(a == 0) c_visit[c] = true;
    while(!q.empty()){
        bottle bot = q.front();
        a = bot.a; b = bot.b; c = bot.c;
        q.pop();
        // use bottle A
        // 0 b+a c
        if(b+a <= B && !visit[0][b+a][c]){
            visit[0][b+a][c] = true;
            q.emplace(0, b+a, c);
            c_visit[c] = true;
        }
        // a-B+b B c
        else if(a-B+b >= 0 && !visit[a-B+b][B][c]){
            visit[a-B+b][B][c] = true;
            q.emplace(a-B+b, B, c);
            if(a-B+b == 0) c_visit[c] = true;
        }
        // 0 b c+a
        if(c+a <= C && !visit[0][b][c+a]){
            visit[0][b][c+a] = true;
            q.emplace(0, b, c+a);
            c_visit[c+a] = true;
        }
        // a-C+c b C
        else if(a-C+c >= 0 && !visit[a-C+c][b][C]){
            visit[a-C+c][b][C] = true;
            q.emplace(a-C+c, b, C);
            if(a-C+c == 0) c_visit[C] = true;
        }
        // use bottle B
        // a+b 0 c
        if(a+b <= A && !visit[a+b][0][c]){
            visit[a+b][0][c] = true;
            q.emplace(a+b, 0, c);
            if(a+b == 0) c_visit[c] = true;
        }
        // A b-A+a c
        else if(b-A+a >= 0 && !visit[A][b-A+a][c]){
            visit[A][b-A+a][c] = true;
            q.emplace(A, b-A+a, c);
        }
        // a 0 c+b
        if(c+b <= C && !visit[a][0][c+b]){
            visit[a][0][c+b] = true;
            q.emplace(a, 0, c+b);
            if(a == 0) c_visit[c+b] = true;
        }
        // a b-C+c C
        else if(b-C+c >= 0 && !visit[a][b-C+c][C]){
            visit[a][b-C+c][C] = true;
            q.emplace(a, b-C+c, C);
            if(a == 0) c_visit[C] = true;
        }
        // use bottle C
        // a+c b 0
        if(a+c <= A && !visit[a+c][b][0]){
            visit[a+c][b][0] = true;
            q.emplace(a+c, b, 0);
            if(a+c == 0) c_visit[0] = true;
        }
        // A b c-A+a
        else if(c-A+a >= 0 && !visit[A][b][c-A+a]){
            visit[A][b][c-A+a] = true;
            q.emplace(A, b, c-A+a);
        }
        // a b+c 0
        if(b+c <= B && !visit[a][b+c][0]){
            visit[a][b+c][0] = true;
            q.emplace(a, b+c, 0);
            if(a == 0) c_visit[0] = true;
        }
        // a B c-B+b
        else if(c-B+b >= 0 && !visit[a][B][c-B+b]){
            visit[a][B][c-B+b] = true;
            q.emplace(a, B, c-B+b);
            if(a == 0) c_visit[c-B+b] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;

    bfs_c(0, 0, C);
    for(int i=0;i<201;i++)
        if(c_visit[i]) cout << i << ' ';

    return 0;
}