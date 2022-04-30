// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4_12_computer.cpp
// Description:  : 多态实现电脑组装案例
// Author        : WaBiKong
// CreatDate     : 2022/04/30  星期六
// -------------------------------------------------------------------------------
// 案例描述
// 电脑主要组成部件为 CPU(用于计算), 显卡(用于显示), 内存条(用于存储)
// 将每个零件封装出抽象基类, 并且提供不同的厂商生产不同的零件, 例如Intel厂商和Amd厂商
// 创建电脑类提供让电脑工作的函数, 并且调用每个零件工作的接口
// 测试时组装三台不同的电脑进行工作
#include<iostream>
using namespace std;

// 抽象CPU类
class CPU{
	public:
		// 抽象的计算函数
		virtual void calculate() = 0;
};

// 抽象显卡类
class VideoCard{
	public:
		// 抽象的显示函数
		virtual void display() = 0;
};

// 抽象内存条类
class Memory{
	public:
		// 抽象的存储函数
		virtual void storage() = 0;
};

// 电脑类
class Computer{
	public:
		Computer(CPU *cpu, VideoCard *vc, Memory *mem){
			m_cpu = cpu;
			m_vc = vc;
			m_mem = mem;
		}

		// 提供工作的函数
		void work(){
			// 让零件工作起来, 调用接口
			m_cpu->calculate();
			m_vc->display();
			m_mem->storage();
		}

		// 提供析构函数 释放3个电脑零件
		~Computer(){
			// 释放CPU零件
			if (m_cpu != NULL){
				delete m_cpu;
				m_cpu = NULL;
			}
			// 释放显卡零件
			if (m_vc != NULL){
				delete m_vc;
				m_vc = NULL;
			}
			// 释放内存条零件
			if (m_mem != NULL){
				delete m_mem;
				m_mem = NULL;
			}
		}

	private:
		CPU *m_cpu; // CPU的零件指针
		VideoCard *m_vc; // 显卡零件指针
		Memory *m_mem; // 内存条零件指针
};

// 具体厂商
// Intel厂商
class IntelCPU: public CPU{
	public:
		virtual void calculate(){
			cout<<"Intel的CPU开始计算了!"<<endl;
		}
};

class IntelVideoCard: public VideoCard{
	public:
		virtual void display(){
			cout<<"Intel的显卡开始显示了!"<<endl;
		}
};

class IntelMemory: public Memory{
	public:
		virtual void storage(){
			cout<<"Intel的内存条开始存储了!"<<endl;
		}
};

// Amd厂商
class AmdCPU: public CPU{
	public:
		virtual void calculate(){
			cout<<"Amd的CPU开始计算了!"<<endl;
		}
};

class AmdVideoCard: public VideoCard{
	public:
		virtual void display(){
			cout<<"Amd的显卡开始显示了!"<<endl;
		}
};

class AmdMemory : public Memory{
	public:
		virtual void storage(){
			cout<<"Amd的内存条开始存储了!"<<endl;
		}
};

int main(){

	cout<<"第一台电脑开始工作: "<<endl;
	// 电脑三个intel零件指针
	CPU *intelCpu = new IntelCPU;
	VideoCard *intelCard = new IntelVideoCard;
	Memory *intelMem = new IntelMemory;
	// 创建第一台电脑
	Computer *computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1; // Computer类的析构函数中将三个零件在堆的地址释放了
	cout<<"-----------------------"<<endl;

	cout<<"第二台电脑开始工作: "<<endl;
	// 第二台电脑组装
	Computer *computer2 = new Computer(new AmdCPU, new AmdVideoCard, new AmdMemory);;
	computer2->work();
	delete computer2;
	cout<<"-----------------------"<<endl;

	cout<<"第三台电脑开始工作: "<<endl;
	// 第三台电脑组装
	Computer *computer3 = new Computer(new AmdCPU, new IntelVideoCard, new AmdMemory);;
	computer3->work();
	delete computer3;

	return 0;

}