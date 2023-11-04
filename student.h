#ifndef UNTITLED3_STUDENT_H
#define UNTITLED3_STUDENT_H

#include "identity.h"

#include <vector>

#include "computer.h"

class Student : public Identity {
public:
    Student();

    Student(int id, string name, int password);

    void openMenu() override;

    void applyOrder();

    void showMyOrder();

    void showAllOrder();

    void cancelOrder();

    int id;//学号

    vector<Computer> vCom;//存放机房号

    void intiVector();
};

#endif //UNTITLED3_STUDENT_H
