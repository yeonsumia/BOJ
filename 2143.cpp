#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int A[1000], B[1000];
long long count_case;
vector<int> A_sum;

int binary_search_lower_bound(int value){
    int start = 0, end = A_sum.size()-1;
    while(start <= end){
        int mid = (start + end)/2;
        if(A_sum[mid] < value) start = mid+1;
        else end = mid-1;
    }
    return start;
}

int binary_search_upper_bound(int value){
    int start = 0, end = A_sum.size()-1;
    while(start <= end){
        int mid = (start + end)/2;
        if(A_sum[mid] > value) end = mid-1;
        else start = mid+1;
    }
    return end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n, m, i, j, sum;
    cin >> T;

    cin >> n;
    for(i=0;i<n;i++) cin >> A[i];

    cin >> m;
    for(i=0;i<m;i++) cin >> B[i];

    for(i=0;i<n;i++){
        sum = 0;
        for(j=i;j<n;j++){
            sum += A[j];
            A_sum.push_back(sum);
        }
    }
    sort(A_sum.begin(), A_sum.end());

    for(i=0;i<m;i++){
        sum = 0;
        for(j=i;j<m;j++){
            sum += B[j];
            int count = binary_search_upper_bound(T-sum) - binary_search_lower_bound(T-sum);
            if(count >= 0) count_case += count+1;
        }
    }

    cout << count_case;

    return 0;
}