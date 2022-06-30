#include <cmath>
#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }

    if (n == 2 || n == 3) {
        return true;
    }

    if (n % 2 == 0) {
        return false;
    }

    const int square_root = (int)sqrt(n);
    for (int i = 3; i <= square_root; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    if (is_prime(n)) {
        cout << n << " is prime." << endl;
    } else {
        cout << n << " is not prime." << endl;
    }
}