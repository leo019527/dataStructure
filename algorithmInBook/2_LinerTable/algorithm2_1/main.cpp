#include <iostream>

using namespace std;

/*
 * 有序合并两个有序列表
 */
void mergeList(int *a, int lengthA, int *b, int lengthB, int *c) {
    int i = 0, j = 0, k = 0;
    while (i < lengthA && j < lengthB) {
        if (a[i]<=b[j]){
            c[k] = a[i];
            i++;
        }else{
            c[k] = b[j];
            j++;
        }
        k++;
    }
    if (i != lengthA) {
        for (; i < lengthA; i++) {
            c[k] = a[i];
            k++;
        }
    } else {
        for (; j < lengthB; j++) {
            c[k] = b[j];
            k++;
        }
    }
}

int main() {
    int a[4] = {3, 5, 8, 11};
    int b[7] = {2, 6, 8, 9, 11, 15, 20};
    int c[11] = {};
    mergeList(a, 4, b, 7, c);
    for (int i:c) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}