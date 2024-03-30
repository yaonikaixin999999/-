#pragma once		//防止头文件重复包含
#include<iostream>
#include<string>
#include<ostream>
#include<fstream>
#include"worker.h"
using namespace std;
#include"employee.h"
#include"manager.h"
#include"BOSS.h"
#define FILENAME "D:\\vs text\\project_职工管理系统\\project_职工管理系统\\职工信息.txt"

//class Worker {		//职工
//public:
//	Worker() {
//		e_Num = 00000;
//		e_Name = "Join";
//		e_age = 21;
//	}
//	int e_Num;		//编号
//	string e_Name;		//姓名
//	int e_age;
//};

class WorkerManager {
public:
	//构造函数
	WorkerManager();

	//输入错误
	void err();

	//显示员工信息
	void contentWorker();

	//增加员工信息（修正）
	void add_Emp();

	//增加员工信息
	void addWorker();

	//删除职工信息
	void Del_Emp();

	//查找职工是否存在
	int Search_Emp(int ID);

	//修改员工信息
	void change_Emp();

	//查询员工信息
	void Find_Emp();

	//排序职工编号
	void sort_Emp_id();

	//展示菜单
	void Show_menu();

	//退出管理系统
	void exit();

	//文件清空
	void file_clean();

	//职工信息保存在文件中
	void file_save();

	//统计文件中人数个数
	int file_Empnum();

	//记录职工人数
	int m_Empnum;

	//判断文件是否为空  标志
	bool m_FileIsEmpty;

	//初始化员工
	void start_Emp();

	//按任意键退出并且清屏
	void quick_clean();

	//职工数组指针
	Worker** m_EmpArray;	

	//析构函数
	~WorkerManager();

};