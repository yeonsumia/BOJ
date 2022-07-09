#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int A[N], i, max_index, count = 0;
    for(i=0;i<N;i++){
        cin >> A[i];
        if(K >= A[i]) max_index = i;
    }

    while(K != 0){
        count += K / A[max_index];
        K %= A[max_index];
        max_index--;
    }

    cout << count;

    return 0;
}