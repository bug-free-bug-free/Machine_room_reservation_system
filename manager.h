//
// Created by 28167 on 2023/11/2.
//

#ifndef UNTITLED3_MANAGER_H
#define UNTITLED3_MANAGER_H
#include "identity.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computer.h"
class Manager: public Identity{
public:
    Manager();
    Manager(string name,int password);
    void openMenu()override;
    void addPerson();
    void showPerson();
    void showComputer();
    void clearFile();
    vector<Student> vStu;
    vector<Teacher> vTec;
    vector<Computer> vCom;
    void initVector();
    bool checkRepeat(int id,int type);
};


#endif //UNTITLED3_MANAGER_H
