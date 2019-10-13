//
// Created by 李凌耀 on 2019/10/12.
//

#ifndef BITREE_BINODE_H
#define BITREE_BINODE_H


class BiNode {
private:
    int data;
    BiNode *lchild,*rchild;
public:
    int getData() const;

    void setData(int data);

    BiNode *getLchild() const;

    void setLchild(BiNode *lchild);

    BiNode *getRchild() const;

    void setRchild(BiNode *rchild);

    BiNode(int data);

    BiNode();
};


#endif //BITREE_BINODE_H
