#include <iostream>
#include "teacher.h"
#include "orderfile.h"
Teacher::Teacher() {

}

Teacher::Teacher(int empId, string name, int password)
{

}

void Teacher::openMenu() {
    cout<<"-----欢迎教师"<<name<<"登录-----"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"|\t1.查看所有预约\t|"<<endl;
    cout<<"|\t2.审核预约\t|"<<endl;
    cout<<"|\t0.注销登录\t|"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"请选择你的操作："<<endl;
}

void Teacher::showOrder() {
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

void Teacher::validOrder() {
    OrderFile f;
    while(true){
        showOrder();
        cout<<"请选择要修改的记录（输入0可退出修改模式）"<<endl;
        int select;
        cin>>select;
        if(!select)break;
        cout<<"请选择修改的模式"<<endl;
        cout<<"1.通过"<<endl;
        cout<<"0.不通过"<<endl;
        int choice;
        cin>>choice;
        auto p=f.orderData[select-1].find("state");
        if(p!=f.orderData[select-1].end()){
            if(choice==1)p->second="2";
            else p->second="3";
        }
        f.updateOrder();
        cout<<"修改成功"<<endl;
    }

}