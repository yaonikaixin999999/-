#include"workerManager.h"
using namespace std;

//��ʼ��
WorkerManager::WorkerManager() {
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		//cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_Empnum = 0;
		//��ʼ������ָ��Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	};

	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�����Ϊ��" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_Empnum = 0;
		//��ʼ������ָ��Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ����ݴ��ڣ����Ҽ�¼��������
	int num = this->file_Empnum();
	//cout << "��ǰ��¼��ְ������Ϊ��" << num << "��" << endl;
	this->m_Empnum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_Empnum];
	//���ļ��е����ݣ��浽������
	this->start_Emp();

	//���Դ���
	/*for (int i = 0; i < this->m_Empnum; i++) {
		cout << "ְ�����Ϊ��" << this->m_EmpArray[i]->m_ID
			 << " ְ������Ϊ��" << this->m_EmpArray[i]->m_Name
			 << " ְ��ְλΪ��" << this->m_EmpArray[i]->m_DeptID << endl;
	}*/
	ifs.close();
};

//��ʼ��Ա��
void WorkerManager::start_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dID;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dID) {
		Worker* worker = NULL;

		//��ְͨ��
		if (dID == 1) {
			worker = new Employee(id, name, dID);
		}
		//����
		else if (dID == 2) {
			worker = new Manager(id, name, dID);
		}
		//�ϰ�
		else if (dID == 3) {
			worker = new BOSS(id,name, dID);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//ͳ���ļ�����������
int WorkerManager::file_Empnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dID;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dID) {
		//ͳ����������
		num++;
	}
	ifs.close(); 
	return num;
}

//�������
void WorkerManager::err() {
	cout << "�����������������" << endl;
};

//��������˳���������
void WorkerManager::quick_clean() {
	system("pause");
	system("cls");
}

//��ʾְ����Ϣ		
void WorkerManager::contentWorker() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < this->m_Empnum; i++) {
			this->m_EmpArray[i]->showlofo();
		}

		//ifstream ifs;
		//ifs.open("ְ����Ϣ.txt", ios::in);
		//char temp[1024] = { 0 };
		//if (temp[0] != NULL) {
		//	while (ifs.getline(temp, sizeof(temp))) {
		//		cout << "ְ�����" << temp << endl;
		//	}
		//}
		//else {
		//	cout << "��ǰ����Ա����Ϣ" << endl;
		//}
		//ifs.close();
		//system("pause");
	}
}

//����ְ����Ϣ
void WorkerManager::file_save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_Empnum; i++) {
		ofs << this->m_EmpArray[i]->m_ID << " ";
		ofs << this->m_EmpArray[i]->m_Name << " ";
		ofs << this->m_EmpArray[i]->m_DeptID << endl;
	}	
	ofs.close();
}

