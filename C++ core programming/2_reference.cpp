// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : reference.cpp
// Description:  : 引用
// Author        : WaBiKong
// CreatDate     : 2022/01/29  星期六
// -------------------------------------------------------------------------------

// 作用: 给变量起别名
// 语法: 数据类型 &别名 = 原名
// 注意: 必须初始化,不可更改引用
// 用途: 1 使用引用进行函数传参 2 做函数返回值,函数调用可作为左值
// 本质: 指针常量,即指针的值不可变(引用不可更改的原因)
// 常量引用: 修饰形参,防止形参改变导致实参改变

#include<iostream>

#include<stdio.h>

using namespace std;

// 交换函数: 引用传参
void swap(int &a, int &b);
// 引用做函数返回值
int &ref();
// 常量引用函数
void showValue(const int &a, int &b);

int main(){

    int a = 10;
    int &b = a;

    cout<<"a = "<<a<<"\tb = "<<b<<endl;  
    // a = 10  b = 10 

    b = 100;
    
    cout<<"a = "<<a<<"\tb = "<<b<<endl;  
    // a = 100 b = 100

    // int &c; // 报错,必须初始化
    int &c = a;
    // 引用初始化后不可更改
    int d = 1000;
    c = d;  // 赋值操作，而不是更改
    cout<<"a = "<<a<<"\tc = "<<c<<endl;

    int x = 1, y = 2;
    swap(x, y);
    cout<<"x = "<<x<<"\ty = "<<y<<endl;
    // x = 2   y = 1
    
    int &reff = ref();
    cout<<"reff = "<<reff<<endl;  // reff = 10
    ref() = 100;  // 如果函数返回值是引用,则函数调用可以作为左值
    cout<<"reff = "<<reff<<endl;  // reff = 100

    // 引用的本质: 指针常量,编译器发现引用将自动转换
    int &ref = a;  // 自动转换为: int * const ref = &a;
    ref = 362425;  // 自动转换为: *ref = 362425;

    // int &ref2 = 10; //报错: 引用本身需要一个合法的内存空间
    // 加const后,编译器自动优化代码为: int temp = 10; int &ref2 = 10;
    const int & ref2  = 10;
    // ref2 = 100; // 报错: 加const后不可修改变量

    int x1 =100, x2 = 100;
    showValue(x1, x2);
    cout<<"x1 = "<<x1<<"\tx2 = "<<x2<<endl;

    return 0;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int &ref(){
    static int a = 10;
    return a;  // 返回静态变量
}

void showValue(const int &a, int &b){
    // a += 10;  // 报错, a 不能修改
    b += 10;
}