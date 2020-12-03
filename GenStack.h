//implementation for GenStack.h
#include <iostream>

using namespace std;

//header file for the GenStack class
template <class type>
class GenStack{
  public:
      GenStack(); //Constructor
      GenStack(int maxSize); //Constructor with a max size.
      ~GenStack(); //Destructor

      void push(type data); //Adds something to the stack
      type pop(); //Deletes something from the stack
      type peek(); //Prints out first item stack

      bool isFull(); //Checks if full
      bool isEmpty(); //Checks if empty
      int getSize(); //gives the size of the stack

  private:
    int top; //first position in stack
    int mSize; //max size of stack
    type *myArray; //the stack

    void rebuild(); //if the stack is full and want to add more it doubles the max size
};



template <class type>
GenStack<type>::GenStack(){ //Constructor
  myArray = new type[128];
  mSize = 128;
  top = -1;
}

template <class type>
GenStack<type>::GenStack(int maxSize) { //Constructor with a max size.
  myArray = new type[maxSize];
  mSize = maxSize;
  top = -1;
}

template <class type>
GenStack<type>::~GenStack(){ //Destructor
  delete myArray;
}

template <class type>
void GenStack<type>::push(type data){ //Adds something to the stack
  if (isFull()) {
    rebuild();
  }
  myArray[++top] = data;
}

template <class type>
void GenStack<type>::rebuild(){ //if the stack is full and want to add more it doubles the max size
  int oldSize = mSize;
  mSize = mSize*2;
  type *newArray = new type[mSize];
  for (int i = 0; i < oldSize; ++i) {
    newArray[i] = myArray[i];
  }
  myArray = newArray;
}

template <class type>
type GenStack<type>::pop(){ //Deletes something from the stack
  if(isEmpty()){
    throw invalid_argument("You can't delete from an empty stack!");
  } else {
    return myArray[top--]; //postdecrement means gets value of top then update top

  }
}

template <class type>
type GenStack<type>::peek(){ //Prints out first item stack
    return myArray[top];
}

template <class type>
bool GenStack<type>::isFull(){ //Checks if full
  return (top == mSize-1);
}

template <class type>
bool GenStack<type>::isEmpty(){ //Checks if empty
  return (top == -1);
}

template <class type>
int GenStack<type>::getSize(){ //gives the size of the stack
  return (top+1);
}
