#include "student.h"

student::student(){//checks size
  id = 0;
  name = "";
  level = "";
  major = "";
  gpa = 0.0;
  advisor = 0;
}

student::student(int i){//constructor with just ID
  id = i;
  name = "";
  level = "";
  major = "";
  gpa = 0.0;
  advisor = 0;
}

student::student(int i, string n, string l, string m, double g, int a){//constructor with all values
  id = i;
  name = n;
  level = l;
  major = m;
  gpa = g;
  advisor = a;
}

student::~student(){}//destructor

string student::look(){//gives string for binary conversion
  string s = "";
  s += "(" + to_string(id) + ")";
  s += "[" + name + "]";
  s += "<" + level + ">";
  s += "{" + major + "}";
  s += "!" + to_string(gpa) + "@";
  s += "#" + to_string(advisor) + "$";
  return s;
}

int student::getID(){//gives id
  return id;
}

int student::getAdvisor(){//gives advisor id
  return advisor;
}

void student::changeAdvisor(int i){//changes advisor
  advisor = i;
}

bool student::operator>(student s){//makes it so can check > with student
  if (id > s.getID()){
    return true;
  } else {
    return false;
  }
}

bool student::operator<(student s){//makes it so can check < with student
  if (id < s.getID()){
    return true;
  } else {
    return false;
  }
}

ostream& operator<<(ostream& o, const student& s){//makes it so can print with student
  o << "ID: " << s.id << endl
    << "Name: " << s.name << endl
    << "Year: " << s.level << endl
    << "Major: " << s.major << endl
    << "GPA: " << s.gpa << endl
    << "Advisor: " << s.advisor << endl;

  return o;
}

bool student::operator!=(student s){//makes it so can check != with student
  if (id == s.getID()){
    return false;
  } else {
    return true;
  }
}
