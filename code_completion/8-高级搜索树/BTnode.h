# include <vector>
using namespace std;

template <typename T> struct BTnode
{
    BTnode *parent;
    vector<T> key;
    vector<BTnode *> child;
    BTnode()
    {
        parent = nullptr;
        child.insert(0, nullptr);
    }
    BTnode(T e,BTnode* lc=nullptr,BTnode* rc = nullptr)
    {
        parent = nullptr;
        key.insert(0, e);
        child.insert(0, lc);
        child.insert(1, rc);

        if(lc)
            lc->parent = this;
        if(rc)
            rc->parent = this;
    }
};

template <typename T> class BTtree
{
    BTnode<T> *root;
    BTnode<T> *hot;
    int _order;

    BTtree(int order = 3):_order(order)
    {
        root = new BTnode<T>();
    }

    void stackOverlflow(BTnode*)
    {
        
    }
};