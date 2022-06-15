#pragma once
#include"worker.h"

class Boss:public Worker{
    public:
        Boss(int id, string name, int dept_id);
        virtual void showInfo();
        virtual string getDeptName();
};