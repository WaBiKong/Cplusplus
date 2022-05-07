#pragma once
#include<iostream>
#include<string>
using namespace std;

// 职工类
class Worker{
    public:
        // 父类中为纯虚函数
        // 显示个人信息
        virtual void showInfo() = 0;
        // 获取岗位名称
        virtual string getDeptName() = 0;

        int Id;  // 职工编号
        string name;  // 职工姓名
        int Dept_Id;  // 岗位编号
};