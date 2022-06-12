// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : demo2.cpp
// Description:  : list容器排序案例
// Author        : WaBiKong
// CreatDate     : 2022/05/17  星期二
// -------------------------------------------------------------------------------

#include<iostream>
using namespace std;
#include<list>
#include<string>

class Person{
	public:
		Person(string name, int age , int height){
			Name = name;
			Age = age;
			Height = height;
		}

		string Name;  //姓名
		int Age;  //年龄
		int Height;   //身高
};

// 年龄小到大, 身高高到低
bool ComparePerson(Person& p1, Person& p2){
	if(p1.Age == p2.Age){
		return p1.Height  > p2.Height;
	}else{
		return  p1.Age < p2.Age;
	}

}

int main(){

	list<Person> L;

	Person p1("刘备", 35 , 175);
	Person p2("曹操", 45 , 180);
	Person p3("孙权", 40 , 170);
	Person p4("赵云", 25 , 190);
	Person p5("张飞", 35 , 160);
	Person p6("关羽", 35 , 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for(list<Person>::iterator it = L.begin(); it != L.end(); it++){
		cout<<"姓名: "<<it->Name<<" 年龄: "<<it->Age 
     <<" 身高: "<<it->Height<<endl;
	}

	cout<<"---------------------------------"<<endl;
	L.sort(ComparePerson); //排序

	for(list<Person>::iterator it = L.begin(); it != L.end(); it++){
		cout<<"姓名: "<<it->Name<<" 年龄: "<<it->Age 
     <<" 身高: "<<it->Height<<endl;
	}

	return 0;
}