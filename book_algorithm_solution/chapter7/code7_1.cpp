#include <iostream>
#include <vector>
using namespace std;

int main() {
    // コインの金額
    const vector<int> value = {500, 100, 50, 10, 5, 1};

    int X;
    vector<int> a(value.size());

    cin >> X;
    for(int i = 0; i < value.size(); i++) {
        cin >> a[i];
    }

    // 貪欲法
    int result = 0;
    for(int i = 0; i < 6; i++) {
        // 枚数制限がない場合の枚数
        int add = X / value[i];

        // 枚数制限を考慮
        if(add > a[i]) {
            add = a[i];
        }

        X -= value[i] * add;
        result += add;
    }

    cout << result << endl;
}