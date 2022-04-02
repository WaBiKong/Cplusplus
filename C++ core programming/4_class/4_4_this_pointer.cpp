// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4_4_this_pointer.cpp
// Description:  : this指针
// Author        : WaBiKong
// CreatDate     : 2022/04/02  星期六
// -------------------------------------------------------------------------------

#include<iostream>
#include<stdio.h>
using namespace std;

// this指针指向被调用的成员函数所属的对象
// this指针的用途: 
// 1 当形参和成员变量同名时, 可用this指针来区分
// 2 在类的非静态成员函数中返回对象本身, 可使用return *this
// 3 类中调用成员变量时, 都默认前面省略了 this->
class Person{
    public:
        int age;
        Person(int age){
            // 1 当形参和成员变量同名时, 可用this指针来区分
            this->age = age;
        }
        Person& PersonAddPerson(Person p){
            this->age = p.age;
            // 2 在类的非静态成员函数中返回对象本身, 可使用return *this
            return *this;
        }
};
int main(){

    Person p1(18);
    cout<<p1.age<<endl; // 18

    // 隐式拷贝构造
    Person p2 = p1.PersonAddPerson(p1);
    cout<<p2.age<<endl; // 18

    return 0;
}