#include <iostream>
#include <vector>
using namespace std;

template <class T> struct Heap {
    vector<T> heap;
    Heap() {}

    // 値を挿入
    void push(T x) {
        heap.push_back(x);            // 最後尾に挿入
        int i = (int)heap.size() - 1; // 挿入された頂点番号
        while(i > 0) {
            int p = (i - 1) / 2; // 親の頂点番号
            if(heap[p] >= x) {
                // 挿入した値が親より小さければ終了
                break;
            }

            heap[i] = heap[p]; // 自身の値を親の値にする
            i = p;             // 頂点番号を親のものに更新
        }
        heap[i] = x;
    }

    // 最大値を取得
    // ヒープが空の場合の挙動は未定義
    T top() { return heap[0]; }

    // 最大値をポップ
    // ヒープが空の場合の挙動は未定義
    T pop() {
        T x = heap.back(); // 最後の要素を取得
        heap.pop_back();

        T max = heap[0]; // 最大値を取得
        int i = 0;       // 根から下ろしていく
        while(i * 2 + 1 < (int)heap.size()) {
            // iの子頂点同士を比較して、大きい方をchild1として取得する
            int child1 = i * 2 + 1;
            int child2 = i * 2 + 2;
            if(child2 < (int)heap.size() && heap[child2] > heap[child1]) {
                child1 = child2;
            }

            if(heap[child1] <= x) {
                // 逆転がなければ終了
                break;
            }

            heap[i] = heap[child1]; // 自分の値を子頂点の値にする
            i = child1;
        }
        heap[i] = x; // xは最終的にこの位置に持ってくる

        return max;
    }
};

int main() {
    Heap<int> h;
    h.push(5);
    h.push(3);
    h.push(7);
    h.push(1);

    cout << h.pop() << endl; // 7
    cout << h.pop() << endl; // 5

    h.push(11);
    cout << h.pop() << endl; // 11
}