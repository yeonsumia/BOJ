#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int A[4000], B[4000], C[4000], D[4000];
long long count_case;
vector<int> AB;

// return lower index of accordant value in the list
// return lower index of the nearest bigger value in the list
int binary_search_lower_bound(int value){
    int start = 0, end = AB.size()-1;
    while(start <= end){
        int mid = (start+end)/2;
        if(AB[mid] >= value) end = mid-1;
        else start = mid+1;
    }
    return start;
}

// return upper index of accordant value in the list
// return upper index of the nearest smaller value in the list
int binary_search_upper_bound(int value){
    int start = 0, end = AB.size()-1;
    while(start <= end){
        int mid = (start+end)/2;
        if(AB[mid] <= value) start = mid+1;
        else end = mid-1;
    }
    return end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, j;
    cin >> n;

    for(i=0;i<n;i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    for(i=0;i<n;i++) for(j=0;j<n;j++) AB.push_back(A[i]+B[j]);
    sort(AB.begin(), AB.end());

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            int sum_CD = C[i]+D[j];
            int count = binary_search_upper_bound(-sum_CD) - binary_search_lower_bound(-sum_CD);
            if(count >= 0) count_case += count+1;
        }
    }

    cout << count_case;

    return 0;
}