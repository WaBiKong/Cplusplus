#pragma once
#include<fstream>
#include<vector>
#include<algorithm>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"

class Manager: public Identity{
    public:
        // 构造函数
        Manager();
        Manager(string name, string pwd);

        // 菜单界面
        virtual void openMenu();

        void addPerson(); // 添加账号
        void showPerson(); // 查看账号
        void showComputer(); // 查看机房信息
        void clearFile(); // 清空预约记录

        // 初始化容器
        void initVector();
        bool checkRepat(int id, int type);

        vector<Student> vStu;
        vector<Teacher> vTea;
        vector<ComputerRoom> vCom;
};

Manager::Manager(){

}

Manager::Manager(string name, string pwd){
    this->name = name;
    this->pwd = pwd;

    initVector();

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

void Manager::openMenu(){
	cout<<"欢迎管理员: "<<this->name<<"登录!"<<endl;
	cout<<"\t\t ---------------------------------\n";
	cout<<"\t\t|                                |\n";
	cout<<"\t\t|          1.添加账号            |\n";
	cout<<"\t\t|                                |\n";
	cout<<"\t\t|          2.查看账号            |\n";
	cout<<"\t\t|                                |\n";
	cout<<"\t\t|          3.查看机房            |\n";
	cout<<"\t\t|                                |\n";
	cout<<"\t\t|          4.清空预约            |\n";
	cout<<"\t\t|                                |\n";
	cout<<"\t\t|          0.注销登录            |\n";
	cout<<"\t\t|                                |\n";
	cout<<"\t\t ---------------------------------\n";
	cout<<"请选择您的操作:"<<endl;
}

void Manager::addPerson(){
    cout<<"请输入添加账号的类型:"<<endl;
    cout<<"1、学生"<<endl;
    cout<<"2、老师"<<endl;

    string fileName;
    string tid;
    ofstream ofs;

    int select = 0;
    cin>>select;

    if(select == 1){
		fileName = STUDENT_FILE;
		tid = "请输入学号:";
	}else{
		fileName = TEACHER_FILE;
		tid = "请输入职工编号:";
	}

    ofs.open(fileName, ios::out | ios::app);
    int id;
    string name;
    string pwd;

    cout<<tid<<endl;
    while(true){
        cin>>id;
        if(checkRepat(id, select)){
            cout<<"此号码已存在, 请重新输入:"<<endl;
        }else{
            break;
        }
    }
    cout<<"请输入名字:"<<endl;
    cin>>name;
    cout<<"请输入密码:"<<endl;
    cin>>pwd;

    ofs<<id<<" "<<name<<" "<<pwd<<endl;
    cout<<"添加成功!"<<endl;
    system("pause");

    ofs.close();
    
    initVector(); // 解决新添加的账户没有读取到内存中的问题
}

void printStudent(Student & s){
	cout<<"学号: "<<s.sid<<" 姓名: "<<s.name<<" 密码: "<<s.pwd<<endl;
}
void printTeacher(Teacher & t){
	cout<<"职工号: "<<t.tid<<" 姓名: "<<t.name<<" 密码: "<<t.pwd<<endl;
}

void Manager::showPerson(){
	cout<<"所有学生信息如下: "<<endl;
	for_each(vStu.begin(), vStu.end(), printStudent);

	cout<<"所有老师信息如下: "<<endl;
	for_each(vTea.begin(), vTea.end(), printTeacher);
	system("pause");
}

void Manager::showComputer(){
    for(vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++){
            cout<<"机房编号: "<<it->Comid<<" 机房最大容量: "<<it->MaxNum<<endl;
        }
        system("pause");
}

void Manager::clearFile(){

	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout<<"清空成功！"<<endl;
	system("pause");
}

void Manager::initVector(){
    // 读取文件中已存在的学生或老师的信息
    ifstream ifs;

    vStu.clear();
    vTea.clear();

    ifs.open(STUDENT_FILE, ios::in);
    if(ifs.is_open()){ // 当文件读取成功时
        Student S;
        while(ifs>>S.sid && ifs>>S.name && ifs>>S.pwd)
            vStu.push_back(S);
        cout<<"当前已存在学生数量为:"<<vStu.size()<<endl;
        ifs.close();
    }

    ifs.open(TEACHER_FILE, ios::in);
    if(ifs.is_open()){ // 当文件读取成功时
        Teacher T;
        while(ifs>>T.tid && ifs>>T.name && ifs>>T.pwd)
            vTea.push_back(T);
        cout<<"当前已存在老师数量为:"<<vTea.size()<<endl;
        ifs.close();
    }
}

bool Manager::checkRepat(int id, int type){
	if(type == 1){
		for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++){
			if(id == it->sid){
				return true;
			}
		}
	}else{
		for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
			if(id == it->tid){
				return true;
			}
		}
	}
	return false;
}
