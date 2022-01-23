// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : demo.cpp
// Description:  : 结构体案例
// Author        : WaBiKong
// Date          : 2022/01/21  星期天
// -------------------------------------------------------------------------------

#include<iostream>
#include<string>

using namespace std;

struct Student{
    string name;
    float score;
};
struct Teacher{
    string name;
    Student students[5];
};

void initTeachers(Teacher p[]);
void printTeachers(Teacher *p);

int main(){

    Teacher teachers[3];
    Teacher *p = teachers;
    Teacher wbk;
    cout<<sizeof(int)<<endl<<sizeof(float)<<endl<<sizeof(string)<<endl<<sizeof(wbk)<<endl;
    cout<<sizeof(*p)<<endl;
    cout<<sizeof(Teacher)<<endl;
    cout<<sizeof(teachers)<<endl;
    initTeachers(teachers);

    printTeachers(teachers);
    cout<<"nice"<<endl;
    system("pause");
    return 0;
}

void initTeachers(Teacher p[]){
    cout<<"nice"<<endl;
    int len = sizeof(*p) / sizeof(Teacher);
    cout<<sizeof(*p)<<endl<<sizeof(Teacher)<<endl;
    cout<<"nice"<<endl;
    for (int i = 0; i < 1; i++){
        cout<<"请输入第"<<i+1<<"位老师及其学生信息:"<<endl;
        cout<<"老师姓名:";
        cin>>p[i].name;
        cout<<"五位学生姓名及其成绩(姓名 成绩):"<<endl;
        for (int j = 0; j < 1; j++)
            cin>>p[i].students[j].name>>p[i].students[j].score;
    }
    cout<<"初始化结束!";
    cout<<"nice"<<endl;
}

void printTeachers(Teacher *p){
    int len = sizeof(p) / sizeof(Teacher);
    for (int i = 0; i < len; i++){
        cout<<"老师姓名:"<<p[i].name;
        cout<<"    五位学生姓名及其成绩(姓名 成绩):"<<endl;
        for (int j = 0; j < 5; j++)
            cout<<"        "<<p[i].students[j].name<<p[i].students[j].score<<endl;
    }
    cout<<"打印结束!";
}