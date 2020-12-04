#include <iostream>

using namespace std;

template <class type>
class TTreeNode{
public:
  TTreeNode();//constructor
  TTreeNode(type key);//constructor with key
  ~TTreeNode();//destructor

  type key;//value put in
  TTreeNode *left;//left node
  TTreeNode *right;//right node
};

template <class type>
TTreeNode<type>::TTreeNode(){//constructor
  left=NULL;
  right=NULL;
}

template <class type>
TTreeNode<type>::TTreeNode(type k){//constructor with key
  key = k;
  left=NULL;
  right=NULL;
}

template <class type>
TTreeNode<type>::~TTreeNode(){//destructor
  delete right;
  delete left;
}
