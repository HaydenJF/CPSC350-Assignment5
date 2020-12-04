#include <iostream>

using namespace std;

template <class type>
class stackNode{//node for reversing old stuff
  public:
    stackNode();//default constructor
    stackNode(string s, type t);//constructor with question and type object
    stackNode(string s, type t, int o);//constructor with both and old id
    ~stackNode();

    string getString();//returns question number
    type getType();//returns type object
    int getOld();//returns old ID
    bool endisHere();//check to make sure not to far in stack

  private:
    string playback;//question number
    type object;
    int old;//old id
    bool end;//makes sure doesn't hit end of stack
};

template <class type>
stackNode<type>::stackNode(){//default constructor
  end = true;
}

template <class type>
stackNode<type>::stackNode(string s, type t){//constructor with question and type object
  playback = s;
  object = t;
  old = -1;
  end = false;
}

template <class type>
stackNode<type>::stackNode(string s, type t, int o){//constructor with both and old id
  playback = s;
  object = t;
  old = o;
  end = false;
}

template <class type>
stackNode<type>::~stackNode(){}//deconstructor

template <class type>
string stackNode<type>::getString(){//returns question number
  return playback;
}

template <class type>
type stackNode<type>::getType(){//returns type object
  return object;
}

template <class type>
int stackNode<type>::getOld(){//returns old ID
  return old;
}

template <class type>
bool stackNode<type>::endisHere(){//makes sure doesn't hit end of stack
  return end;
}
