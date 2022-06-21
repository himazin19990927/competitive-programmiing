#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;

    double get_angle() {
        double angle = atan2(y, x) * 180.0 / M_PI;
        if(angle < 0) {
            angle = 360.0 + angle;
        }

        return angle;
    }
};

Point operator-(const Point &a1, const Point &a2) {
    return Point{a1.x - a2.x, a1.y - a2.y};
}

double get_angle_2(double i1, double i2) {
    double res = abs(i1 - i2);
    if(res >= 180) {
        return 360.0 - res;
    }

    return res;
}

double solve(const vector<Point> &G, int pos) {
    // posを中心とした、各辺の偏角を求め、ソートする
    vector<double> v;
    for(int i = 0; i < (int)G.size(); i++) {
        if(i == pos) {
            continue;
        }

        double angle = (G[i] - G[pos]).get_angle();
        v.push_back(angle);
    }
    sort(v.begin(), v.end());

    // 点Aを全探索して、最も偏角が大きくなる点Cを求める
    double res = 0;
    for(int i = 0; i < (int)v.size(); i++) {
        double target = v[i] + 180.0;
        if(target >= 360.0) {
            target -= 360.0;
        }

        int pos1 = lower_bound(v.begin(), v.end(), target) - v.begin();

        // 点Cの候補は高々2に絞れる
        int candIdx1 = pos1 % v.size();
        int candIdx2 = (pos1 + v.size() - 1) % v.size();

        double cand1 = get_angle_2(v[i], v[candIdx1]);
        double cand2 = get_angle_2(v[i], v[candIdx2]);
        res = max({res, cand1, cand2});
    }

    return res;
}

double solve_fast(const vector<Point> &G) {
    // 点Bを全探索
    double ans = 0;
    for(int i = 0; i < (int)G.size(); i++) {
        double res = solve(G, i);
        ans = max(ans, res);
    }

    return ans;
}

int main() {
    // 点の数N
    int N;
    cin >> N;

    vector<Point> G(N);

    // 点iの座標X[i], Y[i]
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) {

        cin >> G[i].x >> G[i].y;
    }

    double ans = solve_fast(G);
    cout << setprecision(15) << ans << endl;
}