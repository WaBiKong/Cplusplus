// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4_7_operator_overloading.cpp
// Description:  : 运算符重载
// Author        : WaBiKong
// CreatDate     : 2022/04/02  星期六
// -------------------------------------------------------------------------------

// 1 通过成员函数运算符重载
// #include<iostream>
// using namespace std;
// class Person{
// 	public:
// 		Person(){};
// 		Person(int a, int b){
// 			A = a;
// 			B = b;
// 		}
// 		// 成员函数实现 + 号运算符重载
// 		Person operator+(const Person& p) {
// 			Person temp;
// 			temp.A = this->A + p.A;
// 			temp.B = this->B + p.B;
// 			return temp;
// 		}
// 		void printPrivate(){
// 			cout<<"A = "<<A<<" B = "<<B<<endl;
//         }
// 	private:
// 		int A;
// 		int B;
// 	};

// int main(){

// 	Person p1(10, 10);
// 	Person p2(20, 20);

// 	// 成员函数方式
// 	Person p3 = p2 + p1;  // 相当于 p2.operaor+(p1)
// 	p3.printPrivate();

// 	return 0;
// }

// 2 通过全局函数运算符重载
#include<iostream>
using namespace std;
class Person{
    friend Person operator+(Person &p1, Person &p2);
    friend Person operator+(Person &p, int val);
    friend ostream& operator<<(ostream &out, Person p);
	
    public:
		Person(int a, int b){
			A = a;
			B = b;
		}
		void printPrivate(){
			cout<<"A = "<<A<<" B = "<<B<<endl;
        }
	private:
		int A;
		int B;
};
// 若使用 const Person &p1, 则无法p1.A
// C++常引用不能访问private权限?
Person operator+(Person &p1, Person &p2){
    Person temp(0, 0);
    temp.A = p1.A + p2.A;
    temp.B = p1.B + p2.B;
    return temp;
}
// 函数重载
Person operator+(Person &p, int val){
    Person temp(0, 0);
    temp.A = p.A + val;
    temp.B = p.B + val;
    return temp;
}
// iostreasm流实现<<重载
ostream& operator<<(ostream &out, Person p){
    out<<"A = "<<p.A<<" B = "<<p.B<<endl;
    return out;
}

int main(){

	Person p1(10, 20), p2(15, 15);
    Person p3 = p1 + p2;
    p3.printPrivate();  // A = 25 B = 35
    Person p4 = p1 + 10;
    p4.printPrivate(); // A = 20 B = 30
    cout<<p4; // A = 20 B = 30

	return 0;
}