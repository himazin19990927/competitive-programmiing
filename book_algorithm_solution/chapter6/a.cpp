#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const vector<int> v = {1, 4, 4, 5, 6, 34};

    int k = 4;
    int i = lower_bound(v.begin(), v.end(), k) - v.begin();
    cout << i << endl;
}