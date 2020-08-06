//
// Created by Chris Howe on 8/5/20.
//

#pragma once

#include "BinaryTree.h"

/*
 * In addition to the requirements imposed on a binary search tree
 * the following must be satisfied by a red–black tree
    * Each node is either red or black.
    * The root is black.
    * All leaves {nullptr} are black.
    * If a node is red, then both its children are black.
* */

enum Color
{
    RED,
    BLACK
};

class RedBlackTreeNode
{
public:
    RedBlackTreeNode* getParent();
    RedBlackTreeNode* getLeftChild();
    RedBlackTreeNode* getRightChild();
    RedBlackTreeNode* getGrandParent();
    RedBlackTreeNode* getUncle();
    RedBlackTreeNode* getSibling();
    int  getValue();
    Color getColor();
    void setValue(int value);
    void setRightChild(RedBlackTreeNode* right);
    void setLeftChild(RedBlackTreeNode* left);
    void setParent(RedBlackTreeNode* parent);
    void setColor(Color c);
private:
    RedBlackTreeNode* parent_     {nullptr};
    RedBlackTreeNode* leftChild_  {nullptr};
    RedBlackTreeNode* rightChild_ {nullptr};
    int value_   {0};
    Color color_ {RED};
};

class RedBlackTree
{
public:
    void insert(int value);
    void rotateLeft();
    void rotateRight();
private:
    RedBlackTreeNode* root_;
};