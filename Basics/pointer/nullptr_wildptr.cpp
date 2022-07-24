#include<iostream>
using namespace std;
int main(){ // windows下的各种编译器都是默认32位

    // 指针所占内存：
    // 32位操作系统下占4个字节，64位操作系统下占8个字节
    cout<<sizeof(int *)<<endl;  // 4
    cout<<sizeof(char *)<<endl; // 4

    // 空指针和野指针都不是我们申请的空间，因此不要访问
    // 空指针：NULL，指向地址编号0
    // 空指针不可以访问（0~255为系统占用内存，不可访问）
    int * p = NULL;
    cout<<"love you!"<<endl;
    cout<<p<<endl;  // 0
    // *p = 100;  // 不可访问，用法错误
    
    // 野指针：指针变量指向非法内存空间
    // 指针变量p1指向内存地址编号为0x1100的空间
    cout<<"love you!"<<endl;
    int * p1 = (int *)0X1100;
    // cout<<*p1<<endl;  // 访问野指针报错 
    cout<<"执行结束!"<<endl;
    return 0;
}