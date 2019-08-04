//
// Created by 李凌耀 on 2019/7/17.
// 线性表(顺序储存）
//

#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#define ARRAYLIST_INITSIZE 16
#define ARRAYLIST_EXPENDSIZE 2

#include <malloc.h>
#include <iostream>


template<class T>
class mArrayList {
private:
    /**
     * 参数说明
     * @param pHead: 存储的头指针
     * @param length: 数据长度，初始为0
     * @param size: 当前存储空间长度
     */
    T *pHead;
    int length;
    int size;

    /**
     * 容量计算和扩容函数
     * @param increase 增加的大小
     */
    void ensureCapacity(int increase);

public:
    /**
     * 构造函数
     */
    mArrayList();

    ~mArrayList();

    /**
     * 初始化函数，返回空线性表,与构造函数功能相同，为适应王道考研教材修改
     */
    void InitList();

    /**
     * 求长度
     * @return 返回线性表长度
     */
    int Length();

    /**
     * 判空
     * @return true 表示空
     */
    bool Empty();

    /**
     * 增加一个数据至数组末端
     * @param data 数据项
     * @return 永远返回true
     */
    bool add(T data);

    /**
     * 增加一组数据至数组末端
     * @param data 数据项列表的表头
     * @param size 数据项的大小
     * @return 永远返回true
     */
    bool add(T *data, int size);

    /**
     * 将一个数据插入指定位置
     * @param data 数据项
     * @param index 位置
     * @return 当index不在数组内时返回false
     */
    bool add(T data, int index);

    /**
     * 将一组数据插入指定位置
     * @param data 数组项列表的表头
     * @param size 数据项的大小
     * @param index 位置
     * @return 当index不在数组内时返回false
     */
    bool add(T *data, int size, int index);

    /**
     * 删除指定位置数据项
     * @param index 位置
     * @return 位置不正确返回false
     */
    bool drop(int index);

    /**
     * 删除一个区间内的数据项(包含端点)
     * @param start 开始区间
     * @param end 结束区间
     * @return 区间错误返回false
     */
    bool drop(int start, int end);

    /**
     * 获得指定位置的数据
     * @param index 位置
     * @return 数据项，未找到则返回null
     */
    T get(int index);

    /**
     * 修改指定位置的数据
     * @param index
     * @param data
     * @return 修改失败或位置不正确返回false
     */
    bool set(int index,T data);

    /**
     * 中间调试使用的print方法
     */
    void print();
};

//<editor-fold desc="实现">
template<class T>
mArrayList<T>::mArrayList() {
    this->size = ARRAYLIST_INITSIZE;
    this->length = 0;
    this->pHead = (T *) malloc(sizeof(T) * this->size);
}

template<class T>
void mArrayList<T>::print() {
    std::cout << "[";
    for (int i = 0; i < this->length; i++) {
        if (i == this->length - 1) {
            std::cout << this->pHead[i] << "]" << std::endl;
        } else {
            std::cout << this->pHead[i] << ", ";
        }
    }
}

template<class T>
void mArrayList<T>::ensureCapacity(int increase) {
    int newLength = this->length + increase;

    T *newHead = NULL;
    int writeOutLength;

    if (newLength <= this->size) {
        //如果小于原空间直接返回
        return;
    } else if (newLength < this->length * ARRAYLIST_EXPENDSIZE) {
        //扩展后够大
        newHead = (T *) realloc(this->pHead, sizeof(T) * this->length * ARRAYLIST_EXPENDSIZE);
        writeOutLength = this->length * ARRAYLIST_EXPENDSIZE;
    } else {
        //扩展以后还是不够大,直接使用需求大小
        newHead = (T *) realloc(this->pHead, sizeof(T) * newLength);
        writeOutLength = newLength;
    }

    if (newHead == NULL) {
        std::cout << "expand array size from " << this->length << " to " << newLength << " failed!" << std::endl;
        exit(1);
    } else {
        this->pHead = newHead;
        this->size = writeOutLength;
    }
}

template<class T>
mArrayList<T>::~mArrayList() {
    free(this->pHead);
}

template<class T>
bool mArrayList<T>::add(T data) {
    this->ensureCapacity(1);
    this->pHead[this->length] = data;
    this->length++;
    return true;
}

template<class T>
bool mArrayList<T>::add(T *data, int size) {
    this->ensureCapacity(size);
    for (int i = 0; i < size; i++) {
        this->pHead[this->length] = data[i];
        this->length++;
    }
    return true;
}

template<class T>
bool mArrayList<T>::add(T data, int index) {
    if (index > this->length || index < 0)
        return false;
    this->ensureCapacity(1);

    for (int i = this->length; i > index; i--) {
        this->pHead[i] = this->pHead[i - 1];
    }

    this->pHead[index] = data;
    this->length++;
    return true;
}

template<class T>
bool mArrayList<T>::add(T *data, int size, int index) {
    if (index > this->length || index < 0)
        return false;

    this->ensureCapacity(size);

    for (int i = this->length - 1 + size; i > index; i--) {
        this->pHead[i] = this->pHead[i - size];
    }

    for (int i = 0; i < size; i++) {
        this->pHead[index + i] = data[i];
        this->length++;
    }
    return true;
}

template<class T>
bool mArrayList<T>::drop(int index) {
    if (index > this->length - 1 || this->length < 1 || index < 0)
        return false;

    for (int i = index; i < this->length - 1; ++i) {
        this->pHead[i] = this->pHead[i + 1];
    }

    this->length--;
}

template<class T>
bool mArrayList<T>::drop(int start, int end) {
    if (start > end || end > this->length - 1 || start < 0 || this->length < 1)
        return false;
    int c = end - start + 1;
    for (int i = start; i < end + 1; ++i) {
        this->pHead[i] = this->pHead[i + c];
    }
    this->length -= c;
    return false;
}

template <class T>
T mArrayList<T>::get(int index) {
    if (index < 0 || index > this->length)
        return NULL;
    return this->pHead[index];
}

template<class T>
bool mArrayList<T>::set(int index, T data) {
    if (index < 0 || index > this->length)
        return false;
    this->pHead[index] = data;
    return true;
}

template<class T>
void mArrayList::InitList() {
    this->size = ARRAYLIST_INITSIZE;
    this->length = 0;
    this->pHead = (T *) malloc(sizeof(T) * this->size);
}

int mArrayList::Length() {
    return this->length;
}

bool mArrayList::Empty() {
    return this->length==0;
}

//</editor-fold>

#endif //ARRAYLIST_ARRAYLIST_H

