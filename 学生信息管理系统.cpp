//添加学生信息
//显示学生信息
//删除学生信息
//查找学生信息
//修改学生信息
//清空管理系统
//退出系统

//封装函数显示该界面  如void showMenu
//在main函数中调用封装好的函数
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//设计学生信息结构体
struct Person
{
	string m_Name;    //姓名
	string m_Id;      //学号
	int m_Sex;        //性别  1男  2女
	int m_Age;        //年龄
	string m_Major;   //专业
	int m_Ban;      //班级
	string m_Number;  //身份证号
	string m_Addr;    //住址
};

//设计信息管理结构体
struct Addressbooks
{
	//保存的学生数组
	struct Person personArray[MAX];

	//当前记录的学生人数
	int m_Size;
};

void showMenu()//菜单界面
{
	cout << "*******************************" << endl;
	cout << "******  1、添加学生信息  ******" << endl;
	cout << "******  2、显示学生信息  ******" << endl;
	cout << "******  3、删除学生信息  ******" << endl;
	cout << "******  4、查找学生信息  ******" << endl;
	cout << "******  5、修改学生信息  ******" << endl;
	cout << "******  6、清空管理系统  ******" << endl;
	cout << "******  0、退出管理系统  ******" << endl;
	cout << "*******************************" << endl;
}

void addPerson(Addressbooks* abs)//添加学生模块
{
	//判断管理系统是否已满，如果已满提示无法添加
	//如果未满则继续添加
	if (abs->m_Size == MAX)
	{
		cout << "学生人数已满，无法添加！" << endl;
		return;
	}
	else //添加具体学生信息
	{
		//添加姓名
		string name;
		cout << "请输入学生姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//添加学号
		string id;
		cout << "请输入学号：" << endl;
		cin >> id;
		abs->personArray[abs->m_Size].m_Id = id;

		//添加性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "注意：1--男，2--女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)//输入1,2写入性别，其他请重新输入
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		//添加年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			if ((age > 0) && (age <= 120))
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		//添加专业
		string major;
		cout << "请输入专业：" << endl;
		cin >> major;
		abs->personArray[abs->m_Size].m_Major = major;

		//添加班级
		int ban;
		cout << "请输入班级：" << endl;
		cin >> ban;
		abs->personArray[abs->m_Size].m_Ban = ban;

		//添加身份证号
		string number;
		cout << "请输入身份证号：" << endl;
		cin >> number;
		abs->personArray[abs->m_Size].m_Number = number;

		//添加住址
		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;

		//提示操作成功
		cout << "添加成功！" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

void showPerson(Addressbooks* abs)//显示学生信息模块
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "学号：" << abs->personArray[i].m_Id << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "专业：" << abs->personArray[i].m_Major << "\t";
			cout << "班级：" << abs->personArray[i].m_Ban << "\t";
			cout << "身份证号：" << abs->personArray[i].m_Number << "\t";
			cout << "家庭住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测学生信息是否存在
//如果存在，返回学生所在数组的具体位置，不存在返回-1
//参数1 信息 ；参数2 对比姓名
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)//找到用户输入姓名
		{
			return i;//找到返回这个人在数组中的下标编号
		}
	}
	return -1;//如果遍历结束还没找到，返回-1
}

void deletePerson(Addressbooks* abs)//删除指定学生信息模块
{
	cout << "请输入你要删除的学生：" << endl;
	string name;
	cin >> name;
	//ret==-1  未查到此人；ret！=-1  查到该人
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//查到此人，进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新信息系统中人数
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}


void findPerson(Addressbooks* abs)//查找指定学生信息模块
{
	cout << "请输入需要查找的学生信息：" << endl;
	string name;
	cin >> name;

	//判断指定学生是否存在
	int ret = isExist(abs, name);

	if (ret != -1)//找到学生信息
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "学号：" << abs->personArray[ret].m_Id << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "专业：" << abs->personArray[ret].m_Major << "\t";
		cout << "班级：" << abs->personArray[ret].m_Ban << "\t";
		cout << "身份证号：" << abs->personArray[ret].m_Number << "\t";
		cout << "家庭住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else//未查到学生信息
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)//修改学生信息模块
{
	cout << "请输入需要修改的学生信息：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//找到学生信息
	{
		//修改姓名
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//修改学号
		string id;
		cout << "请输入学号：" << endl;
		cin >> id;
		abs->personArray[abs->m_Size].m_Id = id;

		//修改性别
		int sex = 0;
		cout << "请输入联系人性别：" << endl;
		cout << "注意：1--男，2--女" << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)//输入1,2写入性别，其他请重新输入
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		//修改年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			if ((age > 0) && (age <= 120))
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		//修改专业
		string major;
		cout << "请输入专业：" << endl;
		cin >> major;
		abs->personArray[ret].m_Major = major;

		//修改班级
		int ban;
		cout << "请输入班级：" << endl;
		cin >> ban;
		abs->personArray[ret].m_Ban = ban;

		//修改身份证号
		string number;
		cout << "请输入身份证号：" << endl;
		cin >> number;
		abs->personArray[ret].m_Number = number;

		//修改住址
		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else//未找到
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;//将记录学生信息数量重置为0；做逻辑清空操作
	cout << "管理系统已清空!" << endl;
	system("pause");
	system("cls");
}

int main()
{
	Addressbooks abs;//创建学生信息结构体变量
	abs.m_Size = 0;//初始化信息系统人数

	int select = 0;//创建用户选择变量

	while (true)
	{
		showMenu();//菜单调用

		cin >> select;

		switch (select)
		{
		case 1://添加学生信息
			addPerson(&abs);//利用地址传递，可以修饰实参
			break;
		case 2://显示学生信息
			showPerson(&abs);
			break;
		case 3://删除学生信息
			//{
				//cout << "请输入需要删除的学生信息姓名：" << endl;
				//string name;
				//cin >> name;
				//if (isExist(&abs, name) == -1)
				//{
				//	cout << "查无此人！" << en3dl;
				//}
				//else
				//{
				//	cout << "找到此人！" << endl;
				//}
			//}
			deletePerson(&abs);
			break;
		case 4://查找学生信息
			findPerson(&abs);
			break;
		case 5://修改学生信息
			modifyPerson(&abs);
			break;
		case 6://清空信息系统
			cleanPerson(&abs);
			break;
		case 0://退出管理系统
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}
