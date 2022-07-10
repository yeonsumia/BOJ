#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short E, S, M;
    cin >> E >> S >> M;

    short e = 0, s = 0, m = 0, year = 0;
    while(e != E || s != S || m != M){
        e++; s++; m++; year++;
        if(e == 16) e = 1;
        if(s == 29) s = 1;
        if(m == 20) m = 1;
    }

    cout << year;

    return 0;
}