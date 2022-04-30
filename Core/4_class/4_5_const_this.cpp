// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4_5_const_this.cpp
// Description:  : 常函数和常对象
// Author        : WaBiKong
// CreatDate     : 2022/04/02  星期六
// -------------------------------------------------------------------------------

#include<iostream>

#include<stdio.h>

using namespace std;
// 常函数:
// 成员函数()后加const后我们称为这个函数为常函数
// 常函数内不可以修改成员属性
// 若成员属性声明时加关键字mutable后, 在常函数中依然可以修改

// 常对象:
// 声明对象前加const称该对象为常对象
// 常对象只能调用常函数
// 常对象不能修改成员变量的值,但是可以访问
// 若成员变量声明时加关键字mutable后,则可以修改成员变量的值
class Person{
	public:
        int A;
		mutable int B; // 可修改可变的
		Person(){
			A = 0;
			B = 0;
		}
		void ShowPerson1(){
			// this指针的本质是一个指针常量(指针的指向不可修改)
			// this = NULL; // 报错:不能修改指针的指向 Person* const this;
			this->A = 100; // 但是this指针指向的值是可以修改的
		}
		// 如果想让指针指向的值也不可以修改
		// 即 const Type* const this; 
        // 所以声明常函数来指代const Type* const this;
		void ShowPerson2() const{
			// const修饰成员函数, 表示指针指向的内存空间的数据不能修改
			// this->A = 100; 报错
            
            // mutable修饰的变量可以修改
            this->B = 100;
		}
};

int main(){

	// 常对象 
	const Person p;  
	cout<<p.A<<endl;  // 10
	// p.A = 100; // 报错: 常对象不能修改成员变量的值,但是可以访问
	p.B = 100; // 常对象可以修改mutable修饰的成员变量的值

	// 常对象只能调用函数
    // 普通函数可以修改成员变量的值,但是常对象不允许修改,所以只能调用修改不了的常函数
    // p.ShowPerson1(); // 报错
    p.ShowPerson2();

	return 0;
}