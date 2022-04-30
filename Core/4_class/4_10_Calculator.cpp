// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4_10_Calculator.cpp
// Description:  : 多态实现简易计算器
// Author        : WaBiKong
// CreatDate     : 2022/04/26  星期二
// -------------------------------------------------------------------------------

#include<iostream>
using namespace std;
// 抽象计算器类
// 多态优点: 代码组织结构清晰, 可读性强, 利于前期和后期的扩展以及维护
class AbstractCalculator{
	public:
		int m_Num1;
		int m_Num2;
		virtual int getResult(){
			return 0;
		}
};

// 加法计算器
class AddCalculator:public AbstractCalculator{
	public:
		int getResult(){
			return m_Num1 + m_Num2;
		}
};
// 减法计算器
class SubCalculator:public AbstractCalculator{
	public:
		int getResult(){
			return m_Num1 - m_Num2;
		}
};

// 乘法计算器
class MulCalculator:public AbstractCalculator{
	public:
		int getResult(){
			return m_Num1 * m_Num2;
		}
};

int main(){

	// 创建加法计算器
	AbstractCalculator *abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	// cout<<(*abc).m_Num1<<" + "<<abc->m_Num2<<" = "<<abc->getResult()<<endl;
	cout<<abc->m_Num1<<" + "<<abc->m_Num2<<" = "<<abc->getResult()<<endl;
	delete abc;  // 用完了记得销毁

	// 创建减法计算器
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout<<abc->m_Num1<<" - "<<abc->m_Num2<<" = "<<abc->getResult()<<endl;
	delete abc;  

	// 创建乘法计算器
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout<<abc->m_Num1<<" * "<<abc->m_Num2<<" = "<<abc->getResult()<<endl;
	delete abc;

	return 0;
}