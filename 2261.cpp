#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Point{
public:
    int x;
    int y;
    Point(int x, int y){ this->x = x; this->y = y; }
    bool operator<(const Point& other) const{
        if(x != other.x) return x < other.x;
        else return y < other.y;
    }
};

int square_distance(Point a, Point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int brute_force_min_square_distance(int start, int end, const vector<Point>& v){
    int i, j, min_square_distance = square_distance(v[start],v[start+1]);
    for(i=start;i<end;i++){
        for(j=i+1;j<=end;j++){
            int sq_distance = square_distance(v[i], v[j]);
            if(min_square_distance > sq_distance){
                min_square_distance = sq_distance;
            }
        }
    }
    return min_square_distance;
}

int mid_min_square_distance(int start, int end, int mid, int min_sq_d, const vector<Point>& v){
    vector<Point> u;
    int i, j;
    for(i=start;i<=end;i++){
        int del_x = v[i].x - v[mid].x;
        if(del_x * del_x < min_sq_d) u.push_back(v[i]);
    }
    sort(u.begin(), u.end(), [](const Point& p, const Point& q){ return p.y < q.y; });
    // swipe
    for(i=0;i<u.size();i++){
        for(j=i+1;j<u.size() && (u[j].y - u[i].y) * (u[j].y - u[i].y) <= min_sq_d;j++){
            int sq_d = square_distance(u[i], u[j]);
            if(sq_d < min_sq_d)
                min_sq_d = sq_d;
        }
    }
    return min_sq_d;
}

int min_square_distance(int start, int end, const vector<Point>& v){
    if(end - start + 1 <= 3){
        return brute_force_min_square_distance(start, end, v);
    }
    int mid = (start+end)/2;
    int min_sq_distance = min(min_square_distance(start, mid, v), min_square_distance(mid+1, end, v));

    return mid_min_square_distance(start, end, mid, min_sq_distance, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, x, y;
    cin >> n;

    vector<Point> points;
    for(i=0;i<n;i++){
        cin >> x >> y;
        points.emplace_back(x,y);
    }
    sort(points.begin(), points.end());

    cout << min_square_distance(0, n-1, points);

    return 0;
}