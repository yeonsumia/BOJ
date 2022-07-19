#include<iostream>

using namespace std;

int num[10001];
int count_case;

int sum(int i, int j){
    if(i > j) return 0;
    int s = 0;
    for(int a=i;a<=j;a++) s+= num[a];
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, i;
    cin >> N >> M;

    for(i=0;i<N;i++) cin >> num[i];

    int p1 = 0, p2 = 0;
    // two pointer - O(N)
    while(p2 <= N-1){
        int s = sum(p1, p2);
        if(s == M){
            count_case++;
            p2++;
        }
        else if(s > M) p1++;
        else p2++;
    }

    cout << count_case;

    return 0;
}