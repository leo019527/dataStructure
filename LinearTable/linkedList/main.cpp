#include "LinkedList.h"
int main() {
    LinkedList<int> a;
    a.add(1);
    a.add(2);
    a.add(9,0);
    a.print();
    a.add(8,1);
    a.print();
    a.set(6,0);
    a.print();
    a.drop(1);
    a.print();
    return 0;
}