#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<algorithm>
#include<numeric>
#include<ctime>
#include<fstream>
using namespace std;

#include"speaker.h"

// 演讲管理类
class SpeechManager{
    public:
        // 构造函数
        SpeechManager();

        void show_Menu();
        void exit_sys();
        void initSpeach(); // 初始化比赛
        void createSpeaker(); // 创建选手
        void startSpeech(); // 开始比赛
        void speechDraw(); // 选手抽签
        void speechContest(); // 比赛
        void showScore(); // 显示比赛结果
        void saveRecord(); // 保存记录
        void loadRecord(); // 读取记录
        void showRecord(); // 展示记录
        void clearRecord(); // 清除记录

        // 析构函数
        ~SpeechManager();

    // private:
        int index;
        vector<int> v1; // 参数赛选手
        vector<int> v2; // 进入淘汰赛选手
        vector<int> victory; // 获胜选手
        map<int, Speaker> Speakers; // 存放选手编号和选手
        bool fileIsEmpty; // 文件为空
        map<int, vector<string>> Record; // 往届记录
};

// 自定义仿函数, 用以输出vector中的元素
class myPrint{
    public:
        void operator()(int val){
            cout<<val<<" ";
        }
};

SpeechManager::SpeechManager(){
    initSpeach();
    createSpeaker();
    loadRecord();
}

SpeechManager::~SpeechManager(){

}

void SpeechManager::show_Menu(){
    cout<<"********************************************"<<endl;
    cout<<"*************  欢迎参加演讲比赛 ************"<<endl;
    cout<<"*************  1.开始演讲比赛  *************"<<endl;
    cout<<"*************  2.查看往届记录  *************"<<endl;
    cout<<"*************  3.清空比赛记录  *************"<<endl;
    cout<<"*************  0.退出比赛程序  *************"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
}

void SpeechManager::exit_sys(){
    cout<<"goodbye!"<<endl;
    exit(0);
}

void SpeechManager::initSpeach(){
    // 初始化容器为空
    this->v1.clear();
    this->v2.clear();
    this->victory.clear();
    this->Speakers.clear();
    // 进入第一轮演讲
    this->index = 1;
    this->Record.clear();
}

void SpeechManager::createSpeaker(){

    string names = "ABCDEFGHIJKL";
    for(int i = 0; i < names.size(); i ++){
        string name = "play";
        name += names[i];

        Speaker sp;
        sp.name = name;
        sp.score[0] = 0;
        sp.score[1] = 0;

        this->v1.push_back(i + 10001); // 插入选手编号
        // 将选手插入map表中
        this->Speakers.insert(make_pair(i + 10001, sp));
    }
}

void SpeechManager::startSpeech(){
    // 第一轮比赛
    // 1、抽签
    speechDraw();
    // 2、比赛
    speechContest();
    // 3、显示晋级结果
    showScore();
    // 第二轮比赛
    // 1、抽签
    index++;
    speechDraw();
    // 2、比赛
    speechContest();
    // 3、显示最终结果
    showScore();
    // 4、保存分数
    saveRecord();

    // 为下一次比赛初始化
    initSpeach();
    createSpeaker();
    loadRecord();

    cout<<"The competition has come to an end!"<<endl;
    system("pause");
}

void SpeechManager::speechDraw(){
    // 选手抽签: 编号顺序打乱即可
    cout<<"------------------------- This is round "<<index<<" -------------------------"<<endl;
    cout<<"The order of speakers is as follows:"<<endl;

    srand((unsigned int)time(NULL)); // 随机数种子

    if(this->index == 1){
        random_shuffle(v1.begin(), v1.end());
        for_each(v1.begin(), v1.end(), myPrint());
        cout<<endl;
    }else{
        random_shuffle(v2.begin(), v2.end());
        for_each(v2.begin(), v2.end(), myPrint());
        cout<<endl;
    }
}

