#pragma once
#include"worker.h"

class Employee:public Worker{
    public:
        Employee(int id, string name, int dept_id);
        virtual void showInfo();
        virtual string getDeptName();
};