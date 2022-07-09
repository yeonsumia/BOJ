#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C, i, j;
    cin >> R >> C;

    short happy[R][C];
    for(i=0;i<R;i++) for(j=0;j<C;j++) cin >> happy[i][j];

    if(R % 2 == 1){
        for(i=0;i<R;i++){
            for(j=0;j<C-1;j++) cout << (i % 2 == 0 ? 'R' : 'L');
            if(i != R-1) cout << 'D';
        }
    }
    else if(C % 2 == 1){
        for(i=0;i<C;i++){
            for(j=0;j<R-1;j++) cout << (i % 2 == 0 ? 'D' : 'U');
            if(i != C-1) cout << 'R';
        }
    }
    else{
//        test case when R % 2 == 0 && C % 2 == 0
//        4 6
//        1 2 0 3 5 1
//        3 5 2 1 5 1
//        4 3 5 2 2 2
//        4 1 3 4 5 1
//
//        4 6
//        1 2 0 1 5 4
//        3 5 2 1 5 1
//        4 3 5 2 2 2
//        4 1 3 4 5 1
//
//        4 6
//        1 2 0 3 5 4
//        3 5 2 1 1 1
//        4 3 5 2 2 2
//        4 1 3 4 5 1
//
//        4 6
//        1 2 0 3 5 4
//        1 5 2 1 5 1
//        4 3 5 2 2 2
//        4 1 3 4 5 1
//
//        4 6
//        1 2 0 3 5 4
//        3 5 2 1 5 1
//        4 1 5 2 2 2
//        1 1 3 4 5 1
//
//        4 6
//        1 2 0 3 5 4
//        3 5 2 1 5 1
//        4 3 5 2 2 2
//        1 1 3 4 5 1
        int min_i, min_j, min = 1000;
        for(i=0;i<R;i++){
            for(j=0;j<C;j++){
                if((i+j) % 2 == 1){
                    if(min > happy[i][j]){
                        min = happy[i][j];
                        min_i = i;
                        min_j = j;
                    }
                }
            }
        }

        for(i=0;i<min_i-1;i++){
            for(j=0;j<C-1;j++) cout << (i % 2 == 0 ? 'R' : 'L');
            cout << 'D';
        }
        bool tmp = true;
        if(min_i % 2 == 0 && min_i > 0){
            for(j=C-1;j>0;j--){
                if(min_j != j){
                    cout << (tmp ? 'D' : 'U');
                    tmp = !tmp;
                }
                cout << 'L';
            }
        }
        else{
            for(j=0;j<C-1;j++){
                if(min_j != j){
                    cout << (tmp ? 'D' : 'U');
                    tmp = !tmp;
                }
                cout << 'R';
            }
        }
        if(tmp) cout << 'D';
        int curr_i = (min_i == 0 ? min_i+2 : min_i+1);
        if(curr_i < R) cout << 'D';
        for(i=curr_i;i<R;i++){
            for(j=0;j<C-1;j++) cout << (i % 2 == 1 ? 'R' : 'L');
            if(i != R-1) cout << 'D';
        }
    }

    return 0;
}