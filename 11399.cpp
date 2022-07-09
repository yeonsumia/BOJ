#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i, p;
    cin >> N;

    vector<int> P;
    for(i=0;i<N;i++){
        cin >> p;
        P.push_back(p);
    }
    sort(P.begin(), P.end());

    int sum_time[N], sum = 0;
    sum_time[0] = P[0];
    for(i=1;i<N;i++){
        sum_time[i] = sum_time[i-1] + P[i];
    }

    for(i=0;i<N;i++) sum += sum_time[i];
    cout << sum;

    return 0;
}