//���ְ����ָ����
void WorkerManager::add_Emp() {
	cout << "��������Ҫ���ְ��������:" << endl;
	int addNum = 0;		//��ӵ�����
	FLAG:
	cin >> addNum;
	if (addNum > 0) {
		//�����µĿռ��С
		int newSize = this->m_Empnum + addNum;		//�¿ռ�����
		//�����¿ռ�
		Worker** newspace = new Worker * [newSize];
		//��ԭ���ռ��µ����ݿ������¿ռ�
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_Empnum; i++) {
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//���������������������µ�����
		for (int i = 0; i < addNum; i++) {
			int id;		//ְ�����
			string name;		//ְ������
			int dID;		//���ű��

			cout << "������ص�" << i + 1 << "����ְ����ְ�����" << endl;
			cin >> id;
			cout << "������ص�" << i + 1 << "����ְ����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���" << i + 1 << "����ְ���ĸ�λ" << endl;
			cout << "1.��ͨԱ��	2.����	3.�ϰ�" << endl;
			
			Worker* worker = NULL;
			FLAG1:
			cin >> dID;
			switch (dID) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new BOSS(id, name, 3);
				break;
			default:
				this->err();
				goto FLAG1;
				break;
			}
				//if (dID == 1 && dID == 2 && dID == 3) {
				//	break;
				//}

			//������ְ��ְ�𣬱��浽������
			newspace[this->m_Empnum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
			
		//�����¿ռ��ָ��
		this->m_EmpArray = newspace;

		//�����µ�ְ������
		this->m_Empnum = newSize;

		//�����ļ�״̬���ļ����ݲ�Ϊ�յı�־
		this->m_FileIsEmpty = false;

		this->file_save();	
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
	}
	else {
		this->err();
		goto FLAG;
	}
}

//����ְ����Ϣ
void WorkerManager::addWorker() {
	ofstream ofs;
	ofs.open("ְ����Ϣ.txt", ios::app);
	cout << "��������Ҫ��ӵ�ְ������" << endl;
	int num, temp;		//Ա������
	cin >> num;
	for (int i = 0; i < num; i++) {
		string strnum, strname;
		cout << "�������" << i + 1 << "����ְ�����" << endl;
		cin >> strnum;
		ofs << strnum << "  ";
		cout << "�������" << i + 1 << "����ְ������" << endl;
		cin >> strname;
		ofs << strname << "  ";
		cout << "��ѡ���ְ���ĸ�λ" << endl;
		cout << "1.��ְͨ��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		cin >> temp;
		//while (1) {
		//	switch (temp) {
		//	case 1:
		//		ofs << "��ͨԱ��" << endl;
		//		break;
		//	case 2:
		//		ofs << "����" << endl;
		//		break;
		//	case 3:
		//		ofs << "�ϰ�" << endl;
		//		break;
		//	default:
		//		cout << "�����������������" << endl;
		//		break;
		//	}
		//	if (temp == 1 && temp == 2 && temp == 3) {
		//		break;
		//	}
		//}
		system("cls");
	}
	cout << "�ɹ����" << num << "����ְ��" << endl;
	ofs.close();
	system("pause");
}

//����Ա���Ƿ����
int WorkerManager::Search_Emp(int ID) {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int dID;
	int location_Emp = 0;

	//����ҵ���Ա���򷵻ظ�Ա����λ��
	while (ifs >> id && ifs >> name && ifs >> dID) {
		location_Emp++;
		if (ID == id) {
			return location_Emp;
			break;
		}
	}

	//û���ҵ���Ա��
	return -1;
}

//ɾ��ְ����Ϣ
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ�������Ϊ��" << endl;
	}
	else {
		cout << "����������Ҫɾ��ְ���ı��" << endl;
		int temp;
		int ID;		//���
		cin >> ID;
		int index = this->Search_Emp(ID);
		if (index == -1) {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
		else {
			cout << "ȷ��ɾ����ְ����?" << endl;
			cout << "1.ȷ�� 2.ȡ��" << endl;
			while (1) {
				cin >> temp;
				if (temp != 1 && temp != 2) {
					this->err();
				}
				else {
					if (temp == 1) {
						for (int i = index - 1; i < this->m_Empnum; i++) {
							//����ǰ��
							this->m_EmpArray[i] = this->m_EmpArray[i + 1];
						}
						//���¼�¼ְ������
						m_Empnum--;

						//����ͬ���������ļ���
						this->file_save();

						cout << "ְ��ɾ���ɹ�" << endl;
					}else if(temp==2){
						cout << "��ȡ��ɾ��" << endl;
					}
					break;
				}
			}
		}
	}
}

//�޸�Ա����Ϣ
void WorkerManager::change_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ�����Ϊ��" << endl;
	}
	else {
		cout << "����������Ҫ�޸�ְ����Ϣ��ְ�����" << endl;
		int ID;
		cin >> ID;
		int index = this->Search_Emp(ID);
		if (index == -1) {
			cout << "�޸�ʧ�ܣ�δ�ҵ�����ϵ��" << endl;
		}
		else {
			string temp_name;
			int temp_dID;
			int temp;
			cout << "�������Ա���޸ĺ������" << endl;
			cin >> temp_name;
			cout << "�������Ա���޸ĺ��ְλ" << endl;
			cout << "1.��ͨԱ�� 2.���� 3.�ϰ�" << endl;
			while (1) {
				cin >> temp_dID;
				if (temp_dID != 1 && temp_dID != 2 && temp_dID != 3) {
					cout << "�����������������" << endl;
				}
				else {  
					break;
				}
			}

			cout << "ȷ���޸���" << endl;
			cout << "1.ȷ�� 2.ȡ��" << endl;
			while (1) {
				cin >> temp;
				if (temp != 1 && temp != 2) {
					cout << "�����������������" << endl;
				}
				else {
					if (temp == 1) {
						delete this->m_EmpArray[index - 1];
						Worker* worker = NULL; 
						switch (temp_dID) {
						case 1:
							worker = new Employee(ID, temp_name, temp_dID);
							break;
						case 2:
							worker = new Manager(ID, temp_name, temp_dID);
							break;
						case 3:
							worker = new BOSS(ID, temp_name, temp_dID);
							break;
						default: 
							break;
						}  
						this->m_EmpArray[index - 1] = worker;

						//(�ҵĲ��룬����֪bug)
						//this->m_EmpArray[index - 1]->m_Name = temp_name;
						//this->m_EmpArray[index - 1]->m_DeptID = temp_dID;

						this->file_save();
						cout << "ְ����Ϣ�޸ĳɹ�" << endl;
					}
					else if (temp == 2) {
						cout << "��ȡ���޸�" << endl;
					}
					break;
				}
			}
		}
	}
}

