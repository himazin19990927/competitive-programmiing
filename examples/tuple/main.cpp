#include <iostream>
#include <string>
#include <tuple>
using namespace std;

int main() {
    tuple<string, int> person{"Bob", 20};

    tuple<string &, int &> person_ref{get<0>(person), get<1>(person)};

    person_ref = tuple<string, int>{"A", 99};

    string name;
    int age;
    tie(name, age) = person;

    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
}
