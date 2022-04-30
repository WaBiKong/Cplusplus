// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4_8_inheritance.cpp
// Description:  : 继承
// Author        : WaBiKong
// CreatDate     : 2022/04/26  星期二
// -------------------------------------------------------------------------------

#include<iostream>
using namespace std;
//  类内的三种权限
// * public : 类内类外都可访问
// * protected : 类内可以访问, 类外不可访问
// * private : 类内可以访问, 类外不可访问, 子类无法访问(无法访问并不等于没有继承)
// 继承的三种方式
// * 公共继承: 从父类继承的public属性仍为public, protected属性仍为protected
// * 保护继承: 从父类继承的全部public和protected属性均变为protected属性
// * 私有继承: 从父类继承的全部public和protected属性均变为private属性
class Base{
	public: 
		int m_A;
	protected:
		int m_B;
	private:
		int m_C;
};

// 公共继承
class Son1:public Base{
	public:
		void func(){
			m_A; // 类内可访问 public权限
			m_B; // 类内可访问 protected权限
			// m_C; // 类内不可访问 private权限
		}
};
void myClass(){
	Son1 s1;
	s1.m_A; // 类外只能访问到public权限
}

// 保护继承
class Son2:protected Base{
	public:
		void func(){
			m_A; // 类内可访问 protected权限
			m_B; // 类内可访问 protected权限
			// m_C; // 类内不可访问 private权限
		}
};
void myClass2(){
	Son2 s;
	// s.m_A; // 类外不可访问 protected权限
}

// 私有继承
class Son3:private Base{
	public:
		void func(){
			m_A; // 类内可访问 protected权限
			m_B; // 类内可访问 protected权限
			// m_C; // 类内不可访问 private权限
		}
};
class GrandSon:public Son3{
	public:
		void func(){
			// Son3是私有继承, 所以继承Son3的属性在GrandSon3中都无法访问到
		}
};
int main(){

	// 父类中所有成员属性都会被继承
	cout<<"sizeof Son = "<<sizeof(Son1)<<endl;
	// sizeof Son = 12 (4 * 3(int))

    return 0;
}