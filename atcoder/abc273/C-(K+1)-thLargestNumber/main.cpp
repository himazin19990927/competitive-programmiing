#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // XはAをソートして、重複した要素を削除したもの
    vector<int64_t> X(A);
    sort(X.begin(), X.end());
    vector<int64_t>::iterator res = unique(X.begin(), X.end());
    X.erase(res, X.end());

    // B[i]: A[i]より大きい要素の数
    vector<int64_t> B(N);   
    for(int i = 0; i < N; i++) {
        B[i] = (X.end() - upper_bound(X.begin(), X.end(), A[i]));
    }

    // C[i]: A[i]より大きい要素の数がちょうどi種類である場合の数
    vector<int64_t> C(N, 0);
    for(int i = 0; i < N; i++) {
        C[B[i]] += 1;
    }

    for(int i = 0; i < N; i++) {
        cout << C[i] << endl;
    }
}