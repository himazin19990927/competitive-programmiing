#include <iostream>
#include <vector>
using namespace std;

template <class T> void show_vector(const vector<T> &a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// i番目の頂点を根とする部分木について、ヒープ条件をみたすようにする
// aのうち0番目からN-1番目の部分a[0:N]についてのみ考える
template <class T> void heapify(vector<T> &a, int i, int N) {
    int child1 = i * 2 + 1; // iの左の子供
    if(child1 >= N) {
        // iの子供が存在しない場合は終了
        return;
    }

    // 子供同士を比較し、大きい方をchild1として取得
    if(child1 + 1 < N && a[child1 + 1] > a[child1]) {
        child1 += 1;
    }

    if(a[child1] <= a[i]) {
        // 逆転がなければ終了
        return;
    }

    // swap
    swap(a[i], a[child1]);

    // 再帰的に処理
    heapify(a, child1, N);
}

template <class T> void heap_sort(vector<T> &a) {
    int N = (int)a.size();
    // ステップ1: a全体をヒープにする
    for(int i = N / 2; i >= 0; i--) {
        heapify(a, i, N);
    }

    // ステップ2: ヒープから1一つずつ最大値をpopする
    for(int i = N - 1; i > 0; i--) {
        // ヒープの最大値は0番目であるため、一番最後の要素と交換
        swap(a[0], a[i]);

        // aのうち、0番目からi-1番目までをヒープとする
        heapify(a, 0, i);
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

    heap_sort(a);
    show_vector(a);
}