#pragma once
#include"worker.h"

class Manager:public Worker{
    public:
        Manager(int id, string name, int dept_id);
        virtual void showInfo();
        virtual string getDeptName();
};