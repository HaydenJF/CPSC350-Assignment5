#include "calling.h"
#include <fstream>
#include <bitset>
#include <sstream>
#include <string>
#include <iostream>

#include <typeinfo>

using namespace std;

calling::calling(){
  getFiles();
}

calling::~calling(){
  ofstream fileS;
  fileS.open (studentFile);
  if (fileS.is_open()) {
    while (studentTree->getSize() > 0){
      student s = studentTree->getMin();
      for (int i = 0; i < s.look().length(); ++i){
        bitset<8> temp(s.look()[i]);
        fileS << temp.to_string();
      }
      fileS << "\n";
      studentTree->deleteNode(s);
    }
  }
  fileS.close();

  ofstream fileT;
  fileT.open (teacherFile);
  if (fileT.is_open()) {
    while (teacherTree->getSize() > 0){
      teacher t = teacherTree->getMin();
      for (int i = 0; i < t.look().length(); ++i){
        bitset<8> temp(t.look()[i]);
        fileT << temp.to_string();
      }
      fileT << "\n";
      teacherTree->deleteNode(t);
    }
  }
  fileT.close();

}

void calling::getFiles(){
  string tempLine;
  ifstream fileS(studentFile);

  if (fileS.is_open()) {
    sArray = new student[128];
    while (getline(fileS, tempLine)) {

      stringstream sstream(tempLine);
      string output;
      while(sstream.good())
      {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
      }
      //(id)[name]<grade>{major}!gpa@#advisor$
      //(145)[Nick Man]<Sophmore>{Communications}!4.3@#423$
      //cout << output << endl;
        string i = output.substr(output.find("(")+1, output.find(")")-1);
        int id = atoi(i.c_str());
        int n1 = output.find("[")+1;
        int n2 = output.find("]");
        string name = output.substr(n1, n2-n1);
        int g1 = output.find("<")+1;
        int g2 = output.find(">");
        string grade = output.substr(g1, g2-g1);
        int m1 =output.find("{")+1;
        int m2 = output.find("}");
        string major = output.substr(m1, m2-m1);
        double gpa = stod(output.substr(output.find("!")+1, output.find("@")-1));
        string a = output.substr(output.find("#")+1, output.find("$")-1);
        int advisor = atoi(a.c_str());
        if (numS == maxS){
          reconstructS();
        }
        sArray[numS] = student(id, name, grade, major, gpa, advisor);
        numS++;
    }
    studentTree = new TBST<student>();
    createTreeS(-1, ((-1+numS)/2), numS);
  }
  string tempLine2;
  ifstream fileT(teacherFile);
  if (fileT.is_open()) {
    tArray = new teacher[128];
    while (getline(fileT, tempLine2)) {
      stringstream sstream(tempLine2);
      string output;
      while(sstream.good())
      {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
      }
      //(id)[name]<level>{department}:num,:num,:num,
      //(145)[Nick Man]<Something>{Communications}:111,:121,:143,
      //cout << output << endl;
        string i = output.substr(output.find("(")+1, output.find(")")-1);
        int id = atoi(i.c_str());
        int n1 = output.find("[")+1;
        int n2 = output.find("]");
        string name = output.substr(n1, n2-n1);
        int l1 = output.find("<")+1;
        int l2 = output.find(">");
        string level = output.substr(l1, l2-l1);
        int d1 =output.find("{")+1;
        int d2 = output.find("}");
        string department = output.substr(d1, d2-d1);
        string tempOut = output;
        int tot = 0;
        while(tempOut.find(":") != string::npos){
          tot++;
          tempOut = tempOut.substr(tempOut.find(":") + 1);
        }

        string arrayT = "";
        if(output.find(":") != string::npos){
          int t1 = output.find(":");
          string temp = output.substr(t1);
          arrayT = temp;
        }
        if (numT == maxT){
          reconstructT();
        }
        tArray[numT] = teacher(id, name, level, department, arrayT, tot);
        numT++;
    }
    teacherTree = new TBST<teacher>();
    createTreeT(-1, ((-1+numT)/2), numT);
  }
  fileS.close();
  fileT.close();
  stack = new GenStack<stackNode<Person>>();
  stack->push(stackNode<Person>());
  askWhat();
}

