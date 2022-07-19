#include<iostream>
#include<vector>

using namespace std;

int num[20];
bool visit[20];
int N, S;
int count_case;
vector<int> combination;

int sum(){
    int s = 0;
    for(int i: combination) s += i;
    return s;
}

void backtracking(int idx){
    combination.push_back(num[idx]);
    visit[idx] = true;
    if(sum() == S) count_case++;
    for(int i=idx+1;i<N;i++) if(!visit[i]) backtracking(i);
    combination.pop_back();
    visit[idx] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    cin >> N >> S;

    for(i=0;i<N;i++) cin >> num[i];

    for(i=0;i<N;i++) backtracking(i);

    cout << count_case;

    return 0;
}