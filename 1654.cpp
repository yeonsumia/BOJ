#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long binary_search_lan(long start, long end, long max, const vector<long>& lan, int N){
    if(start <= end){
        long mid = (start+end)/2;
        long sum = 0;

        for(long l: lan) sum += l/mid;
        if(sum >= N) max = binary_search_lan(mid+1, end, mid, lan, N);
        else max = binary_search_lan(start, mid-1, max, lan, N);
    }
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    int i, x;
    cin >> K >> N;

    vector<long> lan;
    long max_lan;
    for(i=0;i<K;i++){
        cin >> x;
        lan.push_back(x);
    }
    max_lan = *max_element(lan.begin(), lan.end());

    cout << binary_search_lan(1, max_lan, max_lan, lan, N) << '\n';

    return 0;
}