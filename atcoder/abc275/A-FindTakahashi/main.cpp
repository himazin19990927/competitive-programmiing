#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

int main() {
    int N;
    cin >> N;

    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int max_index = 0;
    for(int i = 0; i < N; i++) {
        if(H[max_index] < H[i]) {
            max_index = i;
        }
    }
    cout << max_index + 1 << endl;;
}