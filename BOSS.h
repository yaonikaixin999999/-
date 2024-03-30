#pragma once
#include<iostream>
#include<istream>
#include<ostream>
#include<string>
#include"worker.h"
using namespace std;

class BOSS :public Worker {
public:
	//构造函数
	BOSS(int ID,string name,int dID);
	//显示个人信息
	virtual void showlofo();
	//获取岗位名称
	virtual string getDeptName();
};
