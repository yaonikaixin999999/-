#include"workerManager.h"
using namespace std;

//初始化
WorkerManager::WorkerManager() {
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_Empnum = 0;
		//初始化数组指针为空
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	};

	//2.文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件数据为空" << endl;
		//初始化属性
		//初始化记录人数
		this->m_Empnum = 0;
		//初始化数组指针为空
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，数据存在，并且记录人数个数
	int num = this->file_Empnum();
	//cout << "当前记录的职工人数为：" << num << "人" << endl;
	this->m_Empnum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_Empnum];
	//将文件中的数据，存到数组中
	this->start_Emp();

	//测试代码
	/*for (int i = 0; i < this->m_Empnum; i++) {
		cout << "职工编号为：" << this->m_EmpArray[i]->m_ID
			 << " 职工姓名为：" << this->m_EmpArray[i]->m_Name
			 << " 职工职位为：" << this->m_EmpArray[i]->m_DeptID << endl;
	}*/
	ifs.close();
};

//初始化员工
void WorkerManager::start_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dID;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dID) {
		Worker* worker = NULL;

		//普通职工
		if (dID == 1) {
			worker = new Employee(id, name, dID);
		}
		//经理
		else if (dID == 2) {
			worker = new Manager(id, name, dID);
		}
		//老板
		else if (dID == 3) {
			worker = new BOSS(id,name, dID);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//统计文件中人数个数
int WorkerManager::file_Empnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dID;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dID) {
		//统计人数变量
		num++;
	}
	ifs.close(); 
	return num;
}

//输入错误
void WorkerManager::err() {
	cout << "输入错误，请重新输入" << endl;
};

//按任意键退出并且清屏
void WorkerManager::quick_clean() {
	system("pause");
	system("cls");
}

//显示职工信息		
void WorkerManager::contentWorker() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_Empnum; i++) {
			this->m_EmpArray[i]->showlofo();
		}

		//ifstream ifs;
		//ifs.open("职工信息.txt", ios::in);
		//char temp[1024] = { 0 };
		//if (temp[0] != NULL) {
		//	while (ifs.getline(temp, sizeof(temp))) {
		//		cout << "职工编号" << temp << endl;
		//	}
		//}
		//else {
		//	cout << "当前暂无员工信息" << endl;
		//}
		//ifs.close();
		//system("pause");
	}
}

//保存职工信息
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

