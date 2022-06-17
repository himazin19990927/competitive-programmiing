#include <iostream>
#include <vector>
using namespace std;

template <class T> void show_vector(const vector<T> &a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <class T> void insertion_sort(vector<T> &a) {
    int N = (int)a.size();
    for(int i = 1; i < N; i++) {
        // 挿入したい値
        T v = a[i];

        // vを挿入する適切な場所jを探す
        int j = i;
        for(; j > 0; j--) {
            if(a[j - 1] > v) {
                // vより大きいものは1つ後ろに移す
                a[j] = a[j - 1];
            } else {
                // a[j-1]がv以下になったら止める
                break;
            }
        }
        // j番目にvを持ってくる
        a[j] = v;
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

    insertion_sort(a);
    show_vector(a);
}