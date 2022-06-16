#include <iostream>
#include <vector>
using namespace std;

// 目的の値keyの添字を返す(存在しない場合は-1)
int binary_search(const vector<int> &a, int key) {
    int left = 0;
    int right = (int)a.size() - 1;

    while(right >= left) {
        int mid = left + (right - left) / 2;
        if(a[mid] == key) {
            return mid;
        } else if(a[mid] > key) {
            right = mid - 1;
        } else if(a[mid] < key) {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    const vector<int> a = {3, 5, 8, 10, 14, 17, 21, 39};
    cout << binary_search(a, 10) << endl;
    cout << binary_search(a, 3) << endl;
    cout << binary_search(a, 39) << endl;


    cout << binary_search(a, -100) << endl;
    cout << binary_search(a, 9) << endl;
    cout << binary_search(a, 100) << endl;

}