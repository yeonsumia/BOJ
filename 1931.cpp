#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Meet{
public:
    int start, end;
    Meet(int start, int end){
        this->start = start;
        this->end = end;
    }
    bool operator<(const Meet& other) const{
        if(this->end != other.end) return this->end < other.end;
        else return this->start < other.start;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i;
    cin >> N;

    int start, end;
    vector<Meet> meet;
    for(i=0;i<N;i++){
        cin >> start >> end;
        meet.emplace_back(start, end);
    }
    sort(meet.begin(), meet.end());

    int end_time = 0, count_meet = 0;
    for(auto& it : meet){
        if(end_time <= it.start){
            count_meet++;
            end_time = it.end;
        }
    }

    cout << count_meet;

    return 0;
}