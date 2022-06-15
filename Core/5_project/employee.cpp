#include"employee.h"

Employee::Employee(int id, string name, int dept_id){
    this->Id = id;
    this->name = name;
    this->Dept_Id = dept_id;
}

void Employee::showInfo(){
    cout<<"职工编号: "<<this->Id<<endl;
    cout<<"职工姓名:"<<this->name<<endl;
    cout<<"岗位: "<<getDeptName()<<endl;
}

string Employee::getDeptName(){
    return string("员工");
}