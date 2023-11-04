#include <iostream>
#include "teacher.h"
#include "orderfile.h"
Teacher::Teacher() {

}

Teacher::Teacher(int empId, string name, int password)
{

}

void Teacher::openMenu() {
    cout<<"-----��ӭ��ʦ"<<name<<"��¼-----"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"|\t1.�鿴����ԤԼ\t|"<<endl;
    cout<<"|\t2.���ԤԼ\t|"<<endl;
    cout<<"|\t0.ע����¼\t|"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"��ѡ����Ĳ�����"<<endl;
}

void Teacher::showOrder() {
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

void Teacher::validOrder() {
    OrderFile f;
    while(true){
        showOrder();
        cout<<"��ѡ��Ҫ�޸ĵļ�¼������0���˳��޸�ģʽ��"<<endl;
        int select;
        cin>>select;
        if(!select)break;
        cout<<"��ѡ���޸ĵ�ģʽ"<<endl;
        cout<<"1.ͨ��"<<endl;
        cout<<"0.��ͨ��"<<endl;
        int choice;
        cin>>choice;
        auto p=f.orderData[select-1].find("state");
        if(p!=f.orderData[select-1].end()){
            if(choice==1)p->second="2";
            else p->second="3";
        }
        f.updateOrder();
        cout<<"�޸ĳɹ�"<<endl;
    }

}