#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {
public:
	//��ʾ������Ϣ
	virtual void showlofo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	//������Ϣ
	int m_ID;			//���
	string m_Name;		//����
	int m_DeptID;		//���ű��
};