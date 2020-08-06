//
// Created by Chris Howe on 8/5/20.
//

#include "RedBlackTree.h"

void RedBlackTreeNode::setValue(int value)
{
    value_ = value;
}

void RedBlackTreeNode::setLeftChild(RedBlackTreeNode *left)
{
    leftChild_ = left;
}

void RedBlackTreeNode::setRightChild(RedBlackTreeNode *right)
{
    right = rightChild_;
}

void RedBlackTreeNode::setParent(RedBlackTreeNode *parent)
{
    parent_ = parent;
}

void RedBlackTreeNode::setColor(Color c)
{
    color_ = c;
}

RedBlackTreeNode* RedBlackTreeNode::getParent()
{
    return parent_;
}

RedBlackTreeNode* RedBlackTreeNode::getGrandParent()
{
    return parent_->getParent();
}

RedBlackTreeNode* RedBlackTreeNode::getUncle()
{
    if (this->parent_->getRightChild() == this)
    {
        return parent_->getParent()->getLeftChild();
    }
    else
    {
        return parent_->getParent()->getRightChild();
    }
}

RedBlackTreeNode* RedBlackTreeNode::getSibling()
{
    if (this->parent_->getRightChild() == this)
    {
        return parent_->getLeftChild();
    }
    else
    {
        return parent_->getRightChild();
    }
}

RedBlackTreeNode* RedBlackTreeNode::getLeftChild()
{
    return leftChild_;
}

RedBlackTreeNode* RedBlackTreeNode::getRightChild()
{
    return rightChild_;
}

int RedBlackTreeNode::getValue()
{
    return value_;
}

Color RedBlackTreeNode::getColor()
{
    return color_;
}

void RedBlackTree::insert(int value)
{
    if (root_ == nullptr)
    {
        root_ = new RedBlackTreeNode;
        root_->setValue(value);
        root_->setColor(BLACK);
    }
    else
    {

    }
}