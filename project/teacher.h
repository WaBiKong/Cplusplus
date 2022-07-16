#pragma once
#include"identity.h"

class Teacher: public Identity{
    public:
        // 构造函数
        Teacher();
        Teacher(int id, string name, string pwd);

        // 菜单界面
        virtual void openMenu();

        void showAllOrder(); // 查看所有预约
        void validationOrder(); // 审核预约

        int tid;
};

Teacher::Teacher(){

}

Teacher::Teacher(int id, string name, string pwd){
    this->tid = id;
    this->name = name;
    this->pwd = pwd;
}

void Teacher::openMenu(){
    cout<<"欢迎教师: "<<this->name<<"登录！"<<endl;
	cout<<"\t\t ----------------------------------\n";
	cout<<"\t\t|                                  |\n";
	cout<<"\t\t|          1.查看所有预约          |\n";
	cout<<"\t\t|                                  |\n";
	cout<<"\t\t|          2.审核预约              |\n";
	cout<<"\t\t|                                  |\n";
	cout<<"\t\t|          0.注销登录              |\n";
	cout<<"\t\t|                                  |\n";
	cout<<"\t\t ----------------------------------\n";
	cout<<"请选择您的操作: "<<endl;
}

void Teacher::showAllOrder(){
	OrderFile of;
	if(of.size == 0){
		cout<<"无预约记录"<<endl;
		system("pause");
		return;
	}
	for(int i = 0; i < of.size; i++){
        cout<<"序号: "<<i+i;
		cout<<"    学号: "<<of.orderData[i]["sid"];
		cout<<"    姓名: "<<of.orderData[i]["name"];
		cout<<"    预约日期: 周"<<of.orderData[i]["date"];
		cout<<"    时段: "<<(of.orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout<<"    机房: "<<of.orderData[i]["roomId"];		
		string status = "    状态: ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if(of.orderData[i]["status"] == "1"){
			status += "审核中";
		}else if(of.orderData[i]["status"] == "2"){
			status += "预约成功";
		}else if(of.orderData[i]["status"] == "-1"){
			status += "审核未通过，预约失败";
		}else{
			status += "预约已取消";
		}
		cout<<status<<endl;
	}
	system("pause");
}

void Teacher::validationOrder(){
    OrderFile of;
	if(of.size == 0){
		cout<<"无预约记录"<<endl;
		system("pause");
		return;
	}
	cout<<"待审核的预约记录如下: "<<endl;

	vector<int> v;
	int index = 0;
	for(int i = 0; i < of.size; i++){
		if(of.orderData[i]["status"] == "1"){
			v.push_back(i);
			cout<<"序号: "<<++index;
			cout<<"    预约日期: 周 "<<of.orderData[i]["date"];
			cout<<"    时段: "<<(of.orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout<<"    机房: "<<of.orderData[i]["roomId"];
			string status = "    状态: ";  // 0取消的预约   1 审核中   2 已预约  -1 预约失败
			if(of.orderData[i]["status"] == "1"){
				status += "审核中";
			}
			cout<<status<<endl;
		}
	}
	cout<<"请输入审核的预约记录序号, 0代表返回"<<endl;
	int select = 0;
	int ret = 0;
	while(true){
		cin>>select;
		if(select >= 0 && select <= v.size()){
			if(select == 0){
				break;
			}
			else{
				cout<<"请输入审核结果"<<endl;
				cout<<"1、通过"<<endl;
				cout<<"2、不通过"<<endl;
				cin>>ret;

				if(ret == 1){
					of.orderData[v[select - 1]]["status"] = "2";
				}else{
					of.orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout<<"审核完毕！"<<endl;
				break;
			}
		}
		cout<<"输入有误，请重新输入"<<endl;
	}
	system("pause");    
}