//添加职工（指正）
void WorkerManager::add_Emp() {
	cout << "请输入您要添加职工的数量:" << endl;
	int addNum = 0;		//添加的数量
	FLAG:
	cin >> addNum;
	if (addNum > 0) {
		//计算新的空间大小
		int newSize = this->m_Empnum + addNum;		//新空间人数
		//开辟新空间
		Worker** newspace = new Worker * [newSize];
		//将原来空间下的数据拷贝到新空间
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_Empnum; i++) {
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//根据输入的数量批量添加新的数据
		for (int i = 0; i < addNum; i++) {
			int id;		//职工编号
			string name;		//职工姓名
			int dID;		//部门编号

			cout << "请输入地第" << i + 1 << "个新职工的职工编号" << endl;
			cin >> id;
			cout << "请输入地第" << i + 1 << "个新职工的职工姓名" << endl;
			cin >> name;
			cout << "请选择第" << i + 1 << "个新职工的岗位" << endl;
			cout << "1.普通员工	2.经理	3.老板" << endl;
			
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

			//将创建职工职责，保存到数组中
			newspace[this->m_Empnum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;
			
		//更改新空间的指向
		this->m_EmpArray = newspace;

		//更新新的职工人数
		this->m_Empnum = newSize;

		//更新文件状态，文件数据不为空的标志
		this->m_FileIsEmpty = false;

		this->file_save();	
		cout << "成功添加" << addNum << "名新职工" << endl;
	}
	else {
		this->err();
		goto FLAG;
	}
}

//增加职工信息
void WorkerManager::addWorker() {
	ofstream ofs;
	ofs.open("职工信息.txt", ios::app);
	cout << "请输入想要添加的职工数量" << endl;
	int num, temp;		//员工数量
	cin >> num;
	for (int i = 0; i < num; i++) {
		string strnum, strname;
		cout << "请输入第" << i + 1 << "个新职工编号" << endl;
		cin >> strnum;
		ofs << strnum << "  ";
		cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
		cin >> strname;
		ofs << strname << "  ";
		cout << "请选择该职工的岗位" << endl;
		cout << "1.普通职工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
		cin >> temp;
		//while (1) {
		//	switch (temp) {
		//	case 1:
		//		ofs << "普通员工" << endl;
		//		break;
		//	case 2:
		//		ofs << "经理" << endl;
		//		break;
		//	case 3:
		//		ofs << "老板" << endl;
		//		break;
		//	default:
		//		cout << "输入错误请重新输入" << endl;
		//		break;
		//	}
		//	if (temp == 1 && temp == 2 && temp == 3) {
		//		break;
		//	}
		//}
		system("cls");
	}
	cout << "成功添加" << num << "名新职工" << endl;
	ofs.close();
	system("pause");
}

//查找员工是否存在
int WorkerManager::Search_Emp(int ID) {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int dID;
	int location_Emp = 0;

	//如果找到该员工则返回该员工的位置
	while (ifs >> id && ifs >> name && ifs >> dID) {
		location_Emp++;
		if (ID == id) {
			return location_Emp;
			break;
		}
	}

	//没有找到该员工
	return -1;
}

//删除职工信息
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者数据为空" << endl;
	}
	else {
		cout << "请输入您想要删除职工的编号" << endl;
		int temp;
		int ID;		//编号
		cin >> ID;
		int index = this->Search_Emp(ID);
		if (index == -1) {
			cout << "删除失败，未找到该职工" << endl;
		}
		else {
			cout << "确定删除该职工吗?" << endl;
			cout << "1.确定 2.取消" << endl;
			while (1) {
				cin >> temp;
				if (temp != 1 && temp != 2) {
					this->err();
				}
				else {
					if (temp == 1) {
						for (int i = index - 1; i < this->m_Empnum; i++) {
							//数据前移
							this->m_EmpArray[i] = this->m_EmpArray[i + 1];
						}
						//更新记录职工人数
						m_Empnum--;

						//数据同步至本地文件中
						this->file_save();

						cout << "职工删除成功" << endl;
					}else if(temp==2){
						cout << "已取消删除" << endl;
					}
					break;
				}
			}
		}
	}
}

//修改员工信息
void WorkerManager::change_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或数据为空" << endl;
	}
	else {
		cout << "请输入您想要修改职工信息的职工编号" << endl;
		int ID;
		cin >> ID;
		int index = this->Search_Emp(ID);
		if (index == -1) {
			cout << "修改失败，未找到该联系人" << endl;
		}
		else {
			string temp_name;
			int temp_dID;
			int temp;
			cout << "请输入该员工修改后的姓名" << endl;
			cin >> temp_name;
			cout << "请输入该员工修改后的职位" << endl;
			cout << "1.普通员工 2.经理 3.老板" << endl;
			while (1) {
				cin >> temp_dID;
				if (temp_dID != 1 && temp_dID != 2 && temp_dID != 3) {
					cout << "输入错误，请重新输入" << endl;
				}
				else {  
					break;
				}
			}

			cout << "确定修改吗？" << endl;
			cout << "1.确定 2.取消" << endl;
			while (1) {
				cin >> temp;
				if (temp != 1 && temp != 2) {
					cout << "输入错误，请重新输入" << endl;
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

						//(我的猜想，有已知bug)
						//this->m_EmpArray[index - 1]->m_Name = temp_name;
						//this->m_EmpArray[index - 1]->m_DeptID = temp_dID;

						this->file_save();
						cout << "职工信息修改成功" << endl;
					}
					else if (temp == 2) {
						cout << "已取消修改" << endl;
					}
					break;
				}
			}
		}
	}
}

