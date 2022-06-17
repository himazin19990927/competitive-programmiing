#include <iostream>
#include <vector>
using namespace std;

template <class T> void show_vector(const vector<T> &a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// 配列aの区間[left, right)をソートする
// [left, right)はleft, left+1, ..., right-1を表す
template <class T> void merge_sort(vector<T> &a, int left, int right) {
    // 区間幅が1の場合はソートする必要がない
    if(right - left == 1) {
        return;
    }

    int mid = left + (right - left) / 2;

    // 左半分 [left, mid)をソート
    merge_sort(a, left, mid);

    // 右半分 [mid, right)をソート
    merge_sort(a, mid, right);

    // 右半分と左半分のソート結果を保存する
    // 右半分は左右反転して保存する
    vector<T> buf;
    for(int i = left; i < mid; ++i) {
        buf.push_back(a[i]);
    }
    for(int i = right - 1; i >= mid; i--) {
        buf.push_back(a[i]);
    }

    // マージする
    int index_left = 0;                    // 左側の添字
    int index_right = (int)buf.size() - 1; // 右側の添字
    for(int i = left; i < right; i++) {
        if(buf[index_left] <= buf[index_right]) {
            // 左側を採用
            a[i] = buf[index_left];
            index_left += 1;
        } else {
            // 右側を採用
            a[i] = buf[index_right];
            index_right -= 1;
        }
    }
}

int main() {
    // 入力
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    merge_sort(a, 0, N);
    show_vector(a);
}