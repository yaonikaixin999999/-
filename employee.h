#pragma once
//��ͨԱ���ļ�
#include<iostream>
using namespace std;
#include"worker.h"

class Employee :public Worker {
public:
	//���캯��
	Employee(int ID,string name,int dID);
	//��ʾ������Ϣ
	virtual void  showlofo();
	//��ȡ��λ����
	virtual string getDeptName();
};
