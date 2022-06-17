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
template <class T> void quick_sort(vector<T> &a, int left, int right) {
    //区間幅が1以下の場合はソートする必要がない
    if(right - left <= 1) {
        return;
    }

    int pivot_index = (left + right) / 2; // 中点とする(適当)
    int pivot = a[pivot_index];
    // pivotと右端をswap
    swap(a[pivot_index], a[right - 1]);

    int i = left; // iは左詰めされたpivot未満要素の右端
    for(int j = left; j < right - 1; j++) {
        if(a[j] < pivot) {
            // pivot未満の要素があれば左に詰めていく
            swap(a[i], a[j]);
            i += 1;
        }
    }

    // 右端にあるpivotを適切な場所に挿入
    // このとき,iは<pivot未満の要素の右端+1>を指している
    swap(a[i], a[right - 1]);

    // 再帰的に解く
    quick_sort(a, left, i);      // 左半分(pivot未満の要素)
    quick_sort(a, i + 1, right); // 右半分(pivot以上の要素)
}

int main() {
    // 入力
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    quick_sort(a, 0, N);
    show_vector(a);
}