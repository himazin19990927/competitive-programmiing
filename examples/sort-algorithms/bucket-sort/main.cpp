#include <iostream>
#include <vector>
using namespace std;

template <class T> void show_vector(const vector<T> &a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <class T> void bucket_sort(vector<T> &a, T max) {
    int N = (int)a.size();

    // 各要素の個数をカウントする
    // num[v]: vの個数
    vector<int> num(max, 0);
    for(int i = 0; i < N; i++) {
        num[a[i]] += 1; // a[i]をカウント
    }

    // numの累積和を取る
    // sum[v]: v以下の値の個数
    // 値a[i]が全体の中で何番目に小さいかを求める
    vector<int> sum(max, 0);
    sum[0] = num[0];
    for(int v = 1; v < max; v++) {
        sum[v] = sum[v - 1] + num[v];
    }

    // sumをもとにソート処理
    // sorted: aをソートしたもの
    vector<int> sorted(N);
    for(int i = N - 1; i >= 0; i--) {
        sum[a[i]] -= 1;
        sorted[sum[a[i]]] = a[i];
    }

    // ソート済みのものをaとする
    a = sorted;
}

int main() {
    // 入力
    int N, MAX;
    cin >> N >> MAX;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    bucket_sort(a, MAX);
    show_vector(a);
}