//查找员工是否存在
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或数据为空" << endl;
	}
	else {
		int temp_select;
		cout << "请输入您想要查找的方式" << endl;
		cout << "1.职工编号查询 2.职工姓名查询" << endl;
		while (1) {
			cin >> temp_select;
			if (temp_select != 1 && temp_select != 2) {
				this->err();
			}
			else {
				if (temp_select == 1) {
					int temp_id;
					cout << "请输入您想要查找职工信息的职工编号" << endl;
					cin >> temp_id;
					int index = this->Search_Emp(temp_id);
					if (index == -1) {
						cout << "未查到该职工" << endl;
					}
					else {
						cout << "查询到以下信息:" << endl;
						this->m_EmpArray[index - 1]->showlofo();
					}
				}
				else if (temp_select == 2) {
					string temp_name;
					int temp_num = 0;
					cout << "请输入您想要查找职工信息的职工姓名" << endl;
					cin >> temp_name;

					for (int i = 0; i < this->m_Empnum; i++) {
						if (this->m_EmpArray[i]->m_Name == temp_name) {
							temp_num++;
						}
					}
					if (temp_num==0) {
						cout << "未找到该联系人" << endl;
					}
					else {
						cout << "查询到" << temp_num << "条结果：" << endl;
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
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1.按照升序进行排序 2.按照降序进行排序" << endl;
		int temp_select;
		while (1) {
			cin >> temp_select;
			if (temp_select != 1 && temp_select != 2) {
				cout << "输入有误，请重新输入" << endl;
			}
			else {
				int temp_flag;
				for (int i = 0; i < this->m_Empnum-1; i++) {
					temp_flag = i;
					for (int j = i + 1; j < this->m_Empnum; j++) {
						if (temp_select == 1) {
							//升序
							if (this->m_EmpArray[temp_flag]->m_ID > this->m_EmpArray[j]->m_ID) {
								temp_flag = j;
							}
						}
						else if (temp_select == 2) {
							//降序
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

				cout << "排序成功" << endl;
				break;
			}
		}
	}
}

//清空文件
void WorkerManager::file_clean() {
	cout << "确定清空吗？" << endl;
	cout << "1.确定 2.取消" << endl;
	int temp_select;
	while (1) {
		cin >> temp_select;
		if (temp_select != 1 && temp_select != 2) {
			cout << "输入错误，请重新输入" << endl;
		}
		else {
			if (temp_select == 1) {
				ofstream ofs;
				ofs.open(FILENAME, ios::trunc);
				ofs.close();

				//回收内存
				if (this->m_EmpArray != NULL) {
					for (int i = 0; i < this->m_Empnum; i++) {
						delete this->m_EmpArray[i];
					}
				}
				this->m_Empnum = 0;
				delete[]this->m_EmpArray; 
				this->m_EmpArray = NULL;
				this->m_FileIsEmpty = true;

				cout << "清空成功" << endl;
			}
			else if (temp_select == 2) {
				cout << "已取消操作" << endl;
			}
			break;
		}
	}
}

//退出管理系统
void WorkerManager::exit() {
	cout << "欢迎下次使用!" << endl;
	return;
}

//展示菜单
void WorkerManager::Show_menu() {
	cout << "**********************************************" << endl;
	cout << "************欢迎使用职工管理系统！************" << endl;
	cout << "****************0.退出管理系统****************" << endl;
	cout << "****************1.增加职工信息****************" << endl;
	cout << "****************2.显示职工信息****************" << endl;
	cout << "****************3.删除离职职工****************" << endl;
	cout << "****************4.修改职工信息****************" << endl;
	cout << "****************5.查找职工信息****************" << endl;
	cout << "****************6.按照编号排序****************" << endl;
	cout << "****************7.清空所有文档****************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
