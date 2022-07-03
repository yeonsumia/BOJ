#include<iostream>
#include<cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2, 2)+pow(y1-y2,2));
}

double one_third(double x1, double x2){
    return x1 + (x2 - x1)/3;
}

double two_thirds(double x1, double x2){
    return x1 + 2*(x2 - x1)/3;
}

double ternary_search(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy){
    if(distance(ax,ay,bx,by) > pow(10, -8)){
        double one_third_ax = one_third(ax, bx);
        double one_third_ay =  one_third(ay, by);
        double one_third_cx = one_third(cx, dx);
        double one_third_cy = one_third(cy, dy);
        double two_thirds_ax = two_thirds(ax, bx);
        double two_thirds_ay = two_thirds(ay, by);
        double two_thirds_cx = two_thirds(cx, dx);
        double two_thirds_cy = two_thirds(cy, dy);
        double one_third_distance = distance(one_third_ax, one_third_ay, one_third_cx, one_third_cy);
        double two_thirds_distance = distance(two_thirds_ax, two_thirds_ay, two_thirds_cx, two_thirds_cy);
        if(one_third_distance > two_thirds_distance)
            return ternary_search(one_third_ax, one_third_ay, bx, by, one_third_cx, one_third_cy, dx, dy);
        else
            return ternary_search(ax, ay, two_thirds_ax, two_thirds_ay, cx, cy, two_thirds_cx, two_thirds_cy);
    }
    double d = distance(ax, ay, cx, cy);
    return  d > pow(10, -6) ? d : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(11);

    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    cout << ternary_search(ax, ay, bx, by, cx, cy, dx, dy);

    return 0;
}