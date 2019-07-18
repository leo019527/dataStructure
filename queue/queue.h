//
// Created by 李凌耀 on 2019/7/18.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <cstdlib>
#include <iostream>

using namespace std;

#define QUEUE_INIT_SIZE 16
#define QUEUE_EXPEND_SZE 2

template <class T>
class Queue{
private:
    /**
     * 参数说明
     * @param pHead:队列指针
     * @param length:队列长度
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
        } else if (newLength < this->length * QUEUE_EXPEND_SZE) {
            //扩展后够大
            newHead = (T *) realloc(this->pHead, sizeof(T) * this->length * QUEUE_EXPEND_SZE);
            writeOutLength = this->length * QUEUE_EXPEND_SZE;
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
    Queue() {
        this->pHead = (T *)malloc(sizeof(T)*QUEUE_INIT_SIZE);
        this->length = 0;
        this->size = QUEUE_INIT_SIZE;
    }

    ~Queue() {
        free(pHead);
    }



    /**
     * 向队列顶压数据
     * @param data
     * @return
     */
    void push(T data) {
        ensureCapacity(1);
        this->pHead[this->length] = data;
        this->length++;
    }

    /**
     * 输出队列顶数据
     * @return
     */
    T pop() {
        if (this->length==0){
            return NULL;
        }
        T tmp = this->pHead[0];
        this->length--;
        for (int i = 0; i < this->length; ++i) {
            this->pHead[i] = this->pHead[i+1];
        }
        return tmp;
    }
};

#endif //QUEUE_QUEUE_H
