#include"manager.h"
using namespace std;

//���캯��
Manager::Manager(int ID, string name, int dID) {
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = dID;
}

//��ʾ������Ϣ
void Manager::showlofo() {
	cout << "ְ����idΪ��" << this->m_ID << "\t";
	cout << "ְ��������Ϊ��" << this->m_Name << "\t";
	cout << "ְ���ĸ�λΪ��" << this->getDeptName() << "\t";
	cout << "��λְ������ϰ彻�������񲢸�Ա���´�����" << endl;
}
//��ȡ��λ����
string Manager::getDeptName() {
	return string("����");
}