void SpeechManager::speechContest(){
    cout<<"---------- The "<<index<<"-th round begins! ----------"<<endl;

    // 临时容器, 记录每个小组, key:分数 value:选手编号, 按编号从大到小
    multimap<double, int, greater<int>> groupScore;

    int num = 0; // 记录人员数, 6个为一组
    vector<int> Src; // 比赛人员的容器
    if(index == 1)
        Src = v1;
    else
        Src = v2;
    
    // 遍历比赛选手
    for(vector<int>::iterator it = Src.begin(); it != Src.end(); it++){
        num++;
        // 评委打分
        deque<double> d;
        for(int i = 0; i < 10; i++){
            double score = (rand() % 401 + 600) / 10.f; // 60~100
            d.push_back(score);
        }
        // 从大到小排序
        sort(d.begin(), d.end(), greater<double>());
        d.pop_front(); // 去掉最大值
        d.pop_back(); // 去掉最小值
        // 获取总分
        double sum = accumulate(d.begin(), d.end(), 0.f);
        // 获取平均分
        double average = sum / (double)d.size();
        // 记录分数
        this->Speakers[*it].score[index - 1] = average;

        groupScore.insert(make_pair(average, *it));
        if(num % 6 == 0){
            cout<<"Group "<<num / 6<<" results:"<<endl;
            for(multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++){
                cout<<"id: "<<it->second<<"    name: "<<Speakers[it->second].name<<"    score"<<it->first<<endl;
            }

            int count = 0;
            // 取前三名
            for(multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++){
                if(index == 1){
                    v2.push_back(it->second);
                }else{
                    victory.push_back(it->second);
                }
            }

            // 清楚前一组的数据
            groupScore.clear();
            cout<<endl;
        }
    }
    cout<<"The "<<index<<"-th match ends!"<<endl;
    system("pause");
}

void SpeechManager::showScore(){
    vector<int> v;
    if(index == 1){
        v = v2;
        cout<<"The qualifiers for the round 1 are as follows:"<<endl;
    }else{
        v = victory;
        cout<<"The winners are as follows:"<<endl;
    }

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout<<"id: "<<*it<<"    name: "<<Speakers[*it].name<<"    score: "<<Speakers[*it].score[index - 1]<<endl;
    cout<<endl;

    system("pause");
    
}

void SpeechManager::saveRecord(){
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); // 为写文件而打开, 用追加写
    
    // 将每个数据写入文件中
    for(vector<int>::iterator it = victory.begin(); it != victory.end(); it++){
        ofs<<*it<<","<<Speakers[*it].name<<","<<Speakers[*it].score[1]<<","<<endl;
    }
    ofs<<endl;

    ofs.close();

    cout<<"record uploaded!"<<endl;

    this->fileIsEmpty = false;
}

void SpeechManager::loadRecord(){
    ifstream ifs;
    ifs.open("speech.csv", ios::in); // 为了读文件而打开文件

    if(!ifs.is_open()){ // 文件不存在, 打不开
        this->fileIsEmpty = true;
        cout<<"file does not exist!"<<endl;
        ifs.close();
        return;
    }

    char ch;
    ifs>>ch;
    if(ifs.eof()){ // 文件打开, 但为空
        cout<<"file is empty!"<<endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    // 文件不为空时
    this->fileIsEmpty = false;
    ifs.putback(ch); // 把刚读取的单个字符放回

    string data;
    int ind = 0;
    while(ifs>>data){ // 读取每一行进string
        vector<string> v;
        int pos = -1, start = 0;

        while(true){
            pos = data.find(",", start); // 从0开始查找 ','

            if(pos == -1) break; // 找不到就break

            // 找到了则获取第一个字串, 即第一个参数
            string tmp = data.substr(start, pos - start);

            v.push_back(tmp);
            start = pos + 1;
        }

        this->Record.insert(make_pair(ind, v));
        ind++;
    }

    ifs.close();
}

void SpeechManager::showRecord(){
    
    if(this->fileIsEmpty)
        cout<<"file is empty!"<<endl;
    else{
        cout<<"The results of previous competitions are as follows:"<<endl;
        for(int i = 0; i < Record.size(); i+=3){
            cout<<"             id       name     score"<<endl;
            cout<<"   champion: "<<this->Record[i][0]<<"    "<<this->Record[i][1]<<"    "<<this->Record[i][2]<<endl;
            cout<<"  runner up: "<<this->Record[i+1][0]<<"    "<<this->Record[i+1][1]<<"    "<<this->Record[i+1][2]<<endl;
            cout<<"third place: "<<this->Record[i+2][0]<<"    "<<this->Record[i+2][1]<<"    "<<this->Record[i+2][2]<<endl;
        }
    }
    system("pause");
    system("cls");
}

void SpeechManager::clearRecord(){
    cout<<"Whether to clear?"<<endl;
    cout<<"1、Yes"<<endl;
    cout<<"2、No"<<endl;
 
    int select = 0;
    cin>>select;

    if(select == 1){
        ofstream ofs;
        // 打开模式 ios::trunc 如果存在, 则删除文件并重新创建
        ofs.open("speech.csv", ios::trunc);
        ofs.close();

        // 为下一次比赛初始化
        initSpeach();
        createSpeaker();
        loadRecord();

        cout<<"Cleared successfully!"<<endl;
    }
    system("pause");
    system("cls");
}
