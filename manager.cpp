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
    cout<<"-----��ӭ����Ա"<<name<<"��¼-----"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"|\t1.����˺�\t|"<<endl;
    cout<<"|\t2.�鿴�˺�\t|"<<endl;
    cout<<"|\t3.�鿴����\t|"<<endl;
    cout<<"|\t4.���ԤԼ\t|"<<endl;
    cout<<"|\t5.ע����¼\t|"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"��ѡ����Ĳ�����"<<endl;
}

void Manager::addPerson() {
    cout<<"����������˺ŵ�����"<<endl;
    cout<<"1.���ѧ��"<<endl;
    cout<<"2.�����ʦ"<<endl;
    int select;
    cin>>select;

    int fid;
    string fname;
    int fpassword;
    fstream f;
    if(select==1){
        f.open("student.txt",ios::out|ios::app);
        cout<<"������ѧ��"<<endl;
    }else{
        f.open("teacher.txt",ios::out|ios::app);
        cout<<"������ְ����"<<endl;
    }
    cin>>fid;
    if(checkRepeat(fid,select)){
        cout<<"�����ѧ��/ְ�����ظ�"<<endl;
        return ;
    }
    cout<<"����������"<<endl;
    cin>>fname;
    cout<<"����������"<<endl;
    cin>>fpassword;
    f<<fid<<' '<<fname<<' '<<fpassword<<endl;
    cout<<"��ӳɹ�"<<endl;
    f.close();
    initVector();
}

void Manager::showPerson() {
//�鿴�˺�
    cout<<"������鿴�˺ŵ�����"<<endl;
    cout<<"1.ѧ��"<<endl;
    cout<<"2.��ʦ"<<endl;
    int select;
    cin>>select;
    fstream f;
    string s;
    if(select==1){
        cout<<"����ѧ������Ϣ����"<<endl;
        f.open("student.txt",ios::in);
        while(getline(f,s)){
            cout<<s<<endl;
        }
    }else{
        cout<<"������ʦ����Ϣ����"<<endl;
        f.open("teacher.txt",ios::in);
        while(getline(f,s)){
            cout<<s<<endl;
        }
    }
}

void Manager::showComputer() {
    cout<<"��������Ϣ����"<<endl;
    for(auto p:vCom){
        cout<<"�������:"<<p.id<<"�����������"<<p.num<<endl;
    }
}
void Manager::clearFile(){
    ofstream f("order.txt",ios::trunc);
    f.close();
    cout<<"ԤԼ��ճɹ�"<<endl;
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
    cout<<"��ǰѧ������Ϊ"<<vStu.size()<<endl;
    f.close();

    f.open("teacher.txt",ios::in);
    Teacher teacher;
    while(f>>teacher.empId&&f>>teacher.name&&f>>teacher.password){
        vTec.push_back(teacher);
    }
    cout<<"��ǰ��ʦ����Ϊ"<<vTec.size()<<endl;
    f.close();

    f.open("computerRoom.txt",ios::in);
    Computer computer;
    while(f>>computer.id&&f>>computer.num){
        vCom.push_back(computer);
    }
    cout<<"��ǰ��������Ϊ"<<vCom.size()<<endl;
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