#include<iostream>
#include<queue>
#include<cstring>
#include<utility>

using namespace std;

bool visit[10000];
int d[4];

class commend{
public:
    int num;
    string comm;
    commend(int num, string comm){
        this->num = num;
        this->comm = move(comm);
    }
};

string bfs_commend(int A, int B){
    int num, D, S, L, R, tmp, i;
    queue<commend> q;
    string s;
    q.emplace(A, "");
    visit[A] = true;
    while(!q.empty()){
        num = q.front().num;
        s = q.front().comm;
        q.pop();
        D = (2*num)%10000;
        if(!visit[D]){
            visit[D] = true;
            if(D == B) return s+"D";
            q.emplace(D, s+"D");
        }
        S = num == 0 ? 9999 : num-1;
        if(!visit[S]){
            visit[S] = true;
            if(S == B) return s+"S";
            q.emplace(S, s+"S");
        }
        tmp = num;
        i = 3; memset(d, 0, sizeof(d));
        while(tmp != 0){
            d[i--] = tmp%10;
            tmp /= 10;
        }
        L = d[1]*1000 + d[2]*100 + d[3]*10 + d[0];
        if(!visit[L]){
            visit[L] = true;
            if(L == B) return s+"L";
            q.emplace(L, s+"L");
        }
        R = d[3]*1000 + d[0]*100 + d[1]*10 + d[2];
        if(!visit[R]){
            visit[R] = true;
            if(R == B) return s+"R";
            q.emplace(R, s+"R");
        }
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, A, B;
    cin >> T;
    while(T--){
        memset(visit, false, sizeof(visit));
        cin >> A >> B;
        cout << bfs_commend(A, B) << '\n';
    }

    return 0;
}