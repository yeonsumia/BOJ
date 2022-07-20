#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int count_case;

bool check_prime(int p){
    if(p == 1) return false;
    if(p == 2) return true;
    if(p % 2 == 0) return false;
    for(int i=3;i<=sqrt(p);i+=2){
        if(p % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i;
    cin >> N;

    vector<int> prime_nums;
    prime_nums.push_back(2);
    for(i=3;i<=N;i+=2){
        if(check_prime(i)) prime_nums.push_back(i);
    }

    int p1 = 0, p2 = 0;
    int sum = prime_nums[p2];
    while(p2 <= prime_nums.size()-1 && prime_nums[p2] <= N){
        if(sum == N){
            count_case++;
            sum -= prime_nums[p1++];
        }
        else if(sum < N){
            if(p2 < prime_nums.size()-1) sum += prime_nums[++p2];
            else p2++;
        }
        else sum -= prime_nums[p1++];
    }

    cout << count_case;

    return 0;
}