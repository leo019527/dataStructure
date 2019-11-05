#include <iostream>
#include <list>
#include <cstdio>

using namespace std;

typedef struct {
    float coef;//系数
    int expn;//指数
} term, *pTerm;

typedef list<term> polynomial;

void CreatPolyn(polynomial &p) {
    pTerm head = (pTerm) malloc(sizeof(term));
    head->coef = 0.0;
    head->expn = -1;
    p.push_back(*head);
}

void DestroyPolyn(polynomial &p) {
    p.erase(p.begin(), p.end());
}

void PrintPolyn(polynomial p) {
    cout << "f(x) = ";
    polynomial::iterator iter;
    for (iter = p.begin(); iter != p.end(); iter++) {
        cout << iter->coef << "^" << iter->expn << " + ";
    }
    printf("\b\b  ");//删除最后的加号
    cout << endl;
}

int PolynLength(polynomial p) {
    return p.size();
}

void AddPolyn(polynomial &a, polynomial &b) {
    int tmpA=0,tmpB=0;
    //TODO:
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}