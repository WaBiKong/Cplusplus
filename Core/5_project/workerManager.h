#pragma once
// #pragma once是一个比较常用的C/C++杂注
// 只要在头文件的最开始加入这条杂注,就能够保证头文件只被编译一次
#include<iostream>
using namespace std;
#include"worker.h"
#include<fstream>
#define FILENAME "workerFile.txt"

class WorkerManager{
    public:
        // 构造函数
        WorkerManager();
        // 菜单展示
        void Show_Menu();
        void exitSystem();
        void add_worker();
        void save();  // 保存员工到文件中
        int get_workerNum(); // 获取文件中的员工数量
        void init_worker(); // 根据文件初始化workerArray
        void show_worker();
        void delete_worker();
        int worker_isExist(int id); // 判断员工是否存在,返回员工的位置
        void modify_worker();
        void clean_file();
        // 析构函数
        ~WorkerManager();

        bool fileIsEmpty; // 标志文件是否为空
        int workerNum;  // 员工数量
        Worker **workerArray;  // 员工数组指针
};