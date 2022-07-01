#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary_search_max_height(int start, int end, int height, const vector<int>& tree, int M){
    if(start <= end){
        int mid = (start+end)/2;
        long sum = 0;
        for(int h: tree) sum += max(h-mid, 0);
        if(sum >= M) height = binary_search_max_height(mid+1, end, mid, tree, M);
        else height = binary_search_max_height(start, mid-1, height, tree, M);
    }
    return height;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int i, x;
    cin >> N >> M;

    vector<int> tree;
    int max_height;
    for(i=0;i<N;i++){
        cin >> x;
        tree.push_back(x);
    }
    max_height = *max_element(tree.begin(), tree.end());

    cout << binary_search_max_height(0, max_height, max_height, tree, M);

    return 0;
}