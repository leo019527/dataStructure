#include "BiTree.h"

int main() {
    BiTree *a = new BiTree();
    a->setTestTree();
    a->recursionErgodicFirst();
    cout << endl << endl;
    a->recursionErgodicMiddle();
    cout << endl << endl;
    a->recursionErgodicBack();
    cout << endl << endl;
    a->unRecursionErgodicFirst();
    cout << endl << endl;
    a->unRecursionErgodicMiddle();
    cout << endl << endl;
    a->unRecursionErgodicBack();
    cout << endl << endl;
    return 0;
}