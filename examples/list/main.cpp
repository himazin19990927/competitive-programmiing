#include <iostream>
#include <list>

template <class T> void print_list(const std::list<T> &ls) {
    auto iter = ls.begin();
    std::cout << "[" << *iter;
    iter++;

    for(; iter != ls.end(); iter++) {

        std::cout << ", " << *iter;
    }

    std::cout << "]" << std::endl;
}

int main() {
    std::list<int> ls;

    // 先頭から要素を追加
    ls.push_front(1);
    ls.push_front(2);

    // 末尾から要素を追加
    ls.push_back(3);
    ls.push_back(4);

    print_list(ls);
}