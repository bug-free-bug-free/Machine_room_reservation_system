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
    cout<<"-----��ӭѧ��"<<name<<"��¼-----"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"|\t1.����ԤԼ\t|"<<endl;
    cout<<"|\t2.�鿴�ҵ�ԤԼ\t|"<<endl;
    cout<<"|\t3.�鿴����ԤԼ\t|"<<endl;
    cout<<"|\t4.ȡ��ԤԼ\t|"<<endl;
    cout<<"|\t0.ע����¼\t|"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"��ѡ����Ĳ�����"<<endl;
}

void Student::applyOrder() {
    cout<<"����ԤԼʱ������һ������"<<endl;
    cout<<"����������ԤԼ��ʱ��"<<endl;
    cout<<"1.��һ"<<endl;
    cout<<"2.�ܶ�"<<endl;
    cout<<"3.����"<<endl;
    cout<<"4.����"<<endl;
    cout<<"5.����"<<endl;
    int data,time,room;
    cin>>data;
    cout<<"�����������ʱ���"<<endl;
    cout<<"1.����"<<endl;
    cout<<"2.����"<<endl;
    cin>>time;
    cout<<"����������ķ����"<<endl;
    for(auto p:vCom){
        cout<<p.id<<' '<<p.num<<endl;
    }
    cin>>room;
    cout<<"ԤԼ�ɹ��������"<<endl;
    ofstream f;
    f.open("order.txt",ios::out|ios::app);
    f<<"data"<<' '<<data<<' ';//����
    f<<"time"<<' '<<time<<' ';//ʱ��
    f<<"id"<<' '<<id<<' ';//ѧ��
    f<<"name"<<' '<<name<<' ';//����
    f<<"num"<<' '<<room<<' ';//�����
    f<<"state"<<' '<<1<<' '<<endl;//״̬
    f.close();
}

void Student::showMyOrder() {
    OrderFile f;
    if(f.size==0){
        cout<<"���κμ�¼"<<endl;
        return ;
    }
    for(int i=0;i<f.size;i++){
        if(atoi(f.orderData[i]["id"].c_str())==id){
            cout<<"���� "<<f.vData[f.orderData[i]["data"]]<<' ';
            cout<<"ʱ�� "<<f.vTime[f.orderData[i]["time"]]<<' ';
            cout<<"ѧ�� "<<f.orderData[i]["id"]<<' ';
            cout<<"���� "<<f.orderData[i]["name"]<<' ';
            cout<<"������ "<<f.orderData[i]["num"]<<' ';
            cout<<"���״̬ "<<f.vState[f.orderData[i]["state"]]<<endl;
        }
    }
}

//data 1 time 2 id 1 name ���Ǻ� num 3 state 1
void Student::showAllOrder() {
    OrderFile f;
    if(f.size==0){
        cout<<"���κμ�¼"<<endl;
        return ;
    }
    for(int i=0;i<f.size;i++){
            cout<<"���� "<<f.vData[f.orderData[i]["data"]]<<' ';
            cout<<"ʱ�� "<<f.vTime[f.orderData[i]["time"]]<<' ';
            cout<<"ѧ�� "<<f.orderData[i]["id"]<<' ';
            cout<<"���� "<<f.orderData[i]["name"]<<' ';
            cout<<"������ "<<f.orderData[i]["num"]<<' ';
            cout<<"���״̬ "<<f.vState[f.orderData[i]["state"]]<<endl;
    }
}

void Student::cancelOrder(){
//    cout<<"û��������ܣ��ٺٺ�"<<endl;
    showMyOrder();
    cout<<"��ȷ���Ƿ�ȡ��ԤԼ��"<<endl;
    cout<<"1.ȷ��"<<endl;
    cout<<"0.��ȷ��"<<endl;
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
    cout<<"�޸ĳɹ�"<<endl;
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