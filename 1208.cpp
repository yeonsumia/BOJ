#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int N, S;
vector<int> num;
bool visit[40];
long long count_case;
vector<int> A, B;
vector<int> combination;
map<int,int> A_num, B_num;

int sum(){
    int s = 0;
    for(int i: combination) s += i;
    return s;
}

void backtracking_front(int idx){
    combination.push_back(num[idx]);
    visit[idx] = true;
    A.push_back(sum());
    for(int i=idx+1;i<N/2;i++) if(!visit[i]) backtracking_front(i);
    combination.pop_back();
    visit[idx] = false;
}

void backtracking_back(int idx){
    combination.push_back(num[idx]);
    visit[idx] = true;
    B.push_back(sum());
    for(int i=idx+1;i<N;i++) if(!visit[i]) backtracking_back(i);
    combination.pop_back();
    visit[idx] = false;
}

void binary_search_a(int start, int end, int n){
    while(start <= end){
        int mid = (start+end)/2;
        if(A[mid] == n){
            count_case += A_num[n];
            break;
        }
        else if(A[mid] > n) end = mid-1;
        else start = mid+1;
    }
}

void binary_search_b(int start, int end, int n){
    while(start <= end){
        int mid = (start+end)/2;
        if(B[mid] == n){
            count_case += B_num[n];
            break;
        }
        else if(B[mid] > n) end = mid-1;
        else start = mid+1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, x;
    cin >> N >> S;

    for(i=0;i<N;i++){
        cin >> x;
        num.push_back(x);
    }

    for(i=0;i<N/2;i++) backtracking_front(i);
    for(i=N/2;i<N;i++) backtracking_back(i);

    // A.size() = 1<<(N/2)-1
    // B.size() = (1<<((N+1)/2))-1
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(i=0;i<A.size();i++) A_num[A[i]]++;
    for(i=0;i<B.size();i++) B_num[B[i]]++;

    // A>=1, B>=1
    for(i=0;i<A.size();i++)
        binary_search_b(0, B.size()-1, S-A[i]);
    // A=0, B>=1
    binary_search_b(0, B.size()-1, S);
    // B=0, A>=1
    binary_search_a(0, A.size()-1, S);

    cout << count_case;

    return 0;
}