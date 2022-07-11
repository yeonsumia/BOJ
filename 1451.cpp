#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, i, j, k, w, l;
    cin >> N >> M;

    char num[N][M];
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            cin >> num[i][j];

    long long ans = 0, sum, sum_left, sum_right, sum_up, sum_down;

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            sum = 0;
            for(k=0;k<=i;k++) for(w=0;w<=j;w++) sum += num[k][w] - '0';

            if(i < N-1 && j < M-1){
                sum_right = 0; sum_down = 0;
                for(k=0;k<=i;k++) for(w=j+1;w<M;w++) sum_right += num[k][w] - '0';
                for(k=i+1;k<N;k++) for(w=0;w<M;w++) sum_down += num[k][w] - '0';
                ans = max(ans, sum * sum_right * sum_down);

                sum_right = 0; sum_down = 0;
                for(k=0;k<N;k++) for(w=j+1;w<M;w++) sum_right += num[k][w] - '0';
                for(k=i+1;k<N;k++) for(w=0;w<=j;w++) sum_down += num[k][w] - '0';
                ans = max(ans, sum * sum_right * sum_down);
            }
            if(i == N-1 && j < M-2){
                for(l=0;l<N-1;l++){
                    sum_up = 0; sum_down = 0;
                    for(k=0;k<=l;k++) for(w=j+1;w<M;w++) sum_up += num[k][w] - '0';
                    for(k=l+1;k<N;k++) for(w=j+1;w<M;w++) sum_down += num[k][w] - '0';
                    ans = max(ans, sum * sum_up * sum_down);
                }
                for(l=j+1;l<M-1;l++){
                    sum_left = 0; sum_right = 0;
                    for(k=0;k<N;k++) for(w=j+1;w<=l;w++) sum_left += num[k][w] - '0';
                    for(k=0;k<N;k++) for(w=l+1;w<M;w++) sum_right += num[k][w] - '0';
                    ans = max(ans, sum * sum_left * sum_right);
                }
            }
            if(j == M-1 && i < N-2){
                for(l=0;l<M-1;l++){
                    sum_left = 0; sum_right = 0;
                    for(k=i+1;k<N;k++) for(w=0;w<=l;w++) sum_left += num[k][w] - '0';
                    for(k=i+1;k<N;k++) for(w=l+1;w<M;w++) sum_right += num[k][w] - '0';
                    ans = max(ans, sum * sum_left * sum_right);
                }
                for(l=i+1;l<N-1;l++){
                    sum_left = 0; sum_right = 0;
                    for(k=i+1;k<=l;k++) for(w=0;w<M;w++) sum_left += num[k][w] - '0';
                    for(k=l+1;k<N;k++) for(w=0;w<M;w++) sum_right += num[k][w] - '0';
                    ans = max(ans, sum * sum_left * sum_right);
                }
            }
        }
    }

    cout << ans;

    return 0;
}