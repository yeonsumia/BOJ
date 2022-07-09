#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, team;
    cin >> N >> M >> K;

    team = min(N/2, M);
    while(N+M - team*3 < K){ team--; }

    cout << team;

    return 0;
}