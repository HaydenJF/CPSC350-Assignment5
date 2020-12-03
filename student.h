#include "person.h"

class student : public Person {
  public:
    student();
    student(int i);
    student(int i, string n, string l, string m, double g, int a);
    ~student();
    string look();
    int getID();
    int getAdvisor();
    void changeAdvisor(int i);
    bool operator>(student s);
    bool operator<(student s);
    bool operator!=(student s);

    int id;
    string name;
    string level;
    string major;
    double gpa;
    int advisor;
};

ostream& operator<<(ostream& output, const student& S);
