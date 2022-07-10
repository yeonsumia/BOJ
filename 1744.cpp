#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short N, i;
    int sum = 0, x;
    cin >> N;

    vector<int> plus, minus;
    bool zero_exist = false;
    for(i=0;i<N;i++){
        cin >> x;
        if(x > 0) plus.push_back(x);
        else if(x < 0) minus.push_back(x);
        else zero_exist = true;
    }
    sort(plus.begin(), plus.end(), [](const int& p1, const int& p2){ return p1 > p2; });
    sort(minus.begin(), minus.end());

    for(i=0;i+1<plus.size();i+=2) sum += (plus[i] == 1 || plus[i+1] == 1 ? plus[i] + plus[i+1] : plus[i] * plus[i+1]);
    if(plus.size() % 2 == 1) sum += plus[plus.size()-1];
    for(i=0;i+1<minus.size();i+=2) sum += minus[i] * minus[i+1];
    if(minus.size() % 2 == 1) sum += (zero_exist ? 0 : minus[minus.size()-1]);

    cout << sum;

    return 0;
}