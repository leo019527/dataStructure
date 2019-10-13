//
// Created by 李凌耀 on 2019/10/12.
//

#ifndef BITREE_BITREE_H
#define BITREE_BITREE_H

#include <iostream>
#include <stack>
#include "BiNode.h"

using namespace std;

class BiTree {
public:
    BiNode *root;
    BiTree();
    //生成测试用树
    void setTestTree();

    //递归遍历
    /**
     * 先序递归遍历
     */
    void recursionErgodicFirst();

    void fun1(BiNode *p);

    /**
     * 中序递归遍历
     */
    void recursionErgodicMiddle();

    void fun2(BiNode *p);

    /**
     * 后序递归遍历
     */
    void recursionErgodicBack();

    void fun3(BiNode *p);

    //非递归方法
    /**
     * 前序非递归遍历
     */
    void unRecursionErgodicFirst();

    /**
     * 中序非递归遍历
     */
    void unRecursionErgodicMiddle();

    /**
     * 后续非递归遍历
     */
    void unRecursionErgodicBack();

};





#endif //BITREE_BITREE_H
