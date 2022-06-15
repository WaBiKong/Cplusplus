#pragma once
#include"manager.h"

Manager::Manager(int id, string name, int dept_id){
    this->Id = id;
    this->name = name;
    this->Dept_Id = dept_id;
}

void Manager::showInfo(){
    cout<<"职工编号: "<<this->Id<<endl;
    cout<<"职工姓名:"<<this->name<<endl;
    cout<<"岗位: "<<getDeptName()<<endl;
}

string Manager::getDeptName(){
    return string("经理");
}