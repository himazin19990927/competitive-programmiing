#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix product(const Matrix &left, const Matrix &right) {
    const int left_M = left.size();
    const int left_N = left[0].size();

    const int right_M = right.size();
    const int right_N = right[0].size();

    if(left_N != right_M) {
        throw invalid_argument("Matrix size is invalid.");
    }

    Matrix result(left_M, vector<int>(right_N, 0));

    for(int m = 0; m < left_M; m++) {
        for(int n = 0; n < right_N; n++) {
            for(int i = 0; i < left_N; i++) {
                result[m][n] += left[m][i] * right[i][n];
            }
        }
    }

    return result;
}

void show_matrix(const Matrix &matrix) {
    const int M = matrix.size();
    const int N = matrix[0].size();

    cout << "[";
    for(int m = 0; m < M; m++) {
        cout << "[";
        for(int n = 0; n < N; n++) {
            cout << matrix[m][n];

            if(n != N - 1) {
                cout << ", ";
            }
        }
        cout << "]";

        if(m != M - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    Matrix a = {{1, 2}, {3, 4}};
    Matrix b = {{5, 6}, {7, 8}};

    Matrix c = product(a, b);
    show_matrix(c);
}