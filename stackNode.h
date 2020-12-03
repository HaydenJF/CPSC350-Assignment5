#include <iostream>

using namespace std;

template <class type>
class stackNode{
  public:
    stackNode();
    stackNode(string s, type t);
    stackNode(string s, type t, int o);
    ~stackNode();

    string getString();
    type getType();
    int getOld();
    bool endisHere();

  private:
    string playback;
    type object;
    int old;
    bool end;
};

template <class type>
stackNode<type>::stackNode(){
  end = true;
}

template <class type>
stackNode<type>::stackNode(string s, type t){
  playback = s;
  object = t;
  old = -1;
  end = false;
}

template <class type>
stackNode<type>::stackNode(string s, type t, int o){
  playback = s;
  object = t;
  old = o;
  end = false;
}

template <class type>
stackNode<type>::~stackNode(){}

template <class type>
string stackNode<type>::getString(){
  return playback;
}

template <class type>
type stackNode<type>::getType(){
  return object;
}

template <class type>
int stackNode<type>::getOld(){
  return old;
}

template <class type>
bool stackNode<type>::endisHere(){
  return end;
}
