#pragma once
#include<iostream>
#include<ostream>
#include<string>
#include<istream>
using namespace std;
#include"worker.h"

//������
class Manager :public Worker {
public:
	//���캯��
	Manager(int ID, string name, int dID);

	//��ʾ������Ϣ
	virtual void showlofo();
	//��ȡ��λ����
	virtual string getDeptName();
};
