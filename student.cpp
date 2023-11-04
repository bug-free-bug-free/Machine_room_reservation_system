#include <iostream>
#include "student.h"
#include <fstream>
#include <string>
#include "orderfile.h"
Student::Student() {

}

Student::Student(int id, string name, int password) {
    this->id=id;
    this->name=name;
    this->password=password;
    intiVector();
}

void Student::openMenu() {
    cout<<"-----欢迎学生"<<name<<"登录-----"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"|\t1.申请预约\t|"<<endl;
    cout<<"|\t2.查看我的预约\t|"<<endl;
    cout<<"|\t3.查看所有预约\t|"<<endl;
    cout<<"|\t4.取消预约\t|"<<endl;
    cout<<"|\t0.注销登录\t|"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"请选择你的操作："<<endl;
}

void Student::applyOrder() {
    cout<<"机房预约时间是周一到周五"<<endl;
    cout<<"请输入申请预约的时间"<<endl;
    cout<<"1.周一"<<endl;
    cout<<"2.周二"<<endl;
    cout<<"3.周三"<<endl;
    cout<<"4.周四"<<endl;
    cout<<"5.周五"<<endl;
    int data,time,room;
    cin>>data;
    cout<<"请输入申请的时间段"<<endl;
    cout<<"1.上午"<<endl;
    cout<<"2.下午"<<endl;
    cin>>time;
    cout<<"请输入申请的房间号"<<endl;
    for(auto p:vCom){
        cout<<p.id<<' '<<p.num<<endl;
    }
    cin>>room;
    cout<<"预约成功，审核中"<<endl;
    ofstream f;
    f.open("order.txt",ios::out|ios::app);
    f<<"data"<<' '<<data<<' ';//日期
    f<<"time"<<' '<<time<<' ';//时间
    f<<"id"<<' '<<id<<' ';//学号
    f<<"name"<<' '<<name<<' ';//名字
    f<<"num"<<' '<<room<<' ';//房间号
    f<<"state"<<' '<<1<<' '<<endl;//状态
    f.close();
}

void Student::showMyOrder() {
    OrderFile f;
    if(f.size==0){
        cout<<"无任何记录"<<endl;
        return ;
    }
    for(int i=0;i<f.size;i++){
        if(atoi(f.orderData[i]["id"].c_str())==id){
            cout<<"日期 "<<f.vData[f.orderData[i]["data"]]<<' ';
            cout<<"时间 "<<f.vTime[f.orderData[i]["time"]]<<' ';
            cout<<"学号 "<<f.orderData[i]["id"]<<' ';
            cout<<"名字 "<<f.orderData[i]["name"]<<' ';
            cout<<"机房号 "<<f.orderData[i]["num"]<<' ';
            cout<<"审核状态 "<<f.vState[f.orderData[i]["state"]]<<endl;
        }
    }
}

//data 1 time 2 id 1 name 李亚航 num 3 state 1
void Student::showAllOrder() {
    OrderFile f;
    if(f.size==0){
        cout<<"无任何记录"<<endl;
        return ;
    }
    for(int i=0;i<f.size;i++){
            cout<<"日期 "<<f.vData[f.orderData[i]["data"]]<<' ';
            cout<<"时间 "<<f.vTime[f.orderData[i]["time"]]<<' ';
            cout<<"学号 "<<f.orderData[i]["id"]<<' ';
            cout<<"名字 "<<f.orderData[i]["name"]<<' ';
            cout<<"机房号 "<<f.orderData[i]["num"]<<' ';
            cout<<"审核状态 "<<f.vState[f.orderData[i]["state"]]<<endl;
    }
}

void Student::cancelOrder(){
//    cout<<"没做这个功能，嘿嘿嘿"<<endl;
    showMyOrder();
    cout<<"请确定是否取消预约："<<endl;
    cout<<"1.确定"<<endl;
    cout<<"0.不确定"<<endl;
    OrderFile f;
    int select;
    cin>>select;
    if(select==0)return;
    for(int i=0;i<f.size;i++){
        if(atoi(f.orderData[i]["id"].c_str())==id){
            auto p=f.orderData[i].find("state");
            if(p!=f.orderData[i].end()){
                p->second="0";
            }
        }
    }
    f.updateOrder();
    cout<<"修改成功"<<endl;
}

void Student::intiVector(){
    Computer computer;
    fstream f;
    f.open("computerRoom.txt",ios::in);
    while(f>>computer.id&&f>>computer.num){
        vCom.push_back(computer);
    }
    f.close();
}