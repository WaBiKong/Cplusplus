// 三种身份的基类 (父类)
#pragma once
#include<iostream>
using namespace std;

// 抽象类, 无法实例化对象
class Identity{
    public:
        // 虚函数, 子类必须重写, 否则子类也为抽象类
        virtual void openMenu() = 0;

        string name;
        string pwd;
};