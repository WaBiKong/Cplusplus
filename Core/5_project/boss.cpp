#pragma once
#include"boss.h"

Boss::Boss(int id, string name, int dept_id){
    this->Id = id;
    this->name = name;
    this->Dept_Id = dept_id;
}

void Boss::showInfo(){
    cout<<"职工编号: "<<this->Id<<endl;
    cout<<"职工姓名:"<<this->name<<endl;
    cout<<"岗位: "<<getDeptName()<<endl;
}

string Boss::getDeptName(){
    return string("总裁");
}