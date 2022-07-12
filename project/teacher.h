#pragma once
#include"identity.h"

class Teacher: public Identity{
    public:
        // 构造函数
        Teacher();
        Teacher(int id, string name, string pwd);

        // 菜单界面
        virtual void openMenu();

        void showAllOrder(); // 查看所有预约
        void validationOrder(); // 审核预约

        int tid;
};

Teacher::Teacher(){

}

Teacher::Teacher(int id, string name, string pwd){
    this->tid = id;
    this->name = name;
    this->pwd = pwd;
}

void Teacher::openMenu(){

}

void Teacher::showAllOrder(){

}

void Teacher::validationOrder(){
    
}