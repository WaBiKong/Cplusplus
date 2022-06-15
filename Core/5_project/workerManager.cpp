#pragma once
#include"workerManager.h"
#include"employee.cpp"
#include"manager.cpp"
#include"boss.cpp"

const int MAX_WORKER = 100;

WorkerManager::WorkerManager(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	// 文件不存在情况, 即文件打开失败
	if(!ifs.is_open()){
		cout<<"员工文件不存在!"<<endl;
		this->workerNum = 0;
		this->fileIsEmpty = true;
		this->workerArray = nullptr;
		ifs.close();
		return;
	}
	// 文件存在, 但为空
	char ch;
	ifs>>ch;  // ifs指针读一个字符
	if(ifs.eof()){  // ifs.eof()判断ifs指向是否为文件结尾
		cout<<"员工文件为空"<<endl;
		this->workerNum = 0;
		this->fileIsEmpty = true;
		this->workerArray = nullptr;
		ifs.close();
		return;
	}
	// 文件存在且有数据
	int num = get_workerNum();
	this->workerNum = num;
	this->fileIsEmpty = false;
	this->workerArray = new Worker*[workerNum];
	init_worker();
}

WorkerManager::~WorkerManager(){
	if(this->workerArray != nullptr)
		delete[] this->workerArray;
}

void WorkerManager::Show_Menu(){
	cout<<"********************************************"<<endl;
	cout<<"*********  欢迎使用职工管理系统！ **********"<<endl;
	cout<<"*************  0.退出管理程序  *************"<<endl;
	cout<<"*************  1.增加职工信息  *************"<<endl;
	cout<<"*************  2.显示职工信息  *************"<<endl;
	cout<<"*************  3.删除离职职工  *************"<<endl;
	cout<<"*************  4.修改职工信息  *************"<<endl;
	cout<<"*************  5.清空所有文档  *************"<<endl;
	cout<<"********************************************"<<endl;
	cout<<endl;
}

void WorkerManager::exitSystem(){
	cout<<"欢迎下次使用"<<endl;
	exit(0);
}

void WorkerManager::add_worker(){
	cout<<"请输入添加员工数量:"<<endl;
	int add_num = 0;
	cin>>add_num;

	if(add_num > 0){
		// 计算新空间
		int newSize = this->workerNum + add_num;

		// 开辟新空间, newSpace中的每一个元素为一个指向worker的指针
		Worker **newSpace = new Worker*[newSize];

		// 将原空间下内容存放到新空间下
		if(this->workerArray != nullptr){
			for(int i = 0; i < this->workerNum; i++){
				newSpace[i] = workerArray[i];
			}
		}

		// 输入新数据
		for(int i = 0; i < add_num; i++){
			int id;
			string name;
			int dept_id;

			cout<<"请输入第"<<i+1<<"个新员工编号:"<<endl;
			cin>>id;
			cout<<"请输入第"<<i+1<<"个新员工姓名:"<<endl;
			cin>>name;

			cout<<"请选择该员工的岗位:"<<endl;
			cout<<"1、普通员工"<<endl;
			cout<<"2、经理"<<endl;
			cout<<"3、老板"<<endl;
			cin>>dept_id;

			// 根据部门创建不同员工
			Worker *worker = nullptr;
			switch(dept_id){
				case 1:
					worker = new Employee(id, name, dept_id);
					break;
				case 2:
					worker = new Manager(id, name, dept_id);
					break;
				case 3:
					worker = new Boss(id, name, dept_id);
					break;
				default:
					break;
			}

			// 添加员工
			newSpace[this->workerNum + i] = worker;
		}

		// 释放原有空间
		delete[] this->workerArray;

		// 更改新空间指向
		this->workerArray = newSpace;

		// 更新数量
		this->workerNum = newSize;

		cout<<"成功添加所有员工!"<<endl;
		// 保存到文件中
		save();
		fileIsEmpty = false;
		system("pause");
	}else{
		cout<<"输入的新员工数量有误!"<<endl;
	}
}

