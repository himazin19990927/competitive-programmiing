#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

struct CharLen {
    char c;
    int len;
};

vector<CharLen> lex(const string &s) {
    vector<CharLen> result;

    CharLen prev = {s[0], 1};

    for(size_t i = 1; i < s.length(); i++) {
        if(prev.c == s[i]) {
            prev.len += 1;
        } else {
            result.push_back(prev);
            prev = {s[i], 1};
        }
    }

    result.push_back(prev);

    return result;
}

bool check(const vector<CharLen> &S, const vector<CharLen> &T) {
    if(S.size() != T.size()) {
        return false;
    }

    for(size_t i = 0; i < S.size(); i++) {
        if(S[i].c != T[i].c) {
            return false;
        }

        if(S[i].len > T[i].len) {
            return false;
        }

        if(S[i].len == 1 && T[i].len != 1) {
            return false;
        }
    }

    return true;
}

int main() {
    string S, T;
    cin >> S >> T;

    auto S_l = lex(S);
    auto T_l = lex(T);

    if(check(S_l, T_l)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}