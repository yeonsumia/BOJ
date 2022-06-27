#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int generate_next(int A, int p){
    int next = 0;
    while(A != 0){
        next += (int) pow(A % 10, p);
        A /= 10;
    }
    return next;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, p, current;
    vector<int> seq;
    cin >> A >> p;

    current = A;
    while(find(seq.begin(),seq.end(),current)==seq.end()){
        seq.push_back(current);
        current = generate_next(current, p);
    }

    cout << find(seq.begin(),seq.end(),current) - seq.begin() << "\n";
    return 0;
}