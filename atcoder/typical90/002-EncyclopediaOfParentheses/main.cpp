#include <iostream>
#include <vector>
using namespace std;

// 競プロ典型 90 問
// 002-Encyclopedia of Parentheses
// https://atcoder.jp/contests/typical90/tasks/typical90_b

// 問題文
// 長さ N の正しいカッコ列をすべて、辞書順に出力してください。

// ただし、正しいカッコ列は次のように定義されています :

// () は正しいカッコ列である
// S が正しいカッコ列であるとき、文字列 ( +S+ ) は正しいカッコ列である
// S,T が正しいカッコ列であるとき、文字列 S+T は正しいカッコ列である
// それ以外の文字列はすべて、正しいカッコ列でない
// 例えば、

// ()()
// (()())(())
// ()()()()()()()()
// は正しいカッコ列ですが、

// )(
// )))()(((
// ((((a))))
// は正しいカッコ列ではありません。

// また、 ( の方が ) よりも辞書順で早いものとします。

int main() {
    int N;
    cin >> N;

    // 長さが奇数の正しいカッコ列を作ることはできない
    if(N % 2 == 1) {
        return 0;
    }

    // 0: "(", 1: ")"として全探索
    for(int i = 0; i < (1 << N); i++) {
        bool ok = true;

        int open = 0;
        int close = 0;
        for(int j = N - 1; j >= 0; j--) {
            if(i & (1 << j)) {
                // jビット目が")"の場合
                close += 1;
            } else {
                // jビット目が"("の場合
                open += 1;
            }

            if(open < close) {
                // "("の数よりも")"の数が多い場合、カッコが対応していない
                ok = false;
                break;
            }
        }

        // "("の数と")"の数が一致しない場合、カッコが対応していない
        if(open != close) {
            ok = false;
        }

        if(ok) {
            for(int j = N - 1; j >= 0; j--) {
                if(i & (1 << j)) {
                    // jビット目が")"の場合
                    cout << ")";
                } else {
                    // jビット目が"("の場合
                    cout << "(";
                }
            }
            cout << endl;
        }
    }
}