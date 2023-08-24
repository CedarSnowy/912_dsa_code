#include "head.h"
using namespace std;



template <typename T> void visitAlongLeftBranch(BinNode<T>* node,stack<BinNode<T>*>& support_stack)
{
    while(node)
    {
        node->visit();
        support_stack.push(node->rchild);
        node = node->lchild;
    }
}

template <typename T> void trav_prev_order(BinTree<T>* tree)
{
    BinNode<T>* node = tree->root;
    stack<BinNode<T>*> support_stack;
    while(true)
    {
        visitAlongLeftBranch(node,support_stack);
        if (support_stack.empty())
            break;
        node = support_stack.top();
        support_stack.pop();
    }
}

template <typename T> void goAlongLeftBranch(BinNode<T>* node,stack<BinNode<T>*>& support_stack)
{

    while(node)
    {
        // support_stack.push(node->rchild);
        support_stack.push(node);
        node = node->lchild;
    }
}

template <typename T> void trav_in_order(BinTree<T>* tree)
{
    BinNode<T>* node = tree->root;
    stack<BinNode<T>*> support_stack;

    while(true)
    {
        goAlongLeftBranch(node,support_stack);

        if(support_stack.empty())
            break;
        node = support_stack.top();
        support_stack.pop();
        node->visit();

        node = node->rchild;
    }

}

template <typename T> void gotoHLVFL(stack<BinNode<T>*>& support_stack)
{
    BinNode<int>* node = support_stack.top();
    while (node)
    {
        if(node->lchild)
        {
            support_stack.push(node->rchild);
            support_stack.push(node->lchild);
        }
        else
            support_stack.push(node->rchild);

        node = support_stack.top();
    }
    support_stack.pop();
}

template <typename T> void trav_post_order(BinTree<T>* tree)
{
    BinNode<T>* node = tree->root;
    stack<BinNode<T>*> support_stack;

    support_stack.push(node);

    while(!support_stack.empty())
    {

        if(support_stack.top() != node->parent)
            gotoHLVFL(support_stack);
        node = support_stack.top();
        support_stack.pop();
        node->visit();
    }

}


int main()
{
    BinNode <int>* Root = new BinNode<int>(nullptr, nullptr, nullptr, 0);
    createTree(Root);

    BinTree<int> *Tree = new BinTree<int>(Root);

    // trav_prev_order(Tree);

    // trav_in_order(Tree);
    trav_post_order(Tree);
}


// 	        0
//      1		2
//  3     4   5     6