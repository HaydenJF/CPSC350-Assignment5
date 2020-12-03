#include "teacher.h"

teacher::teacher(){}

teacher::teacher(int i){
  id = i;
}

teacher::teacher(int i, string n, string l, string d, string s, int numS){
  id = i;
  name = n;
  level = l;
  department = d;
  students = s;
  numStudents = numS;
  studs = createString();

}

teacher::~teacher(){
}

string teacher::look(){
  string t = "";
  t += "(" + to_string(id) + ")";
  t += "[" + name + "]";
  t += "<" + level + ">";
  t += "{" + department + "}";
  t += students;
  return t;
}

int teacher::getID(){
  return id;
}

string teacher::array(){
  return students;
}

bool teacher::hasStudent(int n){
  if (students.find(to_string(n)) != string::npos){
    return true;
  }
  return false;
}

void teacher::addStudent(int student){
  if (!hasStudent(student)){
    students += ":" + to_string(student) + ",";
    numStudents++;
    studs = createString();
  }
}

void teacher::removeStudent(int student){
  if (hasStudent(student)){
    if (students.find(to_string(student)) == 1){
      string s2 = students.substr(students.find(to_string(student))+to_string(student).length()+1);
      students = s2;
      cout << s2 << endl;
    } else if (students.rfind(":") + 1 == students.find(to_string(student))){
      string s1 = students.substr(0, students.find(to_string(student))-1);
      students = s1;
    } else {
      string s1 = students.substr(0, students.find(to_string(student)));
      string s2 = students.substr(students.find(to_string(student))+to_string(student).length()+2);
      students = s1 + s2;
    }
    numStudents--;
    studs = createString();
  }
}


bool teacher::operator>(teacher t){
  if (id > t.getID()){
    return true;
  } else {
    return false;
  }
}

bool teacher::operator<(teacher t){
  if (id < t.getID()){
    return true;
  } else {
    return false;
  }
}

string teacher::createString(){
  string s = "";
  string tempS = students;
  while (tempS.find(":") != string::npos){
    int s1 = tempS.find(":")+1;
    int s2 = tempS.find(",");
    s += tempS.substr(s1, s2-s1) + "\n";
    tempS = tempS.substr(s2+1);
  }
  return s;
}

ostream& operator<<(ostream& o, const teacher& t){
  o << "ID: " << t.id << endl
    << "Name: " << t.name << endl
    << "Year: " << t.level << endl
    << "Major: " << t.department << endl
    << "Students: " << endl << t.studs << endl;


  return o;
}

bool teacher::operator!=(teacher t){
  if (id == t.getID()){
    return false;
  } else {
    return true;
  }
}
