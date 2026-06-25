#ifndef TREE_HPP
#define TREE_HPP

namespace bukreev
{
  template< class T >
  struct Tree
  {
    T val;
    Tree< T >* left;
    Tree< T >* right;
    Tree< T >* parent;
  };

  template< class T >
  void createTree(Tree< T >** ppTree)
  {
    *ppTree = new Tree< T >;
    Tree< T >* pTree = *ppTree;
    pTree->parent = nullptr;
    pTree->left = nullptr;
    pTree->right = nullptr;
  }

  template< class T >
  void deleteTree(Tree< T >* tree)
  {
    if (tree->left)
    {
      deleteTree(tree->left);
    }
    if (tree->right)
    {
      deleteTree(tree->right);
    }

    delete tree;
  }

  template< class T >
  void insertTree(Tree< T >* tree, T& val)
  {
    Tree< T >* parent;
    while (tree)
    {
      parent = tree;
      if (val > tree->val)
      {
        tree = tree->right;
      }
      else
      {
        tree = tree->left;
      }
    }

    Tree< T >* newNode = new Tree< T >;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = parent;

    if (val > parent->val)
    {
      parent->right = newNode;
    }
    else
    {
      parent->left = newNode;
    }
  }
}

#endif
