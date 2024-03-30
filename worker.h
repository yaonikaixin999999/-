#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {
public:
	//显示个人信息
	virtual void showlofo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	//定义信息
	int m_ID;			//编号
	string m_Name;		//姓名
	int m_DeptID;		//部门编号
};