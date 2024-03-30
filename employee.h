#pragma once
//普通员工文件
#include<iostream>
using namespace std;
#include"worker.h"

class Employee :public Worker {
public:
	//构造函数
	Employee(int ID,string name,int dID);
	//显示个人信息
	virtual void  showlofo();
	//获取岗位名称
	virtual string getDeptName();
};