//����Ա���Ƿ����
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ�����Ϊ��" << endl;
	}
	else {
		int temp_select;
		cout << "����������Ҫ���ҵķ�ʽ" << endl;
		cout << "1.ְ����Ų�ѯ 2.ְ��������ѯ" << endl;
		while (1) {
			cin >> temp_select;
			if (temp_select != 1 && temp_select != 2) {
				this->err();
			}
			else {
				if (temp_select == 1) {
					int temp_id;
					cout << "����������Ҫ����ְ����Ϣ��ְ�����" << endl;
					cin >> temp_id;
					int index = this->Search_Emp(temp_id);
					if (index == -1) {
						cout << "δ�鵽��ְ��" << endl;
					}
					else {
						cout << "��ѯ��������Ϣ:" << endl;
						this->m_EmpArray[index - 1]->showlofo();
					}
				}
				else if (temp_select == 2) {
					string temp_name;
					int temp_num = 0;
					cout << "����������Ҫ����ְ����Ϣ��ְ������" << endl;
					cin >> temp_name;

					for (int i = 0; i < this->m_Empnum; i++) {
						if (this->m_EmpArray[i]->m_Name == temp_name) {
							temp_num++;
						}
					}
					if (temp_num==0) {
						cout << "δ�ҵ�����ϵ��" << endl;
					}
					else {
						cout << "��ѯ��" << temp_num << "�������" << endl;
						for (int j = 0; j < this->m_Empnum; j++) {
							if (this->m_EmpArray[j]->m_Name == temp_name) {
								this->m_EmpArray[j]->showlofo();
							}
						}
					}
				}
				break;
			}
		}
	}
}

void WorkerManager::sort_Emp_id() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��������������� 2.���ս����������" << endl;
		int temp_select;
		while (1) {
			cin >> temp_select;
			if (temp_select != 1 && temp_select != 2) {
				cout << "������������������" << endl;
			}
			else {
				int temp_flag;
				for (int i = 0; i < this->m_Empnum-1; i++) {
					temp_flag = i;
					for (int j = i + 1; j < this->m_Empnum; j++) {
						if (temp_select == 1) {
							//����
							if (this->m_EmpArray[temp_flag]->m_ID > this->m_EmpArray[j]->m_ID) {
								temp_flag = j;
							}
						}
						else if (temp_select == 2) {
							//����
							if (this->m_EmpArray[temp_flag]->m_ID < this->m_EmpArray[j]->m_ID) {
								temp_flag = j;
							}
						}
					}
					//if (i != temp_flag) {
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[temp_flag];
						this->m_EmpArray[temp_flag] = temp;
					//}
				}
				this->file_save();

				cout << "����ɹ�" << endl;
				break;
			}
		}
	}
}

//����ļ�
void WorkerManager::file_clean() {
	cout << "ȷ�������" << endl;
	cout << "1.ȷ�� 2.ȡ��" << endl;
	int temp_select;
	while (1) {
		cin >> temp_select;
		if (temp_select != 1 && temp_select != 2) {
			cout << "�����������������" << endl;
		}
		else {
			if (temp_select == 1) {
				ofstream ofs;
				ofs.open(FILENAME, ios::trunc);
				ofs.close();

				//�����ڴ�
				if (this->m_EmpArray != NULL) {
					for (int i = 0; i < this->m_Empnum; i++) {
						delete this->m_EmpArray[i];
					}
				}
				this->m_Empnum = 0;
				delete[]this->m_EmpArray; 
				this->m_EmpArray = NULL;
				this->m_FileIsEmpty = true;

				cout << "��ճɹ�" << endl;
			}
			else if (temp_select == 2) {
				cout << "��ȡ������" << endl;
			}
			break;
		}
	}
}

//�˳�����ϵͳ
void WorkerManager::exit() {
	cout << "��ӭ�´�ʹ��!" << endl;
	return;
}

//չʾ�˵�
void WorkerManager::Show_menu() {
	cout << "**********************************************" << endl;
	cout << "************��ӭʹ��ְ������ϵͳ��************" << endl;
	cout << "****************0.�˳�����ϵͳ****************" << endl;
	cout << "****************1.����ְ����Ϣ****************" << endl;
	cout << "****************2.��ʾְ����Ϣ****************" << endl;
	cout << "****************3.ɾ����ְְ��****************" << endl;
	cout << "****************4.�޸�ְ����Ϣ****************" << endl;
	cout << "****************5.����ְ����Ϣ****************" << endl;
	cout << "****************6.���ձ������****************" << endl;
	cout << "****************7.��������ĵ�****************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
