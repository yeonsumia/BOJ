#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool binary_search(int start, int end, int num, const vector<int>& card){
    if(start <= end){
        int mid = (start+end)/2;
        if(num == card[mid]) return true;
        else if(num > card[mid]) return binary_search(mid+1, end, num, card);
        else return binary_search(start, mid-1, num, card);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int i, x;
    cin >> N;

    vector<int> card;
    for(i=0;i<N;i++){
        cin >> x;
        card.push_back(x);
    }
    sort(card.begin(), card.end());

    cin >> M;
    int target;
    for(i=0;i<M;i++){
        cin >> target;
        cout << (binary_search(0, N-1, target, card) ? 1 : 0) << " ";
    }

    return 0;
}