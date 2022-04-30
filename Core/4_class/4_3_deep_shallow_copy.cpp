// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4_3_deep_shallow _copy.cpp
// Description:  : 深拷贝与浅拷贝
// Author        : WaBiKong
// CreatDate     : 2022/03/31  星期四
// -------------------------------------------------------------------------------

// 浅拷贝：简单的赋值操作，若申请了堆区内存则在析构函数中会重复delete
// 深拷贝：在堆区重新申请空间，进行拷贝操作
// 编译器提供的拷贝构造为浅拷贝，需要自己编写深拷贝的拷贝构造

#include<iostream>
#include<stdio.h>
using namespace std;

class Person{
    public:
        Person(){}
        Person(int a_age, int a_height){
            age = a_age;
            // 堆区开辟一块空间存放升高
            height = new int();
            *height = a_height;
        }
        Person(const Person &p){
            // 编译器默认实现下两行
            // age = p.age;
            // height = p.height;  // 浅拷贝，只把地址拷贝过去，指向的是堆里的同一空间

            age = p.age;
            // 利用深拷贝解决浅拷贝问题
            // *p.height先解引用，获取堆空间里存放的值，在重新申请堆空间
            height = new int(*p.height);
        }
        ~Person(){
            if(height != NULL){
                cout<<"delete "<<height<<endl;
                delete height;  // 删除堆区开辟的内存空间
                height = NULL;
            }
        }
        int* getheight(){
            return height;
        }

    private:
        int age;
        int * height; // 定义一个指向身高的指针
};

void test(){
    Person p1(18, 170);
    Person p2(p1);
    // 析构时采用先定义后析构的准则
    // 先析构p2,若使用浅拷贝，则把p2指向的堆空间释放了，p1析构时报错
}
int main(){

    test();

    return 0;
}
