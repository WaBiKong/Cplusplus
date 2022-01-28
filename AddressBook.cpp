// -*- coding: utf-8 -*-
// -------------------------------------------------------------------------------
// name          : AddressBook.cpp
// Description:  : 通讯录管理系统
// Author        : WaBiKong
// CreateDate    : 2022/01/25  星期二
// -------------------------------------------------------------------------------

#include<iostream>
#include<string>
using namespace std;
// 联系人结构体
// 联系人信息包括: 姓名、性别、年龄、联系电话、家庭住址
struct Person{
    string name;
    string sex;
    string age;
    string telephone;
    string address;
};
// 通讯录结构体
// 通讯录包括: 联系人数组、联系人个数
#define MAX 1000
struct Addressbook{
    Person persons[MAX];
    int size;
};

void showMenu();  // 菜单展示
void addPerson(Addressbook *p);  // 添加联系人
void printPersons(Addressbook *p); // 显示联系人
int isExit(Addressbook *p, string name); // 判断联系人是否存在
void findPerson(Addressbook *p); // 查找联系人
void modifyPerson(Addressbook *p); // 修改联系人
void deletePerson(Addressbook *p); // 删除联系人
void cleanPersons(Addressbook *p); // 清空联系人

int main(){
    // 创建并初始化通讯录
    Addressbook abk;
    abk.size = 0;
    
    int num;
    while(true){

        showMenu();
        cin>>num;

        switch(num)
        {
            case 1:  // 添加联系人
                addPerson(&abk);
			    break;
		    case 2:  // 显示联系人
                printPersons(&abk);
			    break;
            case 3:  // 查找联系人
                findPerson(&abk);
                break;
            case 4:  // 修改联系人
                modifyPerson(&abk);
                break;
            case 5:  // 删除联系人
                deletePerson(&abk);
                break;
            case 6:  // 清空联系人
                cleanPersons(&abk);
                break;
            case 0:  // 退出通讯录
                cout<<"即将退出通讯录!"<<endl;
                system("pause");
                return 0;
            default:  // 非法选项
                cout<<"选项不合法, 请重新选择"<<endl;
                break;
        }

    }
    return 0;
}

void showMenu(){
    cout<<"*****************************************"<<endl;
    cout<<"************* 1、添加联系人 *************"<<endl;
    cout<<"************* 2、显示联系人 *************"<<endl;
    cout<<"************* 3、查找联系人 *************"<<endl;
    cout<<"************* 4、修改联系人 *************"<<endl;
    cout<<"************* 5、删除联系人 *************"<<endl;
    cout<<"************* 6、清空联系人 *************"<<endl;
    cout<<"************* 0、退出通讯录 *************"<<endl;
    cout<<"*****************************************"<<endl;
}
// 1、添加联系人 
void addPerson(Addressbook *p){
    if(p->size >= MAX){
        cout<<"通讯录已满，无法添加!"<<endl;
        return;
    }else{
        Person person;
        cout<<"正在添加联系人, 请输入联系人信息:\n";
        cout<<"姓名:"; cin>>person.name;
        cout<<"性别(男、女):"; cin>>person.sex;
        cout<<"年龄:"; cin>>person.age;
        cout<<"联系电话:"; cin>>person.telephone;
        cout<<"家庭住址:"; cin>>person.address;
        p->persons[p->size] = person;
        p->size++;
        cout<<"添加成功!"<<endl;
        system("pause");
    }
}
// 2、显示联系人
void printPersons(Addressbook *p){
    if(p->size == 0){
        cout<<"联系人为空!"<<endl;
    }else{
        for(int i = 0; i < p->size; i++){
            cout<<"姓名:"<<p->persons[i].name<<"\t";
            cout<<"性别(男、女):"<<p->persons[i].sex<<"\t";
            cout<<"年龄:"<<p->persons[i].age<<"\t";
            cout<<"联系电话:"<<p->persons[i].telephone<<"\t";
            cout<<"家庭住址:"<<p->persons[i].address<<endl;
        }
    }
    system("pause");
}
// 判断联系人是否存在, 不存在返回-1, 存在返回下标
int isExit(Addressbook *p, string name){
    for(int i = 0; i < p->size; i++){
        if(p->persons[i].name == name) return i;
    }
    return -1;
}
// 3、查找联系人
void findPerson(Addressbook *p){
    if(p->size == 0){
        cout<<"联系人为空!"<<endl;
        system("pause");
        return;
    }
    string name;
    while(true){
        cout<<"请输入查找的联系人姓名(输入exit退出查找):";
        cin>>name;
        if(name == "exit"){
            cout<<"正在退出查找!"<<endl;
            break;
        }else{
            int i = isExit(p, name);
            if(i == -1){
                cout<<"联系人不存在!"<<endl;
            }else{
                cout<<"姓名:"<<p->persons[i].name<<"\t";
                cout<<"性别(男、女):"<<p->persons[i].sex<<"\t";
                cout<<"年龄:"<<p->persons[i].age<<"\t";
                cout<<"联系电话:"<<p->persons[i].telephone<<"\t";
                cout<<"家庭住址:"<<p->persons[i].address<<endl;
            }
            system("pause");
        }
    }    
    system("pause");
}
// 4、修改联系人
void modifyPerson(Addressbook *p){
    if(p->size == 0){
        cout<<"联系人为空!"<<endl;
        system("pause");
        return;
    }
    string name;
    while(true){
        cout<<"请输入要修改的联系人姓名(输入exit退出修改):";
        cin>>name;
        if(name == "exit"){
            cout<<"正在退出修改!"<<endl;
            break;
        }else{
            int i = isExit(p, name);
            if(i == -1){
                cout<<"联系人不存在!"<<endl;
            }else{
                cout<<"姓名:"<<p->persons[i].name<<"\t";
                cout<<"性别(男、女):"<<p->persons[i].sex<<"\t";
                cout<<"年龄:"<<p->persons[i].age<<"\t";
                cout<<"联系电话:"<<p->persons[i].telephone<<"\t";
                cout<<"家庭住址:"<<p->persons[i].address<<endl;
                cout<<"请输入修改后的信息:"<<endl;
                cout<<"姓名:"; cin>>p->persons[i].name;
                cout<<"性别(男、女):"; cin>>p->persons[i].sex;
                cout<<"年龄:"; cin>>p->persons[i].age;
                cout<<"联系电话:"; cin>>p->persons[i].telephone;
                cout<<"家庭住址:"; cin>>p->persons[i].address;
                cout<<"修改成功!"<<endl;
            }
            system("pause");
        }
    }    
    system("pause");
}
// 5、删除联系人
void deletePerson(Addressbook *p){
    if(p->size == 0){
        cout<<"联系人为空!"<<endl;
        system("pause");
        return;
    }
    string name;
    while(true){
        cout<<"请输入要删除的联系人姓名(输入exit退出删除):";
        cin>>name;
        if(name == "exit"){
            cout<<"正在退出删除!"<<endl;
            break;
        }else{
            int i = isExit(p, name);
            if(i == -1){
                cout<<"联系人不存在!"<<endl;
            }else{
                for(int j = i; j < p->size - 1; j++)
                    p->persons[j] = p->persons[j + 1];
                p->size --;
                cout<<"删除"<<name<<"成功!"<<endl;
            }
            system("pause");
        }
    }    
    system("pause");
}
// 6、清空联系人
void cleanPersons(Addressbook *p){
    p->size = 0;
    cout<<"清空成功!"<<endl;
    system("pause");
}