#include <iostream>
#include <vector>
using namespace std;
// 競プロ典型 90 問
// 001-Yokan Party
// https://atcoder.jp/contests/typical90/tasks/typical90_a

// 左右の長さが L [cm] のようかんがあります。
// N 個の切れ目が付けられており、左から i 番目の切れ目は左から A[i] [cm] の位置にあります。
// あなたは N 個の切れ目のうち K 個を選び、ようかんを K+1 個のピースに分割したいです。
//
// そこで、以下の値を スコア とします。
// K+1 個のピースのうち、最も短いものの長さ（cm 単位）
//
// スコアが最大となるように分割する場合に得られるスコアを求めてください。


int main() {
    int N, L, K;
    cin >> N >> L >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 答えを二分探索
    int left = -1;
    int right = L + 1;
    while(right - left > 1) {
        // 全てのピースの大きさがmid以上に出来るように分割する
        // このように分割したとき、切れ目の数がK以上あれば条件を満たす
        int mid = left + (right - left) / 2;

        // 切断回数
        int count = 0;
        // 前回の切断面
        int pre = 0;

        for(int i = 0; i < N; i++) {
            // A[i]個目の切れ目を使って、ピースの大きさをmid以上に出来る場合のみ
            // A[i]個目の切れ目を採用
            if(A[i] - pre >= mid && L - A[i] >= mid) {
                count += 1;
                pre = A[i];
            }
        }

        if(count >= K) {
            // K個以上の切れ目全てを使っている場合、もう少し余裕がある
            // 最小のピースの大きさは、mid以上、right未満である
            left = mid;
        } else {
            // K個の切れ目を使い切れない場合、ピースの大きさの条件を緩める必要がある
            // 最小ののピースの大きさはleft以上、mid未満である
            right = mid;
        }
    }

    cout << left << endl;
}