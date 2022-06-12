#include"template.hpp"
#include<string>

// 测试内置数据类型
void printIntArray(MyArray<int> &arr){
    for(int i = 0; i < arr.getSize(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void test01(){
    MyArray<int> array(10);
    for(int i = 0; i < 10; i++)
        array.push_back(i);
    cout<<"array打印输出:"<<endl;
    printIntArray(array);
	cout<<"array的大小:"<<array.getSize()<<endl;
	cout<<"array的容量:"<<array.getCapacity()<<endl;

    MyArray<int> array_(array);
    array_.pop_back();
    cout<<"array_打印输出:"<<endl;
    printIntArray(array_);
	cout<<"array的大小:"<<array_.getSize()<<endl;
	cout<<"array的容量:"<<array_.getCapacity()<<endl;
}

// 测试自定义数据类型
class Person{
    public:
        Person(){}
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }

        string name;
        int age;
};

void printPersonArray(MyArray<Person>& array){
    for(int i = 0; i < array.getSize(); i++)
        cout<<array[i].name<<" "<<array[i].age<<endl;
}

void test02(){
	//创建数组
	MyArray<Person> pArray(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//插入数据
	pArray.push_back(p1);
	pArray.push_back(p2);
	pArray.push_back(p3);
	pArray.push_back(p4);
	pArray.push_back(p5);

	printPersonArray(pArray);

	cout<<"pArray的大小:"<<pArray.getSize()<<endl;
	cout<<"pArray的容量:"<<pArray.getCapacity()<<endl;

}

int main(){
    test01();
    test02();
    return 0;
}