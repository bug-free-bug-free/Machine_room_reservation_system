#include "manager.h"
#include <fstream>
Manager::Manager() {
    initVector();
}

Manager::Manager(string name, int password)
//:name(name),password(password)
{
    this->password=password;
    this->name=name;
    initVector();
}

void Manager::openMenu() {
    cout<<"-----欢迎管理员"<<name<<"登录-----"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"|\t1.添加账号\t|"<<endl;
    cout<<"|\t2.查看账号\t|"<<endl;
    cout<<"|\t3.查看机房\t|"<<endl;
    cout<<"|\t4.清空预约\t|"<<endl;
    cout<<"|\t5.注销登录\t|"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"请选择你的操作："<<endl;
}

void Manager::addPerson() {
    cout<<"请输入添加账号的类型"<<endl;
    cout<<"1.添加学生"<<endl;
    cout<<"2.添加老师"<<endl;
    int select;
    cin>>select;

    int fid;
    string fname;
    int fpassword;
    fstream f;
    if(select==1){
        f.open("student.txt",ios::out|ios::app);
        cout<<"请输入学号"<<endl;
    }else{
        f.open("teacher.txt",ios::out|ios::app);
        cout<<"请输入职工号"<<endl;
    }
    cin>>fid;
    if(checkRepeat(fid,select)){
        cout<<"输入的学号/职工号重复"<<endl;
        return ;
    }
    cout<<"请输入姓名"<<endl;
    cin>>fname;
    cout<<"请输入密码"<<endl;
    cin>>fpassword;
    f<<fid<<' '<<fname<<' '<<fpassword<<endl;
    cout<<"添加成功"<<endl;
    f.close();
    initVector();
}

void Manager::showPerson() {
//查看账号
    cout<<"请输入查看账号的类型"<<endl;
    cout<<"1.学生"<<endl;
    cout<<"2.老师"<<endl;
    int select;
    cin>>select;
    fstream f;
    string s;
    if(select==1){
        cout<<"所有学生的信息如下"<<endl;
        f.open("student.txt",ios::in);
        while(getline(f,s)){
            cout<<s<<endl;
        }
    }else{
        cout<<"所有老师的信息如下"<<endl;
        f.open("teacher.txt",ios::in);
        while(getline(f,s)){
            cout<<s<<endl;
        }
    }
}

void Manager::showComputer() {
    cout<<"机房的信息如下"<<endl;
    for(auto p:vCom){
        cout<<"机房编号:"<<p.id<<"机房最大容量"<<p.num<<endl;
    }
}
void Manager::clearFile(){
    ofstream f("order.txt",ios::trunc);
    f.close();
    cout<<"预约清空成功"<<endl;
}
void Manager::initVector(){
    fstream f;
    vStu.clear();
    vTec.clear();
    vCom.clear();
    f.open("student.txt",ios::in);
    Student student;
    while(f>>student.id&&f>>student.name&&f>>student.password){
        vStu.push_back(student);
    }
    cout<<"当前学生数量为"<<vStu.size()<<endl;
    f.close();

    f.open("teacher.txt",ios::in);
    Teacher teacher;
    while(f>>teacher.empId&&f>>teacher.name&&f>>teacher.password){
        vTec.push_back(teacher);
    }
    cout<<"当前教师数量为"<<vTec.size()<<endl;
    f.close();

    f.open("computerRoom.txt",ios::in);
    Computer computer;
    while(f>>computer.id&&f>>computer.num){
        vCom.push_back(computer);
    }
    cout<<"当前机房数量为"<<vCom.size()<<endl;
    f.close();
}

bool Manager::checkRepeat(int id,int type){
    if(type==1){
        for(auto p:vStu){
            if(p.id==id)return true;
        }
    }else{
        for(auto p:vTec){
            if(p.empId==id)return true;
        }
    }
    return false;
}