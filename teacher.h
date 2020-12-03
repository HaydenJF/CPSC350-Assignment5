#include "person.h"


class teacher : public Person {
  public:
    teacher();
    teacher(int i);
    teacher(int i, string n, string l, string d, string s, int numS);
    ~teacher();
    string look();
    int getID();
    string array();
    bool hasStudent(int i);
    void addStudent(int student);
    void removeStudent(int student);
    string createString();
    bool operator>(teacher s);
    bool operator<(teacher s);
    bool operator!=(teacher s);

    int arraySize;
    int numStudents;

    int test;

    int id;
    string name;
    string level;
    string department;
    string students;
    string studs;
};

ostream& operator<<(ostream& output, const teacher& T);
