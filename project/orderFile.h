#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include"globalFile.h"

class OrderFile{
    public:
        OrderFile();
        void updateOrder();

        map<int, map<string, string>> orderData;

        int size; // 预约条数
        
};

OrderFile::OrderFile(){
    ifstream ifs(ORDER_FILE, ios::in);

    string date, interval, sid, name, roomId, status;

    this->size = 0;

    // 每读一行
    while(ifs >> date && ifs >> interval && ifs >> sid && ifs >> name && ifs >> roomId &&  ifs >> status){

		string key;
		string value;
		map<string, string> m;

		int pos = date.find(":");
		if(pos != -1){
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos -1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if(pos != -1){
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos -1 );
			m.insert(make_pair(key, value));
		}

		pos = sid.find(":");
		if(pos != -1){
			key = sid.substr(0, pos);
			value = sid.substr(pos + 1, sid.size() - pos -1 );
			m.insert(make_pair(key, value));
		}

		pos = name.find(":");
		if(pos != -1){
			key = name.substr(0, pos);
			value = name.substr(pos + 1, name.size() - pos -1);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if(pos != -1){
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos -1 );
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if(pos != -1){
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos -1);
			m.insert(make_pair(key, value));
		}


		this->orderData.insert(make_pair(this->size, m));
		this->size++;
	}

	// // 测试代码
	// for(map<int, map<string, string>>::iterator it = orderData.begin(); it != orderData.end(); it++){
	// 	cout<<"key = "<<it->first<<" value = "<<endl;
	// 	for(map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++){
	// 		cout<<mit->first<<" "<<mit->second<<" ";
	// 	}
	// 	cout<<endl;
    // }
    ifs.close();
}

void OrderFile::updateOrder(){
    if(this->size == 0){
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc); // ios::trunc: 若文件存在, 先删除再创建
	for(int i = 0; i < size; i++){
		ofs<<"date:"<<this->orderData[i]["date"]<<" ";
		ofs<<"interval:"<<this->orderData[i]["interval"]<<" ";
		ofs<<"sid:"<<this->orderData[i]["sid"]<<" ";
		ofs<<"name:"<<this->orderData[i]["name"]<<" ";
		ofs<<"roomId:"<<this->orderData[i]["roomId"]<<" ";
		ofs<<"status:"<<this->orderData[i]["status"]<<endl;
	}
    ofs.close();
}
