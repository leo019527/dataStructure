//
// Created by 李凌耀 on 2019/7/18.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <cstdlib>
#include <iostream>

using namespace std;

#define STACK_INIT_SIZE 16
#define STACK_EXPEND_SZE 2

template <class T>
class Stack{
private:
    /**
     * 参数说明
     * @param pHead:栈指针
     * @param length:栈长度
     */
    T *pHead;
    int length;
    int size;

    /**
     * 容量计算和扩容函数
     * @param increase 增加的大小
     */
    void ensureCapacity(int increase){
        int newLength = this->length + increase;

        T *newHead = NULL;
        int writeOutLength;

        if (newLength <= this->size) {
            //如果小于原空间直接返回
            return;
        } else if (newLength < this->length * STACK_EXPEND_SZE) {
            //扩展后够大
            newHead = (T *) realloc(this->pHead, sizeof(T) * this->length * STACK_EXPEND_SZE);
            writeOutLength = this->length * STACK_EXPEND_SZE;
        } else {
            //扩展以后还是不够大,直接使用需求大小
            newHead = (T *) realloc(this->pHead, sizeof(T) * newLength);
            writeOutLength = newLength;
        }

        if (newHead == NULL) {
            cout << "expand array size from " << this->length << " to " << newLength << " failed!" << endl;
            exit(1);
        } else {
            this->pHead = newHead;
            this->size = writeOutLength;
        }
    }

public:
    Stack() {
        this->pHead = (T *)malloc(sizeof(T)*STACK_INIT_SIZE);
        this->length = 0;
        this->size = STACK_INIT_SIZE;
    }

    ~Stack() {
        free(pHead);
    }



    /**
     * 向栈顶压数据
     * @param data
     * @return
     */
    void push(T data) {
        ensureCapacity(1);
        this->pHead[this->length] = data;
        this->length++;
    }

    /**
     * 输出栈顶数据
     * @return
     */
    T pop() {
        if (this->length==0){
            return NULL;
        }
        this->length--;
        return this->pHead[this->length];
    }
};

#endif //STACK_STACK_H
