#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int binary_search_set_wifi_with_distance(int start, int end, int d, const int distance[], const vector<int>& house, int N, int C){
    if(start <= end){
        int mid = (start+end)/2;
        long distance_sum = 0;
        // set a wi-fi to the first house
        int count_wifi = 1;
        for(int i=0;i<N-1;i++){
            distance_sum += distance[i];
            if(distance_sum >= mid){
                count_wifi++;
                distance_sum = 0;
            }
        }
        if(count_wifi >= C) d = binary_search_set_wifi_with_distance(mid+1, end, mid, distance, house, N, C);
        else d = binary_search_set_wifi_with_distance(start, mid-1, d, distance, house, N, C);
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C;
    int i, x;
    cin >> N >> C;

    vector<int> house;
    int distance[N-1];
    bool wifi[N];
    memset(wifi, false, sizeof(bool)*N);

    for(i=0;i<N;i++){
        cin >> x;
        house.push_back(x);
    }
    sort(house.begin(), house.end());

    for(i=0;i<N-1;i++)
        distance[i] = house[i+1] - house[i];

    cout << binary_search_set_wifi_with_distance(1, house[N-1]-house[0], 1, distance, house, N, C);

    return 0;
}