void WorkerManager::save(){
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for(int i = 0; i < this->workerNum; i++){
		ofs<<workerArray[i]->Id<<" "<<workerArray[i]->name<<" "
		   <<workerArray[i]->Dept_Id<<endl;
	}

	ofs.close();
}

int WorkerManager::get_workerNum(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dept_id;

	int num = 0;
	while(ifs>>id && ifs>>name && ifs>>dept_id)
		num++;
	
	ifs.close();

	return num;
}

void WorkerManager::init_worker(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dept_id;

	int index = 0;
	while(ifs>>id && ifs>>name && ifs>>dept_id){
		Worker *worker = nullptr;
		if(dept_id == 1)
			worker = new Employee(id, name, dept_id);
		else if(dept_id == 2)
			worker = new Manager(id, name, dept_id);
		else
			worker = new Boss(id, name, dept_id);
		
		this->workerArray[index] = worker;
		index++;
	}
}

void WorkerManager::show_worker(){
	if(this->fileIsEmpty){
		cout<<"文件不存在或为空!"<<endl;
	}else{
		for(int i = 0; i < workerNum; i++){
			// 利用多态调用接口
			workerArray[i]->showInfo();
			cout<<endl;
		}
	}
	system("pause");
}

void WorkerManager::delete_worker(){
	if(fileIsEmpty)
		cout<<"文件不存在或记录为空!"<<endl;
	else{
		cout<<"请输入要删除的职工号:"<<endl;
		int id;
		cin>>id;

		int index = worker_isExist(id);

		if(index != -1){
			for(int i = index; i < workerNum - 1; i++)
				workerArray[i] = workerArray[i + 1];
			workerNum--;
			save();
			cout<<"删除成功!"<<endl;
		}else{
			cout<<"员工不存在!"<<endl;
		}
	}
	system("pause");
}

int WorkerManager::worker_isExist(int id){
	int index = -1; // 记录员工是否存在

	for(int i = 0; i < workerNum; i++){
		if(workerArray[i]->Id == id){
			index = i;
			break;
		}
	}

	return index;
}

void WorkerManager::modify_worker(){
	if(fileIsEmpty)
		cout<<"文件不存在或记录为空!"<<endl;
	else{
		cout<<"请输入要修改的职工号:"<<endl;
		int id;
		cin>>id;

		int index = worker_isExist(id);

		if(index != -1){
			delete workerArray[index];

			int newId = -1;
			string newName = "";
			int newDept_id = -1;

			cout<<"请输入新的信息:"<<endl;
			cout<<"职工号:";
			cin >> newId;
			cout<<"姓名:";
			cin >> newName;
			cout<<"岗位:"<<endl;
			cout<<"1、普通职工"<<endl;
			cout<<"2、经理"<<endl;
			cout<<"3、老板"<<endl;
			cin>>newDept_id;

			Worker *worker = nullptr;
			switch(newDept_id){
				case 1:
					worker = new Employee(newId, newName, newDept_id);
					break;
				case 2:
					worker = new Manager(newId, newName, newDept_id);
					break;
				case 3:
					worker = new Boss(newId, newName, newDept_id);
					break;
				default:
					break;
			}

			workerArray[index] = worker;

			save();
			cout<<"修改成功!"<<endl;
		}else{
			cout<<"员工不存在!"<<endl;
		}
	}
	system("pause");	
}

void WorkerManager::clean_file(){
	cout<<"确认清空？"<<endl;
	cout<<"1、确认"<<endl;
	cout<<"2、返回"<<endl;

	int select = 0;
	cin>>select;

	if(select == 1){
		//打开模式ios::trunc, 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if(workerArray != nullptr){
			for(int i = 0; i < workerNum; i++)
				if(workerArray[i] != nullptr)
					delete workerArray[i];
			
			workerNum = 0;
			delete[] workerArray;
			workerArray = nullptr;
			fileIsEmpty = true;

		}
		cout<<"清空成功!"<<endl;
	}
	system("pause");
}