#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int min_value = INT_MAX;
    for(int i = 0; i < N; i++) {
        if(a[i] < min_value) {
            min_value = a[i];
        }
    }

    cout << min_value << endl;
}