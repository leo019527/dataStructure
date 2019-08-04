#include "stack.h"

int main() {
    Stack<int> a;
    a.push(1);
    a.push(2);
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    return 0;
}