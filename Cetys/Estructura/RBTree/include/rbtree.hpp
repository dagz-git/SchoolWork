#ifndef _RBTREE_
#define _RBTREE_

#include <rbnode.hpp>

template <typename T>
class RBTree
{
public:
    RBNode<T> *root;
    void left_rotate(RBNode<T> *x);
    void right_rotate(RBNode<T> *x);
    void insert(T data);
    void RbFix(RBNode<T> *x);
  

    RBTree(T key);
};

template <typename T>
RBTree<T>::RBTree(T data) : root{new RBNode<T>{data}}
{
    this->root->color = Color::BLACK;
}

template <typename T>
void RBTree<T>::insert(T data)
{
    if (this->root == nullptr)
    {
        RBNode<T> *nuevo = new RBNode<T>(data);
        this->root = nuevo;
        this->root->color = Color::BLACK;
    }
    else
    {
        RBNode<T> *temp = this->root;
        RBNode<T> *previous = nullptr;
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
        }
        temp = new RBNode<T>(data);

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
        RbFix(temp);
    }
}

template <typename T>
void RBTree<T>::RbFix(RBNode<T> *x)
{
    while (x != this->root && x->parent->color == Color::RED)
    {
        if (x->parent == x->parent->parent->left)
        {
            RBNode<T> *y = x->parent->parent->right;
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
            RBNode<T> *y = x->parent->parent->left;
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
void RBTree<T>::left_rotate(RBNode<T> *x)
{
    RBNode<T> *y = x->right;
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
}

template <typename T>
void RBTree<T>::right_rotate(RBNode<T> *x)
{
    RBNode<T> *y = x->left;
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
}

#endif