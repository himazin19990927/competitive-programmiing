#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    // S = atcoder 
    //     0123456N
    //     |   |
    //     cur |
    //         search_until = N - (k + 1)
    // 部分文字列の長さは K
    //  k 文字目まで、部分文字列は決定

    // カーソル
    int cursor = 0;
    for (int k = 0; k < K; k++) {
        // k文字目まで部分文字列は決まっている
        // 残りの決めるべき文字数
        int remain = K - (k + 1);
        int search_until = N - remain;

        int min_id = cursor;
        for (int i = cursor; i < search_until; i++) {
            // カーソルからN - k文字目までの中で、辞書順最小の文字を探す
            if (S[min_id] > S[i]) {
                min_id = i;
            }
        }
        cout << S[min_id];
        cursor = min_id + 1;
    }

    cout << endl;
}
