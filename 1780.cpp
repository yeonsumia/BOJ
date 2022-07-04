#include<iostream>

using namespace std;
int zero = 0, one = 0, minus_one = 0;

void count_paper(int r, int c, int size, const short* paper, int N){
    int i, j;
    short num = *(paper + r * N + c);
    bool all_same = true;
    for(i=r;i<r+size;i++){
        for(j=c;j<c+size;j++){
            if(*(paper + i * N + j) != num){
                all_same = false;
                break;
            }
        }
        if(!all_same) break;
    }
    if(all_same){
        switch(num){
            case 1: one++; break;
            case 0: zero++; break;
            case -1: minus_one++; break;
            default: ;
        }
    }
    else{
        size /= 3;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                count_paper(r+size*i, c+size*j, size, paper, N);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int i, j;
    cin >> N;

    short paper[N][N];
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            cin >> paper[i][j];

    count_paper(0, 0, N, (short*) paper, N);
    cout << minus_one << '\n';
    cout << zero << '\n';
    cout << one << '\n';

    return 0;
}