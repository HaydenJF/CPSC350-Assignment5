#include "TTreeNode.h"

template <class type>
class TBST{
  private:
    TTreeNode<type> *root;
    int size;
  public:
    TBST(); //default constructor
    ~TBST();

    type getNode(type i); // find the element value in the BST
    TTreeNode<type>* getTreeNode(type i);
    bool searchNode(type value); //our key is the value in this example
    void insertNode(type value); //value is the key
    bool deleteNode(type value); //delete the node at position value
    bool isEmpty(); 
    unsigned int getSize();
    type getMin(); 
    type getMax();
    void recPrint(TTreeNode<type> *node);
    void printEntireTree();

    TTreeNode<type>* getSuccessor(TTreeNode<type> *d);
};

template <class type>
//default constructor
TBST<type>::TBST(){
  root = NULL;
  size = 0;
}

template <class type>
TBST<type>::~TBST(){
  delete root;
  //iterate and delete
}

template <class type>
void TBST<type>::recPrint(TTreeNode<type> *node){
  if(node != NULL){
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
  }
}

template <class type>
void TBST<type>::printEntireTree(){
  recPrint(root);
}

template <class type>
type TBST<type>::getNode(type i){
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
      if (curr == NULL){
        return '\0';
      }
    }
    return curr->key;
  }
}

template <class type>
TTreeNode<type>* TBST<type>::getTreeNode(type i){
  if(isEmpty()){
    return NULL;
  } else {
    TTreeNode<type> *curr = root;
    while (curr->key != i){
      if (i < curr->key){
          curr = curr->left;
      } else {
        curr = curr->right;
      }
      if (curr == NULL){
        return NULL;
      }
    }
    return curr;
  }
}

template <class type>
type TBST<type>::getMax(){
  TTreeNode<type> *curr = root;

  if(isEmpty()){
    return NULL;
  }
  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr->key;
}

template <class type>
type TBST<type>::getMin(){
  TTreeNode<type> *curr = root;

  if(isEmpty()){
    return '\0';
  }
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr->key;
}

template <class type>
void TBST<type>::insertNode(type value){
  TTreeNode<type> *node = new TTreeNode<type>(value); //key is now set to value
  //check if value exist, if not continue
  if(isEmpty()){ //empty tree
    root = node;
  } else{ //not an empty tree, now we need to find insertion point
    TTreeNode<type> *parent = NULL; //empty node
    TTreeNode<type> *curr = root;
    while(true){
      parent = curr;
      //error checking
      if (value < curr->key){
        curr = curr->left; //going left
        if (curr == NULL){ //new home found for new node
          parent->left = node;
          break;
        }
        //else keep looping
      } else {
        curr = curr->right;
        if (curr == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
  size++;
}

template <class type>
bool TBST<type>::searchNode(type value){

  if(isEmpty()){
    return false;
  } else { //not an empty tree
    TTreeNode<type> *curr = root;
    while (curr->key != value){
      if (value < curr->key){ //go left
        curr = curr->left;
      } else {
        curr = curr->right;
      }
      if (curr == NULL){
        return false;
      }
    }
    return true;
  }
}

template <class type>
bool TBST<type>::deleteNode(type value){
  if(isEmpty()){
    return false;
  }
  TTreeNode<type> *part = NULL;
  TTreeNode<type> *curr = root;
  bool isLeft = true;
  //finding the node we want to delete
  while (curr->key != value){
    part = curr;
    if (value < curr->key){ //left child
      curr = curr->left;
      isLeft = true;
    } else { //right child
      curr = curr->right;
      isLeft = false;
    }
    if (curr == NULL){
      return false;
    }
  }
  //node point has been found

  size--;
  //leaf node deleted
  if (curr->left == NULL && curr->right == NULL){
    if (curr == root){ //tree has the root as it's only element
      root = NULL;
    } else if (isLeft) { //the child is a left child
      part->left = NULL;
    } else { //the child is a right child
      part->right = NULL;
    }
  }
  //case: deleted node has 1 child
  else if (curr->right == NULL){ //is left child and the node we need to delete has no right child
    if (curr == root){
      root = curr->left;
    } else if (isLeft) { //the deleting node is a left child
      part->left = curr->left;
    } else { //the deleting node is a right child of the partner
      part->right = curr->left;
    }
  } else if (curr->left == NULL){ //is right child and the node we need to delete has no left child
    if (curr == root){
      root = curr->right;
    } else if (isLeft) { //node we need to delete is a left child of a parent node
      part->left = curr->right;
    } else { //node we need to deelte is a right child of a parent node
      part->right = curr->right;
    }
  } else { //the dreaded double children
    TTreeNode<type> *successor = getSuccessor(curr); //finding the successor of the deleting node which is current

    if (curr == root){
      root = successor;
    } else if (isLeft){
      part->left = successor;
    } else {
      part->right = successor;
    }

    successor->left = curr->left;
  }
  curr->left = NULL;
  curr->right = NULL;
  delete curr; //QUESTION do WE garbage collect in the delete function????
  return true;
}

template <class type>
TTreeNode<type>* TBST<type>::getSuccessor(TTreeNode<type> *d){ //d represents the deleted node
  TTreeNode<type> *curr = d->right;
  TTreeNode<type> *succ = d;
  TTreeNode<type> *sp = d; //successors parent

  while (curr != NULL){
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
bool TBST<type>::isEmpty(){
  if (getSize() == 0){
    return true;
  } else {
    return false;
  }
}

template <class type>
unsigned int TBST<type>::getSize(){
  return size;
}