void calling::createTreeT(int bottom, int middle, int top){
  teacherTree->insertNode(tArray[middle]);
  int tempLow = (bottom + middle)/2;
  int tempHigh = (top + middle)/2;
  if (middle - bottom > 1){
    createTreeT(bottom, tempLow, middle);
  }
  if (top - middle > 1){
    createTreeT(middle, tempHigh, top);
  }
}

void calling::createTreeS(int bottom, int middle, int top){
  studentTree->insertNode(sArray[middle]);
  int tempLow = (bottom + middle)/2;
  int tempHigh = (top + middle)/2;
  if (middle - bottom > 1){
    createTreeS(bottom, tempLow, middle);
  }
  if (top - middle > 1){
    createTreeS(middle, tempHigh, top);
  }
}



void calling::reconstructS(){
  int oldSize = maxS;
  maxS = maxS*2;
  student *newArray = new student[maxS];
  for (int i = 0; i < oldSize; ++i) {
    newArray[i] = sArray[i];
  }
  sArray = newArray;
}

void calling::reconstructT(){
  int oldSize = maxT;
  maxT = maxT*2;
  teacher *newArray = new teacher[maxT];
  for (int i = 0; i < oldSize; ++i) {
    newArray[i] = tArray[i];
  }
  tArray = newArray;
}

void calling::askWhat(){
  cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
  cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
  cout << "3. Find and display student information given the students id" << endl;
  cout << "4. Find and display faculty information given the faculty id" << endl;
  cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
  cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
  cout << "7. Add a new student" << endl;
  cout << "8. Delete a student given the id" << endl;
  cout << "9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member given the id." << endl;
  cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
  cout << "12. Remove an advisee from a faculty member given the ids" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;
  string c;
  cin >> c;
  if (c == "1"){
    Q1();
  } else if (c == "2"){
    Q2();
  } else if (c == "3"){
    Q3();
  } else if (c == "4"){
    Q4();
  } else if (c == "5"){
    Q5();
  } else if (c == "6"){
    Q6();
  } else if (c == "7"){
    Q7();
  } else if (c == "8"){
    Q8();
  } else if (c == "9"){
    Q9();
  } else if (c == "10"){
    Q10();
  } else if (c == "11"){
    Q11();
  } else if (c == "12"){
    Q12();
  } else if (c == "13"){
    Q13();
  } else if (c == "14"){
    Q14();
  } else {
    cout << "Please input a number 1-14." << endl;
    askWhat();
  }

}

void calling::Q1(){
  studentTree->printEntireTree();
  askWhat();
}

void calling::Q2(){
  teacherTree->printEntireTree();
  askWhat();
}

void calling::Q3(){
  cout << "What is ID?" << endl;
  string c;
  cin >> c;
  student s = studentTree->getNode(atoi(c.c_str()));
  cout << s << endl;
  askWhat();
}

void calling::Q4(){
  cout << "What is ID?" << endl;
  string c;
  cin >> c;
  teacher t = teacherTree->getNode(atoi(c.c_str()));
  cout << t << endl;
  askWhat();
}

void calling::Q5(){
  cout << "What is ID?" << endl;
  string c;
  cin >> c;
  student s = studentTree->getNode(atoi(c.c_str()));
  teacher t = teacherTree->getNode(s.getAdvisor());
  cout << t << endl;
  askWhat();
}

void calling::Q6(){
  cout << "What is ID?" << endl;
  string c;
  cin >> c;
  teacher t = teacherTree->getNode(atoi(c.c_str()));
  string sts = t.array();
  while (sts.find(":") != string::npos){
    int s1 = sts.find(":")+1;
    int s2 = sts.find(",");
    string temp = sts.substr(s1, s2-s1);
    student s = studentTree->getNode(atoi(temp.c_str()));
    cout << s << endl;
    sts = sts.substr(s1);
  }

  askWhat();
}

