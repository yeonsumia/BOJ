#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool binary_search(int start, int end, int num, const vector<int>& key){
    if(start <= end){
        int mid = (start+end)/2;
        if(num == key[mid]) return true;
        else if(num > key[mid]) return binary_search(mid+1, end, num, key);
        else return binary_search(start, mid-1, num, key);
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

    map<int, int> card;
    for(i=0;i<N;i++){
        cin >> x;
        if(card.find(x) != card.end()) card[x]++;
        else card.emplace(x, 1);
    }

    vector<int> key;
    key.reserve(card.size());
    for(auto& it : card)
        key.push_back(it.first);

    cin >> M;
    int target;
    for(i=0;i<M;i++){
        cin >> target;
        if(binary_search(0, (int) card.size()-1, target, key)) cout << card[target] << " ";
        else cout << 0 << " ";
    }

    return 0;
}