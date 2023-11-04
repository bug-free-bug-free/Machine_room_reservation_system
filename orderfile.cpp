#include "orderfile.h"
#include <fstream>
#include <string>
OrderFile::OrderFile() {
    size=0;
    fstream f;
    f.open("order.txt",ios::in);
    string id,value;

    int i=0,cnt=0;
    while(true)
    {
        map<string,string> m;

        while (cnt<6&&f >> id && f >> value) {
            m.insert(make_pair(id, value));
            cnt++;
        }
        if(cnt!=6)break;
        orderData.insert(make_pair(i, m));
        size++;
        cnt=0;
        i++;
    }
    f.close();

    intiVector();
}

void OrderFile::updateOrder() {
    if(size==0)return;

        fstream f("order.txt",ios::out|ios::trunc);;
        for(int i=0;i<size;i++){
            f<<"data"<<' '<<orderData[i]["data"]<<' ';
            f<<"time"<<' '<<orderData[i]["time"]<<' ';
            f<<"id"<<' '<<orderData[i]["id"]<<' ';
            f<<"name"<<' '<<orderData[i]["name"]<<' ';
            f<<"num"<<' '<<orderData[i]["num"]<<' ';
            f<<"state"<<' '<<orderData[i]["state"]<<' '<<endl;
        }
    f.close();
}

void OrderFile::intiVector(){
    vData.insert(make_pair("1","��һ"));
    vData.insert(make_pair("2","�ܶ�"));
    vData.insert(make_pair("3","����"));
    vData.insert(make_pair("4","����"));
    vData.insert(make_pair("5","����"));
    vTime.insert(make_pair("1","����"));
    vTime.insert(make_pair("2","����"));
    vState.insert(make_pair("1","�����"));
    vState.insert(make_pair("2","ԤԼ�ɹ�"));
    vState.insert(make_pair("3","ԤԼʧ��"));
    vState.insert(make_pair("0","ȡ��ԤԼ"));
}