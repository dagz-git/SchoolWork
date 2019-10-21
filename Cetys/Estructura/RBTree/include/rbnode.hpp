#ifndef _RB_TREE_
#define _RB_TREE_


#include <color.h>

template <typename T>
class RBNode
{
public:
    T data;
    RBNode* parent;
    RBNode* left;
    RBNode* right;
    Color color;
    RBNode(const T data);
};

template <typename T>
RBNode<T> :: RBNode(T data){
this->data = data;
this->parent=nullptr;
this->left=nullptr;
this->right= nullptr ;
this->color=Color::RED;
}

#endif
