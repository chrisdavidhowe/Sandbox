//
// Created by Chris Howe on 8/28/20.
//

#include <queue>
#include <iostream>

using namespace std;

struct treeNode
{
    treeNode* left;
    treeNode* right;
    int value;
}

void printNode(treeNode* node)
{
    cout << "Level " << level << node->value << endl;
}

void bfs(treeNode* root)
{
    int level = 1;
    printNode(root);
    queue<treeNode*> q;
    q.push(root);

    int index = 0;
    while( !q.empty() )
    {
        if ( q.front()->left != nullptr )
        {
            q.push( q.front()->left );
        }
        if ( q.front()->right != nullptr )
        {
            q.push( q.front()->right );
        }
        printNode( q.front() );
        level++;
        q.pop();
    }
}

