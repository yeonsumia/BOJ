#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int start = -1, last = -1;
int line_length = 0;

void swipe_1d(vector<pair<int,int>>& v){
    for(auto p: v){
        // initial setting
        if(start == -1 && last == -1){
            start = p.first;
            last = p.second;
            continue;
        }

        if(last < p.first){
            line_length += last - start;
            start = p.first;
        }
        if(last < p.second) last = p.second;
    }
    line_length += last - start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int i, x, y;
    vector<pair<int,int>> point;
    for(i=0;i<N;i++) {
        cin >> x >> y;
        point.emplace_back(x, y);
    }
    sort(point.begin(), point.end());

    swipe_1d(point);
    cout << line_length;

    return 0;
}