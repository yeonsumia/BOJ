#include<iostream>

using namespace std;

int hanoi_count(int n){
    if(n == 0) return 0;
    return 2*hanoi_count(n-1)+1;
}

void hanoi_print(int n, short start, short mid, short end){
    if(n == 0) return;

    hanoi_print(n-1, start, end, mid);
    cout << start << ' ' << end << '\n';
    hanoi_print(n-1, mid, start, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    cout << hanoi_count(N) << '\n';
    hanoi_print(N, 1, 2, 3);

    return 0;
}