#include "person.h"

class student : public Person {
  public:
    student();//default constructor
    student(int i);//constructor with just ID
    student(int i, string n, string l, string m, double g, int a); //constructor with all values
    ~student();//destructor
    string look();//gives string for binary conversion
    int getID();//gives id
    int getAdvisor();//gives advisor id
    void changeAdvisor(int i);//changes advisor
    bool operator>(student s);//makes it so can check > with student
    bool operator<(student s);//makes it so can check < with student
    bool operator!=(student s);//makes it so can check != with student

    //these names are self explanitory
    int id;
    string name;
    string level;
    string major;
    double gpa;
    int advisor;
};

ostream& operator<<(ostream& output, const student& S);//makes it so can print with student
