#include <iostream>

using namespace std;

template <class type>
class TTreeNode{
public:
  TTreeNode();
  TTreeNode(type key);
  ~TTreeNode();

  type key;
  TTreeNode *left;
  TTreeNode *right;
};

template <class type>
TTreeNode<type>::TTreeNode(){
  left=NULL;
  right=NULL;
}

template <class type>
TTreeNode<type>::TTreeNode(type k){
  key = k;
  left=NULL;
  right=NULL;
}

template <class type>
TTreeNode<type>::~TTreeNode(){
  delete right;
  delete left;
}
