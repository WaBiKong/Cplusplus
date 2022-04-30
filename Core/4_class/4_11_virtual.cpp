// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4_11_virtual.cpp
// Description:  : 纯虚函数、虚析构、纯虚析构
// Author        : WaBiKong
// CreatDate     : 2022/04/30  星期六
// -------------------------------------------------------------------------------

#include<iostream>
using namespace std;
// 在多态中, 通常父类中虚函数的实现是毫无意义的, 主要都是调用子类重写的内容
// 因此可以将虚函数改为纯虚函数

// 多态使用时, 因为是用父类指针指向子类对象
// 如果子类中有属性开辟到堆区, 那么父类指针在释放时无法调用到子类的析构代码
// 即无法调用子类虚构, 将引发内存泄漏
// 解决方式: 将父类中的析构函数改为虚析构或者纯虚析构

// 如果是纯虚函数或者纯虚析构, 该类属于抽象类, 无法实例化对象
// 无论虚析构还是纯虚析构都需要进行代码实现
class Animal{
    public:
        Animal(){
            cout<<"Animal 构造函数调用！"<<endl;
        }
        // 纯虚函数
        virtual void Speak() = 0;

        // 析构函数加上virtual关键字, 变成虚析构函数
        // virtual ~Animal(){
        // 	cout<<"Animal虚析构函数调用！"<<endl;
        // }

        // 纯虚析构
        // 只有这一行时报错,需要在类外进行具体函数实现
        // 即无论虚析构还是纯虚析构都需要进行代码实现
        virtual ~Animal() = 0; 
};
Animal::~Animal(){
	cout<<"Animal 纯虚析构函数调用！"<<endl;
}

// 和包含普通纯虚函数的类一样, 包含了纯虚析构函数的类也是一个抽象类, 不能够被实例化
class Cat: public Animal{
	public:
		string *m_Name;
		Cat(string name){
			cout<<"Cat构造函数调用!"<<endl;
			m_Name = new string(name);
		}
		virtual void Speak(){
			cout<<*m_Name<< "小猫在说话!"<<endl;
		}
		~Cat(){
			cout<<"Cat析构函数调用!"<<endl;
			if (this->m_Name != NULL){
				delete m_Name;
				m_Name = NULL;
			}
		}
};

int main(){

	Animal *animal = new Cat("Tom");
	animal->Speak();

	// 通过父类指针去释放, 会导致子类对象可能清理不干净, 造成内存泄漏
	// 怎么解决？给基类增加一个虚析构函数
	// 虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;

	return 0;
}