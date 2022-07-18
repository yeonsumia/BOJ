#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int L, C;
vector<char> alphabet;

bool check_valid(const string& s){
    bool condition = false;
    int condition2 = 0;
    for(char i: s){
        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') condition = true;
    }
    for(char i: s){
        if(i != 'a' && i != 'e' && i != 'i' && i != 'o' && i != 'u') condition2++;
    }
    return condition && condition2 >= 2;
}

void dfs_password(const string& s, int last_i){
    if(s.length() == L){
        if(check_valid(s)) cout << s << '\n';
        return;
    }
    for(int i=last_i+1;i<C;i++){
        dfs_password(s+alphabet[i], i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    cin >> L >> C;

    char c;
    for(i=0;i<C;i++){
        cin >> c;
        alphabet.push_back(c);
    }
    sort(alphabet.begin(), alphabet.end());

    for(i=0;i<C;i++){
        string s;
        dfs_password(s+alphabet[i], i);
    }

    return 0;
}