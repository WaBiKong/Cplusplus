// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : memory.cpp
// Description:  : 内存分区模型
// Author        : WaBiKong
// CreatDate     : 2022/01/29  星期六
// -------------------------------------------------------------------------------

// C++程序在执行时，将内存大方向划分为4个区域
// 代码区: 存放函数体的二进制代码，由操作系统进行管理的
// 全局区: 存放全局变量、静态变量、常量(全局常量、字符常量)
// 栈区: 由编译器自动分配释放,存放函数的参数值,局部变量,局部常量等
// 堆区: 由程序员分配(new)和释放(delete),若程序员不释放,程序结束时由操作系统回收

#include<iostream>
#include<string>
using namespace std;

// 全局变量——全局区
int global_a = 10;
// 全局常量——全局区
const int c_global_a = 10;

// 栈区的数据在函数执行完后自动释放
int *func1(){
    int a = 10; // 局部变量——栈区
    return &a; // 返回局部变量的地址
}
int *func2(){
    int *a = new int(10); // 在堆区分配一个内存，大小为int的大小
    return a; // 返回堆区的地址
}

int main(){

    // 静态变量——全局区
    static int s_a = 10;
    // 局部变量——栈区
    int a = 10;
    // 局部常量——栈区
    const int c_a = 10;


    cout<<"全局变量global_a的地址为:"<<(int)&global_a<<endl;
    cout<<"全局常量c_global_a的地址为:"<<(int)&c_global_a<<endl;
    cout<<"静态变量s_a的地址为:"<<(int)&s_a<<endl;
    cout<<"局部变量a的地址为:"<<(int)&a<<endl;
    cout<<"局部常量c_a的地址为:"<<(int)&c_a<<endl;
    // 字符常量——全局区
    cout<<"字符常量hello world的地址为:"<<(int)&"hello world"<<endl;

    // 定义指针p接受函数返回的地址
    int *p1 = func1();
    cout<<*p1<<endl; // 输出p1指向的内容: 报错或者输出随机数
    int *p2 = func2();
    cout<<*p2<<endl; // 输出p2指向的内容: 10

    // 使用delete释放堆区数据
    delete p2;

    cout<<*p2<<endl; // 报错，释放的空间不可访问

    // 堆区开辟数组
    int *arr = new int[10];
    // 释放数组
    delete[] arr;


    system("pause");
    return 0;
}

// 运行结果如下(存放在全局区的地址相邻，存放在栈区的地址相邻):
// 全局变量global_a的地址为:4214788   
// 全局常量c_global_a的地址为:4218952 
// 静态变量s_a的地址为:4214792        
// 局部变量a的地址为:6422284
// 局部常量c_a的地址为:6422280        
// 局部常量c_b的地址为:6422276        
// 字符常量hello world的地址为:4219121