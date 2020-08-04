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

BinaryTreeNode* BinarySearchTree::newNode(int value)
{
    BinaryTreeNode* new_node = new BinaryTreeNode;
    new_node->setValue(value);
    new_node->setLeftChild(nullptr);
    new_node->setRightChild(nullptr);
    return new_node;
}

BinaryTreeNode* BinarySearchTree::construct(int* data, int start, int end, const TraversalMode mode)
{
    switch (mode)
    {
        case TraversalMode::PREORDER:
        {
            BinaryTreeNode* temp;

            // if start is greater than end then tree is constructed
            if (start > end)
            {
                return nullptr;
            }

            // If first index then assign root
            if (start == 0)
            {
                temp = newNode(data[start]);
                root_ = temp;
            }
            else
            {
                temp = newNode(data[start]);
            }

            int index;
            // from provided start to end check greater than
            // if greater than stop index increment and create next leaves
            // split at index where index - 1 is left child, or lesser of the values
            // index is greater value or right child due to check and break
            for (index = start; index <= end; ++index)
            {
                if (data[index] > temp->getValue())
                {
                    break;
                }
            }

            // Recurively construct the left and right children
            // Continuing the tree structure until start > end
            temp->setLeftChild( construct(data, start + 1, index - 1, TraversalMode::PREORDER) );
            temp->setRightChild( construct(data, index, end, TraversalMode::PREORDER) );

            // return created node
            return temp;
        }
    }

}

//Recursive Function to print in order tree
void BinarySearchTree::print(BinaryTreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }
    this->print(node->getLeftChild());
    printf("%d ", node->getValue());
    this->print(node->getRightChild());
}

BinaryTreeNode* BinarySearchTree::getRoot()
{
    return root_;
}