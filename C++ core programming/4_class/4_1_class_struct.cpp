// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : 4.1 class_struct.cpp
// Description:  : class和struct的区别
// Author        : WaBiKong
// CreatDate     : 2022/03/17  星期四
// -------------------------------------------------------------------------------

#include<iostream>

#include<stdio.h>
// struct 默认权限为public
// class 默认权限为private
using namespace std;
class c1{
    int a;  // 默认权限为private
};
struct c2{
    int a; // 默认权限为public
};

int main(){

    c1 m1;
    c2 m2;
    // m1.a = 10;  // 错误, 访问权限为私有
    m2.a = 10;  // 正确, 访问权限为公共

    return 0;
}