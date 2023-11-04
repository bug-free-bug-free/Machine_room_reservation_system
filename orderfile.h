//
// Created by 28167 on 2023/11/3.
//

#ifndef UNTITLED3_ORDERFILE_H
#define UNTITLED3_ORDERFILE_H
#include <iostream>
#include <map>
#include <string>
using namespace std;

class OrderFile {
public:
    OrderFile();
    void updateOrder();//更新预约记录
    int size;
    map<int,map<string,string>> orderData;
    map<string,string> vData;
    map<string,string> vTime;
    map<string,string> vState;
    void intiVector();
};


#endif //UNTITLED3_ORDERFILE_H
