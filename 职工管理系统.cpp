#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"BOSS.h"
#include"manager.h"
using namespace std;

int main() {
	WorkerManager mu;
	int choose;
	while (1) {
		mu.Show_menu();			//菜单
		cout << "请输入您的选择" << endl;
		cin >> choose;
		switch (choose) {
		case 0:		//退出菜单
			mu.exit();
			break;
		case 1: {		//增加职工信息
			mu.add_Emp();
			mu.quick_clean();
			break;
		}
		case 2: {		//显示职工信息
			mu.contentWorker();
			mu.quick_clean();
			break;
		}
		case 3: {		//删除职工信息
			mu.Del_Emp();
			mu.quick_clean();
			break;
		}
		case 4: {			//修改职工信息
			mu.change_Emp();
			mu.quick_clean();
			break;
		}
		case 5: {		//查找职工信息
			mu.Find_Emp();
			mu.quick_clean();
			break;
		}
		case 6: {	     //按照编号排序
			mu.sort_Emp_id();
			mu.quick_clean();
			break;
		}
		case 7: {		//清空所有文档
			mu.file_clean();
			mu.quick_clean();
			break;
		}
		default:
			mu.err();
			system("pause");
			system("cls");
			break;
		}
		if (choose == 0) {
			break;
		}
	}

	system("pause");
	return 0;
}