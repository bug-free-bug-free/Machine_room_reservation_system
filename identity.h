#ifndef UNTITLED3_IDENTITY_H
#define UNTITLED3_IDENTITY_H
#include <iostream>
using namespace std;
class Identity{
public:
    virtual void openMenu()=0;
    string name;
    int password;
};
#endif