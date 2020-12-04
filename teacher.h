#include "person.h"


class teacher : public Person {
  public:
    teacher();//default constructor
    teacher(int i);//constructor with only id
    teacher(int i, string n, string l, string d, string s, int numS);//constructor with everything
    ~teacher();//destructor
    string look();//gives string for binary
    int getID();//gives the id
    string array();//gives list of students (in string form)
    bool hasStudent(int i);//checks if has a certain student
    void addStudent(int student);//adds a student
    void removeStudent(int student);//removes a student
    string createString();//sets stud for printing
    bool operator>(teacher s);//can check if teacher >
    bool operator<(teacher s);//can check if teacher <
    bool operator!=(teacher s);//can check if teacher !=

    //self explanitory (studs is string students printing)
    int numStudents;
    int id;
    string name;
    string level;
    string department;
    string students;
    string studs;
};

ostream& operator<<(ostream& output, const teacher& T);//prints teacher
