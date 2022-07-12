#pragma once
#include<fstream>
#include<vector>
#include<algorithm>
#include"globalFile.h"
#include"identity.h"
#include"computerRoom.h"

class Student: public Identity{
    public:
        // 构造函数
        Student();
        Student(int id, string name, string pwd);

        // 菜单界面
        virtual void openMenu();

        void applyOrder(); // 申请预约
        void showMyOrder(); // 查看我的预约
        void showAllOrder(); // 查看所有预约
        void cancelOrder(); // 取消预约

        int sid;
        vector<ComputerRoom> vCom;
};

Student::Student(){

}

Student::Student(int id, string name, string pwd){
    this->sid = id;
    this->name = name;
    this->pwd = pwd;

	//获取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while(ifs>>c.Comid && ifs>>c.MaxNum){
		vCom.push_back(c);
	}
	cout<<"当前机房数量为: "<<vCom.size()<<endl;
	ifs.close();
}

void Student::openMenu(){
	cout<<"欢迎学生代表: "<<this->name<<"登录!"<<endl;
	cout<<"\t\t ----------------------------------\n";
	cout<<"\t\t|                                 |\n";
	cout<<"\t\t|          1.申请预约              |\n";
	cout<<"\t\t|                                 |\n";
	cout<<"\t\t|          2.查看我的预约          |\n";
	cout<<"\t\t|                                 |\n";
	cout<<"\t\t|          3.查看所有预约          |\n";
	cout<<"\t\t|                                 |\n";
	cout<<"\t\t|          4.取消预约              |\n";
	cout<<"\t\t|                                 |\n";
	cout<<"\t\t|          0.注销登录              |\n";
	cout<<"\t\t|                                 |\n";
	cout<<"\t\t ----------------------------------\n";
	cout<<"请选择您的操作:"<<endl;
}

void Student::applyOrder(){
	cout<<"机房开放时间为周一至周五！"<<endl;
	cout<<"请输入申请预约的时间: "<<endl;
	cout<<"1、周一"<<endl;
	cout<<"2、周二"<<endl;
	cout<<"3、周三"<<endl;
	cout<<"4、周四"<<endl;
	cout<<"5、周五"<<endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while(true){
		cin>>date;
		if(date >= 1 && date <= 5){
			break;
		}
		cout<<"输入有误, 请重新输入"<<endl;
	}

	cout<<"请输入申请预约的时间段: "<<endl;
	cout<<"1、上午"<<endl;
	cout<<"2、下午"<<endl;

	while (true){
		cin>>interval;
		if(interval >= 1 && interval <= 2){
			break;
		}
		cout<<"输入有误, 请重新输入"<<endl;
	}

	cout<<"请选择机房: "<<endl;
	cout<<"1号机房容量: "<<vCom[0].MaxNum<<endl;
	cout<<"2号机房容量: "<<vCom[1].MaxNum<<endl;
	cout<<"3号机房容量: "<<vCom[2].MaxNum<<endl;

	while(true){
		cin>>room;
		if(room >= 1 && room <= 3){
			break;
		}
		cout<<"输入有误, 请重新输入"<<endl;
	}

	cout<<"预约成功! 审核中"<<endl;

	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	ofs<<"date:"<<date<<" ";
	ofs<<"interval:"<<interval<<" ";
	ofs<<"stuId:"<<this->sid<<" ";
	ofs<<"stuName:"<<this->name<<" ";
	ofs<<"roomId:"<<room<<" ";
	ofs<<"status:"<<1<<endl;

	ofs.close();

	system("pause");
}

void Student::showMyOrder(){

}

void Student::showAllOrder(){

}

void Student::cancelOrder(){

}