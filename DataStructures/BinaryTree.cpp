//
// Created by Chris Howe on 8/1/20.
//

#include "BinaryTree.h"

BinaryTreeNode::BinaryTreeNode(int value) :
    value_(value)
{}

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
    BinaryTreeNode* new_node = new BinaryTreeNode(value);
    new_node->setLeftChild(nullptr);
    new_node->setRightChild(nullptr);
    return new_node;
}

void BinarySearchTree::insert(BinaryTreeNode* node, int value)
{
    printf("Inserting %d to BST\n", value);

    if (node == nullptr)
    {
        root_ = newNode(value);
        return;
    }

    //value already exists at root
    if (node->getValue() == value)
    {
    }
    //less than left child
    else if (value < node->getValue())
    {
        if (node->getLeftChild() != nullptr)
        {
            insert(node->getLeftChild(), value);
        }
        else
        {
            node->setLeftChild(newNode(value));
        }
    }
    //greater than right child
    else
    {
        if (node->getRightChild() != nullptr)
        {
            insert(node->getRightChild(), value);
        }
        else
        {
            node->setRightChild(newNode(value));
        }
    }
}


void BinarySearchTree::traverse(BinaryTreeNode *node, const TraversalMode mode)
{
    switch (mode)
    {
        case TraversalMode::INORDER:
            if (node == nullptr)
            {
                return;
            }
            traverse(node->getLeftChild(), mode);
            printf("Node %d\n", node->getValue());
            traverse(node->getRightChild(), mode);
        break;
        case TraversalMode::PREORDER:
            if (node == nullptr)
            {
                return;
            }
            printf("Node %d\n", node->getValue());
            traverse(node->getLeftChild(), mode);
            traverse(node->getRightChild(), mode);
            break;
        case TraversalMode::POSTORDER:
            if (node == nullptr)
            {
                return;
            }
            traverse(node->getLeftChild(), mode);
            traverse(node->getRightChild(), mode);
            printf("Node %d\n", node->getValue());
            break;
    }
}

BinaryTreeNode* BinarySearchTree::construct(int* data, int start, int end, const TraversalMode mode)
{
    switch (mode)
    {
        // O(n^2) due to searching for the indices to split the tree
        // NOTE: can be optimized to O(n) with min/max checks instead of full index search
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
            // split at index where index - 1 is left child, or lesser than root
            // indexed value is greater than root than therefore the right child
            for (index = start; index <= end; ++index)
            {
                if (data[index] > temp->getValue())
                {
                    break;
                }
            }

            // Recursively construct the left and right children
            // Continuing the tree structure until start > end
            // Left child, Less than root
            temp->setLeftChild( construct(data, start + 1, index - 1, TraversalMode::PREORDER) );
            // Right child, gReater than root
            temp->setRightChild( construct(data, index, end, TraversalMode::PREORDER) );

            // return created node
            return temp;
        }
        break;

        case TraversalMode::LEVELORDER:
        {
            BinaryTreeNode* temp;

            // if start is greater than end then tree is fully constructed
            if (start > end)
            {
                return nullptr;
            }

            //First item is head in Level Order Breadth First Construction
            temp->setValue(data[0]);

            for (int i = 0; i < end; ++i)
            {
                temp->setLeftChild( construct(data, i*2, end, TraversalMode::LEVELORDER));
                temp->setRightChild( construct(data, (i*2)+1, end, TraversalMode::LEVELORDER));
            }
        }
        break;
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