// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4_6_friend.cpp
// Description:  : 友元
// Author        : WaBiKong
// CreatDate     : 2022/04/02  星期六
// -------------------------------------------------------------------------------

#include<iostream>
#include<string>
using namespace std;
// 友元的三种方式
// 1 全局函数做友元, 全局函数的申明和定义随便在什么位置
// 2 类做友元, 类的定义随便在什么位置
// 3 类A中的成员函数做类B友元, 注意: 此处的函数声明必须在类B前面
class GoodGay1{
    public:
        void visit();
    private:
        Building building;
};
class GoodGay2{
    public:
        void visit1();
        void visit2();
    private:
        Building building;
};
class Building{
    // 全局函数做友元, 全局函数的申明和定义随便在什么位置
    friend void goodGay2(Building &building);
    // 类做友元, 类的定义随便在什么位置
    friend class GoodGay1;
    // 类中的成员函数做友元, 注意: 此处的函数声明必须在这个类前面
    friend void GoodGay2::visit2();
    
    public:
        string living_room; // 客厅
        Building();

    private:
        string bedroom; // 卧室
};

Building::Building(){
            living_room = "客厅";
            bedroom = "卧室";
        }

void GoodGay1::visit(){
    cout<<"private权限"<<building.bedroom<<endl;
}

void GoodGay2::visit1(){
    cout<<"public权限"<<building.living_room<<endl;
    // cout<<"private权限"<<building.bedroom<<endl; // 报错: 私有权限不可访问
}
void GoodGay2::visit2(){
    cout<<"public权限"<<building.living_room<<endl;
    cout<<"private权限"<<building.bedroom<<endl;
}

void goodGay1(Building &building){
    cout<<"public权限"<<building.living_room<<endl;
    // cout<<"private权限"<<building.bedroom<<endl; // 报错: 私有权限不可访问
}
void goodGay2(Building &building){
    cout<<"public权限"<<building.living_room<<endl;
    cout<<"private权限"<<building.bedroom<<endl; // 可以访问,类中申明了友元
}

int main(){

    Building b;
    goodGay1(b); // 客厅
    goodGay2(b); // 客厅  卧室

    GoodGay1 gg;
    gg.visit();  // 卧室

    GoodGay2 gg2;
    gg2.visit1();
    gg2.visit2();

    return 0;
}
