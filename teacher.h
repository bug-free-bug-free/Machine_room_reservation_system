
#ifndef UNTITLED3_TEACHER_H
#define UNTITLED3_TEACHER_H
#include <iostream>
using namespace std;
#include "identity.h"
class Teacher:public Identity{
public:
    Teacher();
    Teacher(int empId,string name,int password);
    void openMenu()override;
    void showOrder();
    void validOrder();
    int empId;//职工号
};
#endif
