//
// Created by Chris Howe on 8/1/20.
//

#include "BinaryTree.h"

int BinaryTreeNode::getValue()
{
    return value_;
}
BinaryTreeNode* BinaryTreeNode::getLeftChild()
{
    return leftChild_;
}

BinaryTreeNode* BinaryTreeNode::getRightChild()
{
    return rightChild_;
}

void BinaryTreeNode::setValue(int v)
{
    value_ = v;
}

void BinaryTreeNode::setRightChild(BinaryTreeNode *r)
{
    rightChild_ = r;
}

void BinaryTreeNode::setLeftChild(BinaryTreeNode *l)
{
    leftChild_ = l;
}