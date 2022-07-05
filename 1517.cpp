#include<iostream>

using namespace std;

long long count_swap = 0;

int bubble_sort(int A[], int N){
    int i, j, tmp, count = 0;
    bool swap_occur;
    for(i=N-1;i>0;i--){
        swap_occur = false;
        for(j=0;j<i;j++){
            if(A[j] > A[j+1]){
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
                count++;
                swap_occur = true;
            }
        }
        if(!swap_occur) break;
    }
    return count;
}

void merge_count(int a, int b, int c, int d, int A[]){
    int B[d-a+1];
    int i = a, j = c, k = 0;
    while(i <= b && j <= d){
        if(A[i] <= A[j]){
            B[k++] = A[i++];
            count_swap += abs(i - a - k);
        }
        else{
            B[k++] = A[j++];
            count_swap += abs(j - a - k);
        }
    }
    while(i <= b){
        B[k++] = A[i++];
        count_swap += abs(i - a - k);
    }
    while(j <= d){
        B[k++] = A[j++];
        count_swap += abs(j - a - k);
    }
    i = a; k = 0;
    while(i <= d) A[i++] = B[k++];
}

void merge_sort(int start, int end, int A[]){
    if(start < end){
        int mid = (start+end)/2;
        merge_sort(start, mid, A);
        merge_sort(mid+1, end, A);
        merge_count(start, mid, mid+1, end, A);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i;
    cin >> N;

    int A[N];
    for(i=0;i<N;i++)
        cin >> A[i];

    // timeout
    // cout << bubble_sort(A, N);
    merge_sort(0, N-1, A);
    count_swap /= 2;

    cout << count_swap;

    return 0;
}

