#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "orderfile.h"
using namespace std;
void showMenu(){
    cout<<"-----欢迎来到机房预约系统-----"<<endl;
    cout<<"请输入你的身份："<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"|\t1.学生\t\t|"<<endl;
    cout<<"|\t2.老师\t\t|"<<endl;
    cout<<"|\t3.管理员\t|"<<endl;
    cout<<"|\t0.退出\t\t|"<<endl;
    cout<<"-------------------------"<<endl;
}

//void initFile(){
//    fstream f;
//    f.open("admin.txt",ios::out);
//    f.close();
//    f.open("student.txt",ios::out);
//    f.close();
//    f.open("teacher.txt",ios::out);
//    f.close();
//    f.open("computerRoom.txt",ios::out);
//    f.close();
//    f.open("order.txt",ios::out);
//    f.close();
//}

void managerMenu(Identity * man)
{
    Manager *manager=static_cast<Manager *>(man);
    while(true)
    {

        manager->openMenu();
        int select;
        cin>>select;
        switch (select)
        {
            case 1:{
                manager->addPerson();
                break;
            }
            case 2:{
                manager->showPerson();
                break;
            }
            case 3:{
                manager->showComputer();
                break;
            }
            case 4:{
                manager->clearFile();
                break;
            }
            case 5:{
                delete manager;
                cout<<"销毁成功"<<endl;
                return;
            }
        }
    }
}

void studentMenu(Identity * man)
{
    Student *student=static_cast<Student *>(man);
    while(true)
    {

        student->openMenu();
        int select;
        cin>>select;
        switch (select)
        {
            case 1:{
                student->applyOrder();
                break;
            }
            case 2:{
                student->showMyOrder();
                break;
            }
            case 3:{
                student->showAllOrder();
                break;
            }
            case 4:{
                student->cancelOrder();
                break;
            }
            case 0:{
                delete student;
                cout<<"销毁成功"<<endl;
                return;
            }
        }
    }
}

void teacherMenu(Identity * man)
{
    Teacher *teacher=static_cast<Teacher *>(man);
    while(true)
    {
        teacher->openMenu();
        int select;
        cin>>select;
        switch (select)
        {
            case 1:{
                teacher->showOrder();
                break;
            }
            case 2:{
                teacher->validOrder();
                break;
            }
            case 0:{
                delete teacher;
                cout<<"销毁成功"<<endl;
                return;
            }
        }
    }
}

void loginIn(int choice){
    fstream f;
    Identity *people= nullptr;
    int id;
    string name;
    int password;

    if(choice==1){
        cout<<"请输入学号："<<endl;
        cin>>id;
    }else if(choice==2){
        cout<<"请输入职工号："<<endl;
        cin>>id;
    }

    cout<<"请输入姓名："<<endl;
    cin>>name;
    cout<<"请输入密码："<<endl;
    cin>>password;

    int fid;
    string fname;
    int fpassword;

    if(choice==1){
        f.open("student.txt",ios::in);
        while(f>>fid&&f>>fname&&f>>fpassword){
            if(fid==id&&fname==name&&fpassword==password){
                cout<<"学生系统登录成功"<<endl;
                people=new Student(id,name,password);
                studentMenu(people);
                return;
            }
        }
    }else if(choice==2){
        f.open("teacher.txt",ios::in);
        while(f>>fid&&f>>fname&&f>>fpassword){
            cout<<fid<<fname<<fpassword<<endl;
            if(fid==id&&fname==name&&fpassword==password){
                cout<<"教师系统登录成功"<<endl;
                people=new Teacher(id,name,password);
                teacherMenu(people);
                return;
            }
        }
    }else{
        f.open("admin.txt",ios::in);
        while(f>>fname&&f>>fpassword){
            if(fname==name&&fpassword==password){
                cout<<"管理者系统登录成功"<<endl;
                people=new Manager(name,password);
                managerMenu(people);
                return;
            }
        }
    }
    cout<<"登录失败"<<endl;
    return ;
}


int main() {
//    initFile();
    while(true){
        showMenu();
        int choice=0;
        cin>>choice;
        switch (choice) {
            case 1:{
                loginIn(choice);
                break;
            }
            case 2:{
                loginIn(choice);
                break;
            }
            case 3:{
                loginIn(choice);
                break;
            }
            case 0:{
                cout<<"欢迎下次使用"<<endl;
                exit(0);
            }
            default:{
                cout<<"输入有误，请重新选择"<<endl;
                break;
            }

        }
    }
    return 0;
}
