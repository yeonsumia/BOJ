#include<iostream>
#include<unordered_map>

using namespace std;

int A[1000], B[1000], count_case;
unordered_map<int,int> pizza_A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, m, n, i, j, sum;
    cin >> size >> m >> n;

    for(i=0;i<m;i++) cin >> A[i];
    for(i=0;i<n;i++) cin >> B[i];

    pizza_A[0]++;

    // i: start position, j: length-1
    for(i=0;i<m;i++){
        sum = 0;
        for(j=0;j<m-(i == 0 ? 0 : 1);j++){
            sum += A[i+j >= m ? i+j-m : i+j];
            pizza_A[sum]++;
        }
    }
    // i: start position, j: length-1
    for(i=0;i<n;i++){
        sum = 0;
        for(j=0;j<n-(i == 0 ? 0 : 1);j++){
            sum += B[i+j >= n ? i+j-n : i+j];
            count_case += pizza_A[size-sum];
        }
    }
    count_case += pizza_A[size];

    cout << count_case;

    return 0;
}