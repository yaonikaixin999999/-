#pragma once
#include<iostream>
#include<istream>
#include<ostream>
#include<string>
#include"worker.h"
using namespace std;

class BOSS :public Worker {
public:
	//���캯��
	BOSS(int ID,string name,int dID);
	//��ʾ������Ϣ
	virtual void showlofo();
	//��ȡ��λ����
	virtual string getDeptName();
};
