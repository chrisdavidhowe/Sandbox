//
// Created by Chris Howe on 8/1/20.
//

#pragma once

class BinaryTreeNode
{
public:
    int getValue();
    BinaryTreeNode* getLeftChild();
    BinaryTreeNode* getRightChild();
    void setValue(int v);
    void setRightChild(BinaryTreeNode* r);
    void setLeftChild(BinaryTreeNode* l);

private:
    int value_ {0};
    BinaryTreeNode* leftChild_;
    BinaryTreeNode* rightChild_;
};
