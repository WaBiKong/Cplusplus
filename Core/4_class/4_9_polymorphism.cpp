// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4_9_polymorphism.cpp
// Description:  : 多态
// Author        : WaBiKong
// CreatDate     : 2022/04/26  星期二
// -------------------------------------------------------------------------------

#include<iostream>
using namespace std;
// 多态满足条件:  
// 1、有继承关系
// 2、子类重写父类中的虚函数(父类必须有virtual关键字, 重写除了函数名外参数也得完全相同)
// 多态使用: 
// 父类指针或引用指向子类对象
class Animal{
	public:
		// 函数前面加上virtual关键字变成虚函数, 那么编译器在编译的时候就不函数调用
		// 所以在运行时才进行地址绑定
		virtual void speak(){
			cout<<"动物在说话"<<endl;
		}
};

class Cat:public Animal{
	public:
		void speak(){
			cout<<"小猫在说话"<<endl;
		}
};

class Dog:public Animal{
	public:
		void speak(){
			cout<<"小狗在说话"<<endl;
		}
};

// 父类引用可以接受子类对象
void DoSpeak(Animal &animal){
	animal.speak();
}
int main() {

	// 如果父类中speak()函数不是虚函数，则在编译时就进行了地址绑定
	// 从而此处的输出均为 动物在说话
	Cat cat;
	DoSpeak(cat); // 小猫在说话

	Dog dog;
	DoSpeak(dog); // 小狗在说话

    cout<<"sizeof Animal = "<<sizeof(Animal)<<endl;
    // sizeof Animal = 4  空类大小为1, 但加了virtual后变为4了
    // 4为一个四字节指针(vfptr)的大小 virtual function ptr

	return 0;
}