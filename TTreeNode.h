#include <iostream>

using namespace std;

template <class type>
class TTreeNode{
public:
  TTreeNode(); //deafult constructor
  TTreeNode(type key); //overloaded constructor
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
