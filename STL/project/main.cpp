// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : main.cpp
// Description:  : 基于STL的演讲比赛流程管理系统
// Author        : WaBiKong
// CreatDate     : 2022/06/14  星期二
// -------------------------------------------------------------------------------

#include<iostream>
using namespace std;
#include"speechManager.h"

int main(){

    SpeechManager sm;
    int choice;

    cout<<"The Speakers participating in the competition are:"<<endl;
    for(map<int, Speaker>::iterator it = sm.Speakers.begin(); it != sm.Speakers.end(); it++)
        cout<<"id:  "<<it->first<<"     name:  "<<it->second.name<<endl;
    system("pause");
    
    while(true){
        sm.show_Menu();
        
        cout<<"please input your choice:"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                sm.startSpeech();
                break;
            case 2:
                sm.showRecord();
                break;
            case 3:
                sm.clearRecord();
                break;
            case 0:
                sm.exit_sys();
                break;
            default:
                break;
        }
    }

    return 0;
}