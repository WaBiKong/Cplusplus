// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : struct.cpp
// Description:  : 结构体基础：结构体定义，结构体变量(数组)，结果体指针变量
// Author        : WaBiKong
// Date          : 2022/01/21  星期五
// -------------------------------------------------------------------------------

#include<iostream>
#include<string>
using namespace std;

// 定义格式
struct Student{
    string name;
    int age;
    int score;
};
// // 定义格式
// struct Student{
//     string name;
//     int age;
//     int score;
// }wbk1, wbk2;   // 定义结构体时，顺带定义变量

int main(){

    // 定义变量, 也可不赋初值
    // struct可以省略
    struct Student wbk = {"WuBaoKun", 23, 100};  
    cout<<"student'name: "<<wbk.name<<endl;  // 使用 . 运算符访问成员变量

    // 结构体数组定义
    Student students[3] = {
        {"wbk", 23, 100},
        {"msh", 23, 99},
        {"hy", 24, 98}
    };
    cout<<students[1].name<<endl;

    // 结构体指针变量：通过指针指向结构体变量
    Student *p = &wbk;
    cout<<p->name<<endl;  // 使用->符号访问
    cout<<"我是你爹";

    system("pause");
    return 0;
}