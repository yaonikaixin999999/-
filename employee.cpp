#include"employee.h"
using namespace std;

//���캯��
Employee::Employee(int ID,string name,int dID) {
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = dID;
}
//��ʾ������Ϣ
void Employee::showlofo() {
	cout << "ְ����idΪ��" << this->m_ID<<"\t";
	cout << "ְ��������Ϊ��" << this->m_Name<<"\t";
	cout << "ְ���ĸ�λΪ��" << this->getDeptName() << "\t";
	cout << "ְ��ְ����ɾ�����������" << endl;
}
//��ȡ��λ���� 
string Employee::getDeptName() {
	return string("Ա��");
}