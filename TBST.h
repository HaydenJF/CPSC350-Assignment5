#include "TTreeNode.h"

template <class type>
class TBST{
  private:
    TTreeNode<type> *root;
    int size = 0;
  public:
    TBST();//default constructor
    ~TBST();//destructor

    type getNode(type i);//from the ID gives the type
    TTreeNode<type>* getTreeNode(type i);//From the type gives the node (for editing)
    bool searchNode(type value); //sees if value exists
    void insertNode(type value);//inserts a new node
    bool deleteNode(type value);//deletes a node
    bool isEmpty();//checks if empty
    unsigned int getSize();//checks size
    type getMin();//gives the minimum value
    type getMax();//gives the maximum value
    void recPrint(TTreeNode<type> *node);//prints node with all youth too
    void printEntireTree();//prints whole tree

    TTreeNode<type>* getSuccessor(TTreeNode<type> *d);//help for delete node
};

template <class type>
TBST<type>::TBST(){//default constructor
  root = '\0';
  size = 0;
}

template <class type>
TBST<type>::~TBST(){//destructor
  delete root;
}


template <class type>
void TBST<type>::recPrint(TTreeNode<type> *node){//prints node with all youth too
  if(node != '\0'){
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
  }
}

template <class type>
void TBST<type>::printEntireTree(){//prints whole tree
  if (!isEmpty()){
    recPrint(root);
  }
}

template <class type>
type TBST<type>::getNode(type i){//from the ID gives the type
  if(isEmpty()){
    return '\0';
  } else {
    TTreeNode<type> *curr = root;
    while (curr->key != i){
      if (i < curr->key){
          curr = curr->left;
      } else {
        curr = curr->right;
      }
      if (curr == '\0'){
        return '\0';
      }
    }
    return curr->key;
  }
}

template <class type>
TTreeNode<type>* TBST<type>::getTreeNode(type i){//From the type gives the node (for editing)
  if(isEmpty()){
    return '\0';
  } else {
    TTreeNode<type> *curr = root;
    while (curr->key != i){
      if (i < curr->key){
          curr = curr->left;
      } else {
        curr = curr->right;
      }
      if (curr == '\0'){
        return '\0';
      }
    }
    return curr;
  }
}

template <class type>
type TBST<type>::getMax(){//gives the maximum value
  TTreeNode<type> *curr = root;

  if(isEmpty()){
    return '\0';
  }
  while(curr->right != '\0'){
    curr = curr->right;
  }
  return curr->key;
}

template <class type>
type TBST<type>::getMin(){//gives the minimum value
  TTreeNode<type> *curr = root;

  if(isEmpty()){
    return '\0';
  }
  while(curr->left != '\0'){
    curr = curr->left;
  }
  return curr->key;
}

template <class type>
void TBST<type>::insertNode(type value){//inserts a new node
  TTreeNode<type> *node = new TTreeNode<type>(value);
  if(isEmpty()){
    root = node;
  } else{
    TTreeNode<type> *parent = '\0';
    TTreeNode<type> *curr = root;
    while(true){
      parent = curr;
      if (value < curr->key){
        curr = curr->left;
        if (curr == '\0'){
          parent->left = node;
          break;
        }
      } else {
        curr = curr->right;
        if (curr == '\0'){
          parent->right = node;
          break;
        }
      }
    }
  }
  size++;
}

template <class type>
bool TBST<type>::searchNode(type value){//sees if value exists

  if(isEmpty()){
    return false;
  } else {
    TTreeNode<type> *curr = root;
    while (curr->key != value){
      if (value < curr->key){
        curr = curr->left;
      } else {
        curr = curr->right;
      }
      if (curr == '\0'){
        return false;
      }
    }
    return true;
  }
}

template <class type>
bool TBST<type>::deleteNode(type value){//deletes a node
  if(isEmpty()){
    return false;
  }
  TTreeNode<type> *part = '\0';
  TTreeNode<type> *curr = root;
  bool isLeft = true;
  while (curr->key != value){
    part = curr;
    if (value < curr->key){
      curr = curr->left;
      isLeft = true;
    } else {
      curr = curr->right;
      isLeft = false;
    }
    if (curr == '\0'){
      return false;
    }
  }

  size--;
  //leaf node deleted
  if (curr->left == '\0' && curr->right == '\0'){
    if (curr == root){
      root = '\0';
    } else if (isLeft) {
      part->left = '\0';
    } else {
      part->right = '\0';
    }
  }
  //case: deleted node has 1 child
  else if (curr->right == '\0'){ //is left child
    if (curr == root){
      root = curr->left;
    } else if (isLeft) {
      part->left = curr->left;
    } else {
      part->right = curr->left;
    }
  } else if (curr->left == '\0'){ //is right child
    if (curr == root){
      root = curr->right;
    } else if (isLeft) {
      part->left = curr->right;
    } else {
      part->right = curr->right;
    }
  } else { //the dreaded double children
    TTreeNode<type> *successor = getSuccessor(curr);

    if (curr == root){
      root = successor;
    } else if (isLeft){
      part->left = successor;
    } else {
      part->right = successor;
    }

    successor->left = curr->left;
  }
  curr->left = '\0';
  curr->right = '\0';
  delete curr; //QUESTION do WE garbage collect in the delete function????
  return true;
}

template <class type>
TTreeNode<type>* TBST<type>::getSuccessor(TTreeNode<type> *d){ //represents the deleted node
  TTreeNode<type> *curr = d->right;
  TTreeNode<type> *succ = d;
  TTreeNode<type> *sp = d;

  while (curr != '\0'){
    sp = succ;
    succ = curr;
    curr = curr->left;
  }
  //once we exit the while loop. pointers should be in correct positions
  //we need to check weather or not successor is decendent of right children
  if (succ != d->right){
    sp->left = succ->right;
    succ->right = d->right;
  }
  return succ;
}

template <class type>
bool TBST<type>::isEmpty(){//checks if empty
  if (size == 0){
    return true;
  } else {
    return false;
  }
}

template <class type>
unsigned int TBST<type>::getSize(){//checks size
  return size;
}
