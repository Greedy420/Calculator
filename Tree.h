#ifndef TREE_H
#define TREE_H

#include <cstdlib>

template <typename T>
struct node {
    T value;
    node<T> *left;
    node<T> *right;
};

template <class Type>
class Tree {
public:
    Tree();
    ~Tree();

    void destroy();
    void destroy(node<Type> *leaf);

    node<Type> *root;
};

template <class Type>
Tree<Type>::Tree()
{
    root = NULL;
}

template <class Type>
Tree<Type>::~Tree()
{
    destroy();
}

template <class Type>
void Tree<Type>::destroy()
{
  destroy(root);
}

template <class Type>
void Tree<Type>::destroy(node<Type> *leaf)
{
    if (leaf != NULL)
      {
        destroy(leaf->left);
        destroy(leaf->right);
        delete leaf;
      }
}

#endif // TREE_H
