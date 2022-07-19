#include<iostream>

using namespace std;

int num[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S, i;
    cin >> N >> S;

    for(i=0;i<N;i++) cin >> num[i];

    int p1 = 0, p2 = 0, min_length = 100001;
    int sum = num[p2];
    while(p2 <= N-1){
        if(sum >= S){
            min_length = min(min_length, p2-p1+1);
            sum -= num[p1++];
        }
        else{
            if(p2 < N-1) sum += num[++p2];
            else p2++;
        }
    }

    cout << (min_length == 100001 ? 0 : min_length);

    return 0;
}