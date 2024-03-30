#include"BOSS.h"
using namespace std;

//构造函数
BOSS::BOSS(int ID, string name, int dID) {
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = dID;
}
//显示个人信息
void BOSS ::showlofo() {
	cout << "职工的id为：" << this->m_ID << "\t";
	cout << "职工的姓名为：" << this->m_Name << "\t";
	cout << "职工的岗位为：" << this->getDeptName() << "\t";
	cout << "职工职责：给经理下达任务" << endl;
}
//获取岗位名称
string BOSS :: getDeptName() {
	return string("老板");
}