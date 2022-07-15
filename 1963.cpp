#include<iostream>
#include<cmath>
#include<queue>
#include<cstring>

using namespace std;

bool visit[10000];
int depth[10000];

bool prime_number(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(int i=3;i<=sqrt(n);i+=2){ if(n % i == 0) return false; }
    return true;
}

int bfs_prime(int p, int q){
    int i, j, num, transformed_num;
    queue<int> queue;
    queue.push(p);
    visit[p] = true;
    while(!queue.empty()){
        num = queue.front();
        queue.pop();
        for(i=0;i<4;i++){
            for(j=0;j<10;j++){
                if(i == 3 && j == 0) continue;
                int pos = (int) pow(10,i);
                int digit = (num/pos)%10;
                if(j != digit){
                    transformed_num = num - digit*pos + j*pos;
                    if(!visit[transformed_num] && prime_number(transformed_num)){
                        visit[transformed_num] = true;
                        queue.push(transformed_num);
                        depth[transformed_num] = depth[num] + 1;
                    }
                }
            }
        }
    }
    return depth[q];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, p, q, ans;
    cin >> T;

    while(T--){
        memset(visit, false, sizeof(visit));
        memset(depth, 0, sizeof(depth));
        cin >> p >> q;
        ans = bfs_prime(p, q);
        if(ans == 0 && p != q) cout << "Impossible" << '\n';
        else cout << ans << '\n';
    }

    return 0;
}