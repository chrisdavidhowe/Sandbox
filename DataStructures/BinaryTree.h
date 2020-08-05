//
// Created by Chris Howe on 8/1/20.
//

#pragma once

#include "LinkedList.h"

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
    BinaryTreeNode* leftChild_ {nullptr};
    BinaryTreeNode* rightChild_ {nullptr};
};

enum class TraversalMode
{
    INORDER,   /* Left-Root-Right */
    PREORDER,  /* Root-Left-Right */
    POSTORDER, /* Left-Right-Root */
    LEVELORDER /* Breadth First   */
};

class BinarySearchTree
{
public:
    BinaryTreeNode* newNode(int value);
    BinaryTreeNode* construct(int* data, int start, int end, const TraversalMode mode);
    void traverse(const TraversalMode mode);
    void print(BinaryTreeNode* node);
    BinaryTreeNode* getRoot();
private:
    BinaryTreeNode* root_ {nullptr};
    LinkedList data_;
    int index_  {0};
    int length_ {0};
};