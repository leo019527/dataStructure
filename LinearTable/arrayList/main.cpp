#include <iostream>
#include "mArrayList.h"

using namespace std;

int main() {
    mArrayList<int> *a = new mArrayList<int>{};
    int as[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    a->add(as, 9);
    a->print();
    a->drop(5,5);
    a->print();
    cout << a->get(1) << endl;
    a->set(0,9);
    a->print();
    return 0;
}