void calling::Q7(){
  string i, n, y, m, g, t;
  cout << "ID: ";
  cin >> i;
  cout << endl;
  cout << "Name: ";
  cin >> n;
  cout << endl;
  cout << "Year: ";
  cin >> y;
  cout << endl;
  cout << "Major: ";
  cin >> m;
  cout << endl;
  cout << "GPA: ";
  cin >> g;
  cout << endl;
  cout << "Advisor: ";
  cin >> t;
  cout << endl;

  student s = student(atoi(i.c_str()), n, y, m, stod(g), atoi(t.c_str()));
  studentTree->insertNode(s);
  stackNode<Person> node = stackNode<Person>("7", s);
  stack->push(node);
  askWhat();
}

void calling::Q8(){
  cout << "What is ID?" << endl;
  string c;
  cin >> c;
  student s = studentTree->getNode(atoi(c.c_str()));
  stackNode<Person> node = stackNode<Person>("8", s);
  stack->push(node);
  studentTree->deleteNode(s);

  askWhat();
}

void calling::Q9(){
  string i, n, l, d, s;
  cout << "ID: ";
  cin >> i;
  cout << endl;
  cout << "Name: ";
  cin >> n;
  cout << endl;
  cout << "Level: ";
  cin >> l;
  cout << endl;
  cout << "Department: ";
  cin >> d;
  int tot = 0;
  cout << endl;
  cout << "Enter all the student IDs the teacher needs.  Type done when done: " << endl;
  bool run = true;
  while (run == true){
    string tempS;
    cin >> tempS;
    if (tempS != "done"){
      s += ":" + tempS + ",";
      tot++;
    } else {
      run = false;
    }

  }


  teacher t = teacher(atoi(i.c_str()), n, l, d, s, tot);
  teacherTree->insertNode(t);
  stackNode<Person> node = stackNode<Person>("9", t);
  stack->push(node);
  askWhat();
}

void calling::Q10(){
  cout << "What is ID?" << endl;
  string c;
  cin >> c;
  teacher t = teacherTree->getNode(atoi(c.c_str()));
  stackNode<Person> node = stackNode<Person>("10", t);
  stack->push(node);
  teacherTree->deleteNode(t);

  askWhat();
}

void calling::Q11(){
  cout << "What is ID?" << endl;
  string c1;
  cin >> c1;
  cout << "What is new advisor ID?" << endl;
  string c2;
  cin >> c2;
  student s = studentTree->getNode(atoi(c1.c_str()));
  int ad = s.getAdvisor();
  TTreeNode<student> *ts = studentTree->getTreeNode(s);
  ts->key.advisor = atoi(c2.c_str());

  stackNode<Person> node = stackNode<Person>("11", s, ad);
  stack->push(node);
  askWhat();
}

void calling::Q12(){
  cout << "What is ID?" << endl;
  string c1;
  cin >> c1;
  cout << "What is student ID?" << endl;
  string c2;
  cin >> c2;

  teacher t = teacherTree->getNode(atoi(c1.c_str()));
  TTreeNode<teacher> *ts = teacherTree->getTreeNode(t);
  ts->key.removeStudent(atoi(c2.c_str()));
  cout << ts->key << endl;
  //stackNode<Person> node = stackNode<Person>("12", t, atoi(c2.c_str()));
  //stack->push(node);

  askWhat();
}

void calling::Q13(){
  stackNode<Person> node = stack->peek();
  /*if (node.endisHere()){
    cout << "You have no Rollbacks left." << endl;
  } else if (node.getString() == "7"){
    student s1 = (student)(node.getType());
    studentTree->deleteNode(s1);
    stack->pop();
  } else if (node.getString() == "8"){
    studentTree->insertNode(node.getType());
    stack->pop();
  } else if (node.getString() == "9"){
    teacherTree->deleteNode(node.getType());
    stack->pop();
  } else if (node.getString() == "10"){
    teacherTree->insertNode(node.getType());
    stack->pop();
  } //else if (node.getString() == "11"){*/

  //}
  askWhat();
}

void calling::Q14(){

}
