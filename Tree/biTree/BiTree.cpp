//
// Created by 李凌耀 on 2019/10/12.
//

#include "BiTree.h"

BiTree::BiTree() {
    this->root = nullptr;
}

void BiTree::setTestTree() {
    this->root = new BiNode(1);
    this->root->setLchild(new BiNode(2));
    this->root->setRchild(new BiNode(3));
    this->root->getLchild()->setLchild(new BiNode(4));
    this->root->getLchild()->setRchild(new BiNode(5));
    this->root->getRchild()->setLchild(new BiNode(6));
    this->root->getRchild()->setRchild(new BiNode(7));
}

void BiTree::recursionErgodicFirst() {
    cout << "先序递归遍历" << endl;
    this->fun1(this->root);
    cout << endl;
}

void BiTree::fun1(BiNode *p) {
    if(p== nullptr){
        return;
    }
    cout << p->getData() << ", ";
    fun1(p->getLchild());
    fun1(p->getRchild());
}

void BiTree::recursionErgodicMiddle() {
    cout << "中序递归遍历" << endl;
    this->fun2(this->root);
    cout << endl;
}

void BiTree::fun2(BiNode *p) {
    if(p== nullptr){
        return;
    }
    fun2(p->getLchild());
    cout << p->getData() << ", ";
    fun2(p->getRchild());
}

void BiTree::recursionErgodicBack() {
    cout << "后序递归遍历" << endl;
    this->fun3(this->root);
    cout << endl;
}

void BiTree::fun3(BiNode *p) {
    if(p== nullptr){
        return;
    }
    fun3(p->getLchild());
    fun3(p->getRchild());
    cout << p->getData() << ", ";
}

void BiTree::unRecursionErgodicFirst() {
    cout << "先序非递归遍历" << endl;
    stack<BiNode *> *s = new stack<BiNode *>();
    s->push(this->root);
    BiNode *tmp;
    tmp = this->root;
    cout << tmp->getData() << ", ";
    while(!s->empty()){
        tmp = s->top();
        while(tmp->getLchild()!= nullptr){
            s->push(tmp->getLchild());
            cout << tmp->getLchild()->getData() << ", ";
            tmp = tmp->getLchild();
        }
        tmp = s->top();
        s->pop();
        if(!s->empty()) {
            //最后一次遍历时栈为空不能弹出
            tmp = s->top();
            s->pop();
        }
        if(tmp->getRchild()!= nullptr){
            s->push(tmp->getRchild());
            cout << tmp->getRchild()->getData() << ", ";
        }
    }
    cout << endl;
}

void BiTree::unRecursionErgodicMiddle() {
    cout << "中序非递归遍历" << endl;
    stack<BiNode *> *s = new stack<BiNode *>();
    s->push(this->root);
    BiNode *tmp;
    tmp = this->root;
    while(!s->empty()){
        tmp = s->top();
        while(tmp->getLchild()!= nullptr){
            s->push(tmp->getLchild());
            tmp = tmp->getLchild();
        }
        tmp = s->top();
        cout << tmp->getData() << ", ";
        s->pop();
        if(!s->empty()) {
            //最后一次遍历时栈为空不能弹出
            tmp = s->top();
            cout << tmp->getData() << ", ";
            s->pop();
        }
        if(tmp->getRchild()!= nullptr){
            s->push(tmp->getRchild());
        }
    }
    cout << endl;
}

void BiTree::unRecursionErgodicBack() {
    cout << "后序非递归遍历" << endl;
    stack<BiNode *> *stack1 = new stack<BiNode *>();
    BiNode *node = this->root;
    stack<BiNode *> *output = new stack<BiNode *>();
    while(node != nullptr || !stack1->empty()){
        if(node != nullptr) {
            stack1->push(node);
            output->push(node);
            node = node->getRchild();
        } else{
            node = stack1->top();
            stack1->pop();
            node = node->getLchild();
        }
    }

    while(output->size() > 0){
        BiNode *n = output->top();
        output->pop();
        cout << n->getData() << ", ";
    }
    cout << endl;
}

