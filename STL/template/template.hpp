// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : template.hpp
// Description:  : 类模板案例--自定义数组
// Author        : WaBiKong
// CreatDate     : 2022/05/12  星期四
// -------------------------------------------------------------------------------
// * 可以对内置数据类型以及自定义数据类型的数据进行存储
// * 将数组中的数据存储到堆区
// * 构造函数中可以传入数组的容量
// * 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
// * 提供尾插法和尾删法对数组中的数据进行增加和删除
// * 可以通过下标的方式访问数组中的元素
// * 可以获取数组中当前元素个数和数组的容量

// 将类模板的定义和实现写在一个文件, 并以.hpp命名

#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray{
    public:
        // 构造函数
        MyArray(int capacity){
            this->capacity = capacity;
            this->size = 0;
            this->pAddress = new T[this->capacity];
        }
        // 拷贝构造
        MyArray(const MyArray& arr){
            // 引用的本质: 指针常量, 即arr是一个指向MyArray对象的指针
            // 编译器发现引用将自动转换
            // arr.capacity自动转换为(*arr).capacity
            this->capacity = arr.capacity;
            this->size = arr.size;
            // 重新申请空间, 防止出现浅拷贝
            this->pAddress = new T[this->capacity];
            for(int i = 0; i < arr.size; i++)
                this->pAddress[i] = arr.pAddress[i];
        }
        // 重载 = 操作符, 防止出现浅拷贝问题
        MyArray& operator=(const MyArray& arr){
            if(this->pAddress != nullptr){
                delete[] this->pAddress;
                this->capacity = 0;
                this->size = 0;
            }

            this->capacity = arr.capacity;
            this->size = arr.size;
            // 重新申请空间, 防止出现浅拷贝
            this->pAddress = new T[this->capacity];
            for(int i = 0; i < arr.size; i++)
                this->pAddress[i] = arr.pAddress[i];

            return *this;
        }
        // 重载 [] 操作符
        T& operator[](int index){
            return this->pAddress[index];
        }
        // 尾插法
        void push_back(const T& val){
            if(this->capacity == this->size)
                return;
            this->pAddress[this->size] = val;
            this->size++;
        }
        // 尾删法
        void pop_back(){
            if(this->size == 0)
                return;
            this->size--;
        }
        // 获取容量
        int getCapacity(){
            return this->capacity;
        }
        // 获取数组大小
        int getSize(){
            return this->size;
        }
        // 析构
        ~MyArray(){
            if(this->pAddress != nullptr){
                delete[] this->pAddress;
                this->pAddress = nullptr; // 置空,防止出现野指针
                this->capacity = 0;
                this->size = 0;
            }
        }
    private:
        T* pAddress; // 指向一个堆空间, 堆空间存储真正数据
        int capacity; // 容量
        int size; //大小
};