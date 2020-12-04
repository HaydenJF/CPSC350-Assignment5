#include "GenStack.h"
#include "student.h"
#include "teacher.h"
#include "TBST.h"
#include "stackNode.h"

class calling{
  public:
    calling();//constructor
    ~calling();//destructor (also adds to file)
    void getFiles();//gets the trees ready and info from file
    void askWhat();//The repeating questions are here

    void createTreeS(int n1, int n2, int n3);//creates student tree
    void createTreeT(int n1, int n2, int n3);//creates teacher tree
    void reconstructS();//rebuilds student array if it gets too big
    void reconstructT();//rebuilds teacher array if it gets too big

    void Q1();//Print all students and their information (sorted by ascending id #)
    void Q2();//Print all faculty and their information (sorted by ascending id #)
    void Q3();//Find and display student information given the students id
    void Q4();//Find and display faculty information given the faculty id
    void Q5();//Given a student’s id, print the name and info of their faculty advisor
    void Q6();//Given a faculty id, print ALL the names and info of his/her advisees.
    void Q7();//Add a new student
    void Q8();//Delete a student given the id
    void Q9();//Add a new faculty member
    void Q10();//Delete a faculty member given the id.
    void Q11();//Change a student’s advisor given the student id and the new faculty id.
    void Q12();//Remove an advisee from a faculty member given the ids
    void Q13();//Rollsback whatever the user has been doing
  private:
    string studentFile = "studentTable";//student file
    string teacherFile = "facultyTable";//teacher file
    TBST<student> *studentTree;//student tree
    TBST<teacher> *teacherTree;//teacher tree
    GenStack<stackNode<string>> *stack;//stack for everything
    GenStack<stackNode<student>> *sStack;//stack for students
    GenStack<stackNode<teacher>> *tStack;//stack for teachers

    int numS = 0;//number of students
    student* sArray;//array for balancing student tree
    int maxS = 128;//make array size

    int numT = 0;//number of teachers
    teacher* tArray = new teacher[128];//array for balancing teacher tree
    int maxT = 128;//make array size

};
