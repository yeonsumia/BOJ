#include<iostream>
#include<cstring>

using namespace std;

void remove_star(int r, int c, int size, char* star, int N){
    int i, j;
    if(size == 1) return;
    size /= 3;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            *(star + (r+size+i) * N + c+size+j) = ' ';
        }
    }

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            remove_star(r+i*size, c+j*size, size, star, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int i, j;
    char star[N][N];
    for(i=0;i<N;i++)
        memset(star[i], '*', sizeof(char)*N);

    remove_star(0, 0, N, (char*) star, N);

    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            cout << star[i][j];
        cout << '\n';
    }

    return 0;
}