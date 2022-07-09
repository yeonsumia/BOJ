#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num;
    cin >> N >> M;

    if(N == 1) num = 1;
    // cannot use operation 1 & 4 -> max = 4
    else if(N == 2) num = min(4,(M+1)/2);
    else{
        num = M; // max when using operation 1 & 4
        if(num > 4){
            // necessary to use operation 2 & 3
            num = max(num-2, 4);
        }
    }
    cout << num;

    return 0;
}