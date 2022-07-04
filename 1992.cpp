#include<iostream>
#include<string>

using namespace std;

string compress_quad_tree(int r, int c, int size, const bool* quad_tree, int N){
    int i, j;
    bool all_same = true;
    bool num = *(quad_tree + r * N + c);
    for(i=r;i<r+size;i++){
        for(j=c;j<c+size;j++){
            if(*(quad_tree + i * N + j) != num){
                all_same = false;
                break;
            }
        }
        if(!all_same) break;
    }
    if(all_same){ return num ? "1" : "0"; }
    else{
        string s = "(";
        size /= 2;
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                s += compress_quad_tree(r + size * i, c + size * j, size, quad_tree, N);
            }
        }
        s += ")";
        return s;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();

    int i, j;
    string s;
    bool quad_tree[N][N];
    for(i=0;i<N;i++){
        getline(cin, s);
        for(j=0;j<N;j++)
            quad_tree[i][j] = s[j] - '0';
    }

    cout << compress_quad_tree(0, 0, N, (bool*) quad_tree, N);

    return 0;
}