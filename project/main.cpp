// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : main.cpp
// Description:  : 机房预约系统
// Author        : WaBiKong
// CreatDate     : 2022/06/18  星期六
// -------------------------------------------------------------------------------

#include<iostream>
using namespace std;
#include"function.cpp"

int main(){

    int select = 0;
	while(true){
		cout<<"======================  欢迎来到传智播客机房预约系统  ====================="<<endl;
		cout<<endl << "请输入您的身份"<<endl;
		cout<<"\t\t -------------------------------\n";
		cout<<"\t\t|                               |\n";
		cout<<"\t\t|          1.学生代表           |\n";
		cout<<"\t\t|                               |\n";
		cout<<"\t\t|          2.老    师           |\n";
		cout<<"\t\t|                               |\n";
		cout<<"\t\t|          3.管 理 员           |\n";
		cout<<"\t\t|                               |\n";
		cout<<"\t\t|          0.退    出           |\n";
		cout<<"\t\t|                               |\n";
		cout<<"\t\t -------------------------------\n";
		cout<<"输入您的选择: ";

		cin>>select; // 接受用户选择

		switch(select){
            case 1:  // 学生身份
				Login(STUDENT_FILE, 1);
                break;
            case 2:  // 老师身份
				Login(TEACHER_FILE, 2);
                break;
            case 3:  // 管理员身份
				Login(MANAGER_FILE, 3);
                break;
            case 0:  // 退出系统
                cout<<"欢迎下次使用, 谢谢!"<<endl;
                return 0;
            default:
                cout<<"输入有误，请重新选择！"<<endl;
                system("pause");
                break;
		}
	}

    return 0;
}