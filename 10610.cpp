#include<iostream>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int i, j, sum_digit = 0;
    short digit[10] = { };

    bool no_zero = true;
    for(i=0;i<s.size();i++){
        int c = s[i] - '0';
        sum_digit += c;
        digit[c]++;
        if(c == 0) no_zero = false;
    }
    if(no_zero || (sum_digit % 3) != 0) cout << -1;
    else{
        for(i=9;i>=0;i--)
            for(j=0;j<digit[i];j++) cout << i;
    }

    return 0;
}