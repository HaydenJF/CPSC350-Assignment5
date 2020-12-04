#include "student.h"

student::student(){
  id = 0;
  name = "";
  level = "";
  major = "";
  gpa = 0.0;
  advisor = 0;
}

student::student(int i){
  id = i;
  name = "";
  level = "";
  major = "";
  gpa = 0.0;
  advisor = 0;
}

student::student(int i, string n, string l, string m, double g, int a){
  id = i;
  name = n;
  level = l;
  major = m;
  gpa = g;
  advisor = a;
}

student::~student(){} //no need for a destructor, since there is no dynamically allocated memory

string student::look(){
  string s = "";
  s += "(" + to_string(id) + ")";
  s += "[" + name + "]";
  s += "<" + level + ">";
  s += "{" + major + "}";
  s += "!" + to_string(gpa) + "@";
  s += "#" + to_string(advisor) + "$";
  return s;
}

int student::getID(){
  return id;
}

int student::getAdvisor(){
  return advisor;
}

void student::changeAdvisor(int i){
  advisor = i;
}

bool student::operator>(student s){
  if (id > s.getID()){
    return true;
  } else {
    return false;
  }
}

bool student::operator<(student s){
  if (id < s.getID()){
    return true;
  } else {
    return false;
  }
}

ostream& operator<<(ostream& o, const student& s){ //output stream to write the infromation out 
  o << "ID: " << s.id << endl
    << "Name: " << s.name << endl
    << "Year: " << s.level << endl
    << "Major: " << s.major << endl
    << "GPA: " << s.gpa << endl
    << "Advisor: " << s.advisor << endl;

  return o;
}

bool student::operator!=(student s){
  if (id == s.getID()){
    return false;
  } else {
    return true;
  }
}
