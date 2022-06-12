// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : demo1.cpp
// Description:  : vector和deque容器案例
// Author        : WaBiKong
// CreatDate     : 2022/05/17  星期二
// -------------------------------------------------------------------------------
// 案例描述：
// 有5名选手ABCDE, 10个评委分别对每一名选手打分, 去除最高分, 去除评委中最低分, 取平均分
// 实现步骤:
// 1. 创建五名选手,放到vector中
// 2. 遍历vector容器,取出来每一个选手,执行for循环,可以把10个评分打分存到deque容器中
// 3. sort算法对deque容器中分数排序,去除最高和最低分
// 4. deque容器遍历一遍,累加总分
// 5. 获取平均分

#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm> // deque中的排序算法头文件

class Person{
	public:
		Person(string name){
			this->name = name;
			this->average_score = 0;
		}
		void setScores(){
			for(int i = 0; i < 10; i++){
				float score = rand() % 41 + 60;
				scores.push_back(score);
			}

			// 输出每名选手的十个分数
			cout<<this->name<<"的十个分数为: "<<endl;
			for(deque<float>::iterator di = scores.begin(); di != scores.end(); di++){
				cout<<*di<<" ";
			}
			cout<<endl;
		}
		void calculateScores(){
			// 排序
			sort(scores.begin(), scores.end());
			// 去除最高和最低分
			cout<<scores.front()<<" "<<scores.back()<<endl;
			scores.pop_back();
			scores.pop_front();

			float sum = 0;
			for(deque<float>::iterator di = scores.begin(); di != scores.end(); di++)
				sum += *di;
			
			this->average_score = sum / scores.size();
		}
		void printScores(){
			cout<<"name: "<<this->name<<"  average_score: "<<this->average_score<<endl;
		}

	private:
		string name;
		float average_score;
		deque<float> scores;
};

int main(){

	vector<Person> v;

	string names = "ABCED";
	for(int i = 0; i < 5; i++){
		string name = "选手";
		name += names[i];

		Person p(name);

		v.push_back(p);
	}

	for(vector<Person>::iterator vi = v.begin(); vi != v.end(); vi++){
		vi->setScores();
		vi->calculateScores();
		vi->printScores();
	}

	return 0;
}