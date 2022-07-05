#include<iostream>
#include<cstring>

using namespace std;

void remove_star(int r, int c, int n, char* star, int W){
    if(n == 3){
        *(star + (r+1) * W + c+2) = ' ';
        return;
    }

    int i, j;
    int w = 2*n-1;
    for(i=n/2;i<n;i++)
        for(j=i;j<w-i;j++)
            *(star + (r+i) * W + c+j) = ' ';

    remove_star(r, c+n/2, n/2, star, W);
    remove_star(r+n/2, c, n/2, star, W);
    remove_star(r+n/2, c+n, n/2, star, W);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i, j;
    cin >> N;

    int W = 2*N-1;
    char star[N][W];
    for(i=0;i<N;i++)
        memset(star[i], '*', sizeof(char)*W);

    for(i=0;i<N;i++)
        for(j=0;j<W/2-i;j++)
            star[i][j] = ' ';

    for(i=0;i<N;i++)
        for(j=N+i;j<W;j++)
            star[i][j] = ' ';

    remove_star(0, 0, N, (char*) star, W);

    for(i=0;i<N;i++){
        for(j=0;j<W;j++)
            cout << star[i][j];
        cout << '\n';
    }

    return 0;
}