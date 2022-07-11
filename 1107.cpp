#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    bool button[10];
    int i, num;
    memset(button, true, sizeof(bool)*10);

    for(i=0;i<M;i++){
        cin >> num;
        button[num] = false;
    }

    int min_N = N, max_N = N + 1, n;
    int count_min = 0, count_max = 0;
    while(min_N >= 0){
        n = min_N;
        if(n == 0){
            if(button[0]){
                min_N = 0;
                count_min = 1;
            }
            else{
                min_N = -1;
                count_min = 0;
            }
            break;
        }
        while(n != 0){
            if(!button[n % 10]) break;
            n /= 10;
            count_min++;
        }
        if(n != 0){
            min_N--;
            count_min = 0;
        }
        else break;
    }
    while(max_N <= 999900){
        n = max_N;
        while(n != 0){
            if(!button[n % 10]) break;
            n /= 10;
            count_max++;
        }
        if(n != 0){
            max_N++;
            count_max = 0;
        }
        else break;
    }

    if(min_N == -1) cout << min(count_max + max_N - N, abs(N - 100));
    else cout << min(min(count_min + N - min_N, count_max + max_N - N), abs(N - 100));

    return 0;
}