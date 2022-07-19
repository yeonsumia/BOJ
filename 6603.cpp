#include<iostream>
#include<vector>

using namespace std;

vector<int> combination;

void backtracking(int idx, vector<int> set){
    combination.push_back(set[idx]);
    if(combination.size() == 6){
        for(int& i: combination) cout << i << ' ';
        cout << '\n';
    }
    for(int i=idx+1;i<set.size();i++) backtracking(i, set);
    combination.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, i, s;
    cin >> k;
    while(k != 0){
        vector<int> set;
        for(i=0;i<k;i++){
            cin >> s;
            set.push_back(s);
        }
        for(i=0;i<k;i++) backtracking(i, set);
        cout << '\n';
        cin >> k;
    }

    return 0;
}