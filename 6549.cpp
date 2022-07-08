#include<iostream>

using namespace std;

long long max(long long a, long long b){ return a >= b ? a : b; }
int min(int a, int b){ return a <= b ? a : b; }

long long max_mid_area(int start, int end, int mid, const int h[]){
    long long height = h[mid];
    long long width = 1;
    long long max_area = height * width;
    int left_mid = mid-1;
    int right_mid = mid+1;
    while(start <= left_mid && right_mid <= end){
        if(h[left_mid] >= h[right_mid]){
            height = min(h[left_mid], height);
            width++;
            max_area = max(max_area, height * width);
            left_mid--;
        }
        else if(h[left_mid] < h[right_mid]){
            height = min(h[right_mid], height);
            width++;
            max_area = max(max_area, height * width);
            right_mid++;
        }
    }
    while(start <= left_mid){
        height = min(h[left_mid], height);
        width++;
        max_area = max(max_area, height * width);
        left_mid--;
    }
    while(right_mid <= end){
        height = min(h[right_mid], height);
        width++;
        max_area = max(max_area, height * width);
        right_mid++;
    }
    return max_area;
}

long long calculate_max_area(int start, int end, const int h[]){
    if(start == end) return h[start];
    int mid = (start+end)/2;

    long long max_area = max(calculate_max_area(start, mid, h), calculate_max_area(mid + 1, end, h));

    return max(max_mid_area(start, end, mid, h), max_area);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while(n != 0){
        int i;
        int h[n];
        for(i=0;i<n;i++)
            cin >> h[i];

        cout << calculate_max_area(0, n-1, h) << '\n';

        cin >> n;
    }

    return 0;
}