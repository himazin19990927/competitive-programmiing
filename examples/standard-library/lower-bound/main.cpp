#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void show_array(const vector<int> &A) {
    cout << "A = [";
    for(int i = 0; i < (int)A.size(); i++) {
        cout << " " << A[i];
    }
    cout << "]" << endl;
}

void search(const vector<int> &A, int key) {
    auto result = lower_bound(A.begin(), A.end(), key);
    int index = result - A.begin();
    int value = *result;
    cout << "key = " << key << ", A[" << index << "] = " << value << endl;
}

int main() {
    vector<int> A = {3, 5, 8, 10, 14, 17, 21, 39};

    show_array(A);
    search(A, 1);
    search(A, 3);
    search(A, 16);
    search(A, 17);
    search(A, 18);
    search(A, 40);
}