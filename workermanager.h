#pragma once		//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
#include<ostream>
#include<fstream>
#include"worker.h"
using namespace std;
#include"employee.h"
#include"manager.h"
#include"BOSS.h"
#define FILENAME "D:\\vs text\\project_ְ������ϵͳ\\project_ְ������ϵͳ\\ְ����Ϣ.txt"

//class Worker {		//ְ��
//public:
//	Worker() {
//		e_Num = 00000;
//		e_Name = "Join";
//		e_age = 21;
//	}
//	int e_Num;		//���
//	string e_Name;		//����
//	int e_age;
//};

class WorkerManager {
public:
	//���캯��
	WorkerManager();

	//�������
	void err();

	//��ʾԱ����Ϣ
	void contentWorker();

	//����Ա����Ϣ��������
	void add_Emp();

	//����Ա����Ϣ
	void addWorker();

	//ɾ��ְ����Ϣ
	void Del_Emp();

	//����ְ���Ƿ����
	int Search_Emp(int ID);

	//�޸�Ա����Ϣ
	void change_Emp();

	//��ѯԱ����Ϣ
	void Find_Emp();

	//����ְ�����
	void sort_Emp_id();

	//չʾ�˵�
	void Show_menu();

	//�˳�����ϵͳ
	void exit();

	//�ļ����
	void file_clean();

	//ְ����Ϣ�������ļ���
	void file_save();

	//ͳ���ļ�����������
	int file_Empnum();

	//��¼ְ������
	int m_Empnum;

	//�ж��ļ��Ƿ�Ϊ��  ��־
	bool m_FileIsEmpty;

	//��ʼ��Ա��
	void start_Emp();

	//��������˳���������
	void quick_clean();

	//ְ������ָ��
	Worker** m_EmpArray;	

	//��������
	~WorkerManager();

};