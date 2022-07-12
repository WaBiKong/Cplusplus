#pragma once
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"globalFile.h"
#include<string>
#include<fstream>

void managerMenu(Identity* &manager);
void studentMenu(Identity * &student);

void Login(string fileName, int type){
    Identity* person = NULL; // 多态: 父类指针指向子类对象

    ifstream ifs(fileName, ios::in);
    if(!ifs.is_open()){
        cout<<"文件不存在!"<<endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if(type == 1){ // 学生登录
        cout<<"请输入学号:"<<endl;
        cin>>id;
    }else if(type == 2){ // 教师登录
        cout<<"请输入职工号:"<<endl;
        cin>>id;
    }

    cout<<"请输入用户名:"<<endl;
    cin>>name;
    cout<<"请输入密码:"<<endl;
    cin>>pwd;

    if(type == 1){ // 学生验证
        int fid;
        string fname, fpwd;
        while(ifs>>fid && ifs>>fname && ifs>>fpwd){
            if(fid == id && fname == name && fpwd == pwd){
                cout<<"学生登录验证成功!"<<endl;
                system("pause");
                person = new Student(id, name, pwd);
                studentMenu(person);
                return;
            }
        }
    }else if(type == 2){ // 教师验证
        int fid;
        string fname, fpwd;
        while(ifs>>fid && ifs>>fname && ifs>>fpwd){
            if(fid == id && fname == name && fpwd == pwd){
                cout<<"教师登录验证成功!"<<endl;
                system("pause");
                person = new Teacher(id, name, pwd);
                return;
            }
        }
    }else if(type == 3){ // 管理员验证
        string fname, fpwd;
        while(ifs>>fname && ifs>>fpwd){
            if(fname == name && fpwd == pwd){
                cout<<"管理员登录验证成功!"<<endl;
                system("pause");
                person = new Manager(name, pwd);
                managerMenu(person);
                return;
            }
        }
    }

    cout<<"登录验证失败!"<<endl;

    system("pause");
    return;
}

void managerMenu(Identity* &manager){
    while(true){
        // 管理员菜单
        manager->openMenu();

        Manager* man = (Manager*) manager; // 强转, 使其能够调用子类函数

        int select = 0;
        cin>>select;

        if(select == 1){
            man->addPerson();
        }else if(select == 2){
            man->showPerson();
        }else if(select == 3){
            man->showComputer();
        }else if(select == 4){
            man->clearFile();
        }else{
            delete manager;
            cout<<"注销成功!"<<endl;
            system("pause");
            return;
        }
    }
}
void studentMenu(Identity * &student){
    while(true){
		//学生菜单
		student->openMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin>>select;

		if(select == 1){ //申请预约
			stu->applyOrder();
		}else if(select == 2){ //查看自身预约
			stu->showMyOrder();
		}else if(select == 3){ //查看所有预约
			stu->showAllOrder();
		}else if(select == 4){ //取消预约
			stu->cancelOrder();
		}else{
			delete student;
			cout<<"注销成功"<<endl;
			system("pause");
			return;
		}
	}    
}