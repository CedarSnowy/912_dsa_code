# include <iostream>
# include <stack>
using namespace std;



template <typename T> struct BinNode {
    /*Todo:定义二叉树节点*/
    // 成员变量：左孩子、右孩子、亲节点、数据域

    BinNode<T> *lchild, *rchild,* parent;
    T data;

    BinNode();

    BinNode(BinNode<T> *lchild, BinNode<T> *rchild,BinNode<T> * parent,T data)
    {
        this->lchild = lchild;
        this->rchild = rchild;
        this->parent = parent;
        this->data = data;
    }

    void insertAslchild(BinNode<T> *node)
    {
        this->lchild = node;
        node->parent = this;
    }

    
    void insertAsrchild(BinNode<T> *node)
    {
        this->rchild = node;
        node->parent = this;
    }

    void visit()
    {
        cout << this->data << endl;
    }
};



template <typename T> class BinTree
{
    public:
        BinNode<T> *root;
        BinTree();

        BinTree(BinNode <T>* root)
        {
            this->root = root;
        }

};

template <typename T> void createTree(BinNode<T>* &Root)
{
    BinNode<T>* leftChild = new BinNode<T>(nullptr, nullptr, nullptr, 1);
    BinNode<T>* rightChild = new BinNode<T>(nullptr, nullptr, nullptr, 2);

    BinNode<T>* leftGrandChild1 = new BinNode<T>(nullptr, nullptr, nullptr, 3);
    BinNode<T>* leftGrandChild2 = new BinNode<T>(nullptr, nullptr, nullptr, 4);
    BinNode<T>* rightGrandChild1 = new BinNode<T>(nullptr, nullptr, nullptr, 5);
    BinNode<T>* rightGrandChild2 = new BinNode<T>(nullptr, nullptr, nullptr, 6);

    leftChild->insertAslchild(leftGrandChild1);
    leftChild->insertAsrchild(leftGrandChild2);
    rightChild->insertAslchild(rightGrandChild1);
    rightChild->insertAsrchild(rightGrandChild2);

    Root->insertAslchild(leftChild);
    Root->insertAsrchild(rightChild);
}


