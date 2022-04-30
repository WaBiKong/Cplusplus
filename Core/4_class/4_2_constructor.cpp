// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4.2 constructor.cpp
// Description:  : 构造函数
// Author        : WaBiKong
// CreatDate     : 2022/03/17  星期四
// -------------------------------------------------------------------------------

#include<iostream>
#include<stdio.h>
using namespace std;
// 构造函数分类
// 按照参数分类分为有参和无参构造, 无参又称为默认构造函数
// 按照类型分类分为普通构造和拷贝构造

// 拷贝构造的三种调用情况
// 已经创建的对象初始化新对象
// 函数传参时, 值传递的方式
// 函数返回值为对象时(编译器此处使用返回值优化的技术, 从而不需用调用拷贝构造)
class Person{
    public:
        // 无参(默认)构造
        Person(){
            cout<<"无参构造"<<endl;
        }
        // 有参构造
        Person(int a){
            cout<<"有参构造"<<endl;
            age = a;
        }
        // 拷贝构造
        // const Person &p: 常引用
        Person(const Person &p){
            cout<<"拷贝构造"<<endl;
            name = p.name;
            age = p.age;
        }
        // 析构函数
        ~Person(){}
    private:
        string name;
        int age;
};

void copyPerson(Person p){}
Person retuenPerson(){
    Person p;
    cout<<&p<<endl;
    // 返回的不是栈区的p, 而是将p拷贝到全局区
    // 但编译器使用了一项名为返回值优化的技术，使得调用函数时不需要调用复制构造函数
    return p;  
}

int main(){

    // 三种调用构造方法
    // 括号法
    Person p1_1;  // 默认构造
    Person p1_2(10);  // 有参构造
    Person p1_3(p1_1);  // 拷贝构造
    // 显示法
    Person p2 = Person(10);
    Person p3 = Person(p2);
    // 隐式法
    Person p4 = 10;
    Person p5 = p3;

    // 使用拷贝构造的三种情况
    // 初始化新对象
    Person p6(p2);
    // 函数传参值传递时, 将全局区实参拷贝一份传入栈区函数中
    copyPerson(p6);
    // 值方式返回局部对象
    Person p = retuenPerson();
    cout<<&p<<endl;
    // 此处输出的地址相同
    // 编译器使用了一项名为返回值优化的技术，使得调用函数时不需要调用复制构造函数

    return 0;
}

