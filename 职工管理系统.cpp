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
		mu.Show_menu();			//�˵�
		cout << "����������ѡ��" << endl;
		cin >> choose;
		switch (choose) {
		case 0:		//�˳��˵�
			mu.exit();
			break;
		case 1: {		//����ְ����Ϣ
			mu.add_Emp();
			mu.quick_clean();
			break;
		}
		case 2: {		//��ʾְ����Ϣ
			mu.contentWorker();
			mu.quick_clean();
			break;
		}
		case 3: {		//ɾ��ְ����Ϣ
			mu.Del_Emp();
			mu.quick_clean();
			break;
		}
		case 4: {			//�޸�ְ����Ϣ
			mu.change_Emp();
			mu.quick_clean();
			break;
		}
		case 5: {		//����ְ����Ϣ
			mu.Find_Emp();
			mu.quick_clean();
			break;
		}
		case 6: {	     //���ձ������
			mu.sort_Emp_id();
			mu.quick_clean();
			break;
		}
		case 7: {		//��������ĵ�
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