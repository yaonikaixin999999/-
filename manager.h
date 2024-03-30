#pragma once
#include<iostream>
#include<ostream>
#include<string>
#include<istream>
using namespace std;
#include"worker.h"

//经理类
class Manager :public Worker {
public:
	//构造函数
	Manager(int ID, string name, int dID);

	//显示个人信息
	virtual void showlofo();
	//获取岗位名称
	virtual string getDeptName();
};
