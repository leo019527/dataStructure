//
// Created by 李凌耀 on 2019/10/12.
//

#include "BiNode.h"

BiNode::BiNode(int data) : data(data) {
    this->lchild = nullptr;
    this->rchild = nullptr;
}

BiNode::BiNode() {
    this->lchild = nullptr;
    this->rchild = nullptr;
}

int BiNode::getData() const {
    return data;
}

void BiNode::setData(int data) {
    BiNode::data = data;
}

BiNode *BiNode::getLchild() const {
    return lchild;
}

void BiNode::setLchild(BiNode *lchild) {
    BiNode::lchild = lchild;
}

BiNode *BiNode::getRchild() const {
    return rchild;
}

void BiNode::setRchild(BiNode *rchild) {
    BiNode::rchild = rchild;
}