#ifndef _OSRBTree_
#define _OSRBTree_

#include <osrbnode.hpp>

template <typename T>
class OSRBTree
{
public:
    OSRBNode<T> *root;
    void left_rotate(OSRBNode<T> *x);
    void right_rotate(OSRBNode<T> *x);
    void insert(T data);
    void RbFix(OSRBNode<T> *x);
    OSRBNode<T> OS_SELECT(int i);
    int OS_RANK(OSRBNode<T> x);

    OSRBTree(T key);
};

template <typename T>
OSRBNode<T> OSRBTree<T>::OS_SELECT(int i)
{
    OSRBNode<T> x = this->root;
    int r = x.left.size;
    if (i == r)
    {
        return x;
    }
    else if (i < r)
    {
        return OS_SELECT(x.left, i);
    }
    else
    {
        return OS_SELECT(x.right, i - r);
    }
}

template <typename T>
int OSRBTree<T>::OS_RANK(OSRBNode<T> x)
{
    int r = x.left.size + 1;
    OSRBNode<T> y = x;
    while (y != this.root)
    {
        if (y == y.parent.right)
        {
            r = r + y.parent.left.size + 1;
        }
        y = y.parent;
    }
    return r;
}

template <typename T>
OSRBTree<T>::OSRBTree(T data) : root{new OSRBNode<T>{data}}
{
    this->root->color = Color::BLACK;
    this->root->size = 1;
}

template <typename T>
void OSRBTree<T>::insert(T data)
{
    if (this->root == nullptr)
    {
        OSRBNode<T> *nuevo = new OSRBNode<T>(data);
        this->root = nuevo;
        this->root->color = Color::BLACK;
        this->root->size = 1;
    }
    else
    {
        OSRBNode<T> *temp = this->root;
        OSRBNode<T> *previous = nullptr;
        while (temp != nullptr)
        {
            previous = temp;
            if (data < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
            previous->size = previous->size + 1;
        }
        temp = new OSRBNode<T>(data);

        temp->parent = previous;

        if (data < previous->data)
        {
            previous->left = temp;
        }
        else
        {
            previous->right = temp;
        }
        temp->color = Color::RED;
        temp->size = 1;
        RbFix(temp);
    }
}

template <typename T>
void OSRBTree<T>::RbFix(OSRBNode<T> *x)
{
    while (x != this->root && x->parent->color == Color::RED)
    {
        if (x->parent == x->parent->parent->left)
        {
            OSRBNode<T> *y = x->parent->parent->right;
            if (y == nullptr)
            {
                if (x == x->parent->right)
                {
                    x = x->parent;
                    left_rotate(x);
                }
                x->parent->color = Color::BLACK;
                x->parent->parent->color = Color::RED;
                right_rotate(x->parent->parent);
            }
            else
            {
                if (y->color == Color::RED)
                {
                    x->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    x->parent->parent->color = Color::RED;
                    x = x->parent->parent;
                }
            }
        }
        else
        {
            OSRBNode<T> *y = x->parent->parent->left;
            if (y == nullptr)
            {
                if (x == x->parent->left)
                {
                    x = x->parent;
                    right_rotate(x);
                }
                x->parent->color = Color::BLACK;
                x->parent->parent->color = Color::RED;
                left_rotate(x->parent->parent);
            }
            else
            {
                if (y->color == Color::RED)
                {
                    x->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    x->parent->parent->color = Color::RED;
                    x = x->parent->parent;
                }
            }
        }
    }
    this->root->color = Color::BLACK;
}

template <typename T>
void OSRBTree<T>::left_rotate(OSRBNode<T> *x)
{
    OSRBNode<T> *y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        this->root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
    y->size = x->size;
    int aux = 0;
    if (x->left != nullptr)
    {
        aux = aux + x->left->size;
    }
    if (x->right != nullptr)
    {
        aux = aux + x->right->size;
    }
    x->size = aux + 1;
}

template <typename T>
void OSRBTree<T>::right_rotate(OSRBNode<T> *x)
{
    OSRBNode<T> *y = x->left;
    x->left = y->right;
    if (y->right != nullptr)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        this->root = y;
    }
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
    y->size = x->size;
    int aux = 0;
    if (x->left != nullptr)
    {
        aux = aux + x->left->size;
    }
    if (x->right != nullptr)
    {
        aux = aux + x->right->size;
    }
    x->size = aux + 1;
}

#endif
