#include "GenStack.h"
#include "student.h"
#include "teacher.h"
#include "TBST.h"
#include "stackNode.h"

class calling{
  public:
    calling();
    ~calling();
    void getFiles();
    void askWhat();

    void createTreeS(int n1, int n2, int n3);
    void createTreeT(int n1, int n2, int n3);
    void reconstructS();
    void reconstructT();

    void Q1();
    void Q2();
    void Q3();
    void Q4();
    void Q5();
    void Q6();
    void Q7();
    void Q8();
    void Q9();
    void Q10();
    void Q11();
    void Q12();
    void Q13();
    void Q14();
  private:
    string studentFile = "studentTable";
    string teacherFile = "facultyTable";
    TBST<student> *studentTree;
    TBST<teacher> *teacherTree;
    GenStack<stackNode<Person>> *stack;

    int numS = 0;
    student* sArray;
    int maxS = 128;

    int numT = 0;
    teacher* tArray = new teacher[128];
    int maxT = 128;

};
