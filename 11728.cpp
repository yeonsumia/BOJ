#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int i;
    cin >> N >> M;

    int a[N], b[M];
    for(i=0;i<N;i++)
        cin >> a[i];
    for(i=0;i<M;i++)
        cin >> b[i];

    int j = 0, k = 0, l = 0;
    int c[N+M];
    while(j < N && k < M){
        if(a[j] <= b[k]){
            c[l] = a[j];
            l++; j++;
        }
        else{
            c[l] = b[k];
            l++; k++;
        }
    }
    if(j == N){
        while(k < M){
            c[l] = b[k];
            l++; k++;
        }
    }
    else if(k == M){
        while(j < N){
            c[l] = a[j];
            l++; j++;
        }
    }

    for(i=0;i<N+M;i++)
        cout << c[i] << " ";

    return 0;
}