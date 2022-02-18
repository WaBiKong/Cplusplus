// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : function.cpp
// Description:  : 函数提高: 默认参数、占位参数、函数重载
// Author        : WaBiKong
// CreatDate     : 2022/02/09  星期三
// -------------------------------------------------------------------------------

#include<iostream>

#include<stdio.h>

using namespace std;

// 1、函数默认参数
// 默认参数放在参数最后面
int func1(int a, int b = 20);
// 如果函数申明设置了默认值,则函数定义时不能设置,反之亦是如此
int func1(int a, int b){
    return a + b;
}

// 2、占位参数: 调用函数时必须填补该位置
void func2(int a, int){
    cout<<a<<endl;
}
// 展位参数还可以有默认参数
void func3(int a, int = 100){
    cout<<a<<endl;
}

// 3、函数重载
void func4(){
    cout<<"1"<<endl;
}
// int func4(){  // 报错, 返回值类型不能重载
//     cout<<"1.5"<<endl;
// }
void func4(int a){
    cout<<"2"<<endl;
}
void func4(double a){
    cout<<"2.5"<<endl;
}
void func4(int a, double b){
    cout<<"3"<<"3.5"<<endl;
}
void func4(double a, int b){
    cout<<"3.5"<<"3"<<endl;
}

// 3.1 重载注意事项
// 引用作重载
void func5(int &a){
    cout<<"int &a 调用"<<endl;
}
void func5(const int &a){
    cout<<"const int &a 调用"<<endl;
}

// // 3.2 重载含有默认参数
// // 出现二义性,语法没问题,调用时不知道是哪个
// void func6(int a){
//     cout<<a<<endl;
// }
// void func6(int a, int b = 10){
//     cout<<a<<b<<endl;
// }

int main(){

    cout<<func1(10)<<endl;  // 30

    func2(10, 20);  // 10
    func3(10);  // 10

    func4();  // 1
    func4(2);  // 2
    func4(2.5);  // 2.5
    func4(3.5, 3);  // 3.53
    func4(3, 3.5);  // 33.5

    int num = 10;
    // 引用必须指向合法空间，所以是 int &a = num;
    // 常引用 const int &a = 10;
    func5(num);  // int &a 调用
    func5(10);  // const int &a 调用

    // func6(10);  // 报错

    system("pause");
    return 0;
}