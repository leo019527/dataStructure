//
// Created by 李凌耀 on 2019/7/18.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>

using namespace std;

template<class T>
class Node {
private:
    /**
     * 参数说明
     * @param data:存储的数据
     * @param pre:前项指针
     * @param next:后继指针
     */
    T data;
    Node *pre;
    Node *next;
public:
    /**
     * 构造函数
     * @param data 创建的时候需要把两个指针置空
     */
    Node(T data) : data(data) {
        pre = NULL;
        next = NULL;
    }

    ~Node() {}

    void print() {
        cout << " " << data << " ";
    }

    Node *getPre() const {
        return pre;
    }

    void setPre(Node *pre) {
        Node::pre = pre;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        Node::data = data;
    }
};

template<class T>
class LinkedList {
private:
    /**
     * 参数说明
     * @param pHead:头指针
     * @param pTail:尾指针
     * @param length:长度
     */
    Node<T> *pHead;
    Node<T> *pTail;
    int length;
public:
    LinkedList() {
        this->pHead = NULL;
        this->pTail = NULL;
        length = 0;
    }

    ~LinkedList() {
        Node<T> *p = this->pHead;
        while (p->getNext() != NULL) {
            Node<T> *tmp = p->getNext();
            delete p;
            p = tmp;
        }
    }

    /**
     * 在尾部添加数据
     * @param data
     * @return
     */
    bool add(T data) {
        Node<T> *node = new Node<T>(data);
        if (this->pHead == NULL) {
            //表示是第一个节点
            this->pHead = node;
            this->pTail = node;
            this->length = 1;
        } else {
            //直接在尾结点后添加
            this->pTail->setNext(node);
            node->setPre(this->pTail);
            this->pTail = node;
            this->length++;
        }
        return true;
    }

    /**
     * 在指定位置添加数据
     * @param data
     * @param index
     * @return
     */
    bool add(T data, int index) {
        if (index < 0 || index > this->length) {
            return false;
        }
        Node<T> *node = new Node<T>(data);
        Node<T> *p = this->pHead;
        this->length++;
        if (index == 0) {
            //需要插入的是第一个节点
            this->pHead->setPre(node);
            node->setNext(this->pHead);
            this->pHead = node;
            return true;
        }

        for (int i = 0; i < index; ++i) {
            p = p->getNext();
        }
        p->getPre()->setNext(node);
        node->setNext(p);
        node->setPre(p->getPre());
        p->setPre(node);
        return true;
    }

    /**
     * 删除指定位置的数据
     * @param index
     * @return
     */
    bool drop(int index) {
        if (index < 0 || index > this->length - 1) {
            return false;
        }
        Node<T> *p = this->pHead;
        if (index == 0) {
            //表示删除的是第一个节点
            p = p->getNext();
            p->setPre(NULL);
            delete this->pHead;
            this->pHead = p;
            return true;
        } else if (index == this->length - 1) {
            //表示删除的是尾结点
            p = this->pTail;
            p->getPre()->setNext(NULL);
            this->pTail = p->getPre();
            delete p;
            return true;
        }
        for (int i = 0; i < index; ++i) {
            p = p->getNext();
        }
        p->getPre()->setNext(p->getNext());
        p->getNext()->setPre(p->getPre());
        delete p;
        return true;
    }

    /**
     * 查询指定位置的数据
     * @param index
     * @return
     */
    T get(int index) {
        if (index < 0 || index > this->length - 1) {
            return NULL;
        }
        Node<T> *p = this->pHead;
        for (int i = 0; i < index; ++i) {
            p = p->getNext();
        }
        return p->getData();
    }

    /**
     * 修改指定位置的数据
     * @param data
     * @param index
     * @return
     */
    bool set(T data,int index) {
        if (index < 0 || index > this->length - 1) {
            return NULL;
        }
        Node<T> *p = this->pHead;
        for (int i = 0; i < index; ++i) {
            p = p->getNext();
        }
        p->setData(data);
        return true;
    }

    /**
     * 测试用输出
     */
    void print(){
        Node<T> *p = this->pHead;
        cout << "[";
        while(true) {
            if (p->getNext()== NULL) {
                p->print();
                break;
            }
            p->print();
            cout << ",";
            p = p->getNext();
        }
        cout << "]" << endl;
    }
};

#endif //LINKEDLIST_LINKEDLIST_H
