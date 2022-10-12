//���ѧ����Ϣ
//��ʾѧ����Ϣ
//ɾ��ѧ����Ϣ
//����ѧ����Ϣ
//�޸�ѧ����Ϣ
//��չ���ϵͳ
//�˳�ϵͳ

//��װ������ʾ�ý���  ��void showMenu
//��main�����е��÷�װ�õĺ���
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//���ѧ����Ϣ�ṹ��
struct Person
{
	string m_Name;    //����
	string m_Id;      //ѧ��
	int m_Sex;        //�Ա�  1��  2Ů
	int m_Age;        //����
	string m_Major;   //רҵ
	int m_Ban;      //�༶
	string m_Number;  //���֤��
	string m_Addr;    //סַ
};

//�����Ϣ����ṹ��
struct Addressbooks
{
	//�����ѧ������
	struct Person personArray[MAX];

	//��ǰ��¼��ѧ������
	int m_Size;
};

void showMenu()//�˵�����
{
	cout << "*******************************" << endl;
	cout << "******  1�����ѧ����Ϣ  ******" << endl;
	cout << "******  2����ʾѧ����Ϣ  ******" << endl;
	cout << "******  3��ɾ��ѧ����Ϣ  ******" << endl;
	cout << "******  4������ѧ����Ϣ  ******" << endl;
	cout << "******  5���޸�ѧ����Ϣ  ******" << endl;
	cout << "******  6����չ���ϵͳ  ******" << endl;
	cout << "******  0���˳�����ϵͳ  ******" << endl;
	cout << "*******************************" << endl;
}

void addPerson(Addressbooks* abs)//���ѧ��ģ��
{
	//�жϹ���ϵͳ�Ƿ����������������ʾ�޷����
	//���δ����������
	if (abs->m_Size == MAX)
	{
		cout << "ѧ�������������޷���ӣ�" << endl;
		return;
	}
	else //��Ӿ���ѧ����Ϣ
	{
		//�������
		string name;
		cout << "������ѧ��������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//���ѧ��
		string id;
		cout << "������ѧ�ţ�" << endl;
		cin >> id;
		abs->personArray[abs->m_Size].m_Id = id;

		//����Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "ע�⣺1--�У�2--Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)//����1,2д���Ա���������������
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		//�������
		int age = 0;
		cout << "���������䣺" << endl;
		while (true)
		{
			cin >> age;
			if ((age > 0) && (age <= 120))
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		//���רҵ
		string major;
		cout << "������רҵ��" << endl;
		cin >> major;
		abs->personArray[abs->m_Size].m_Major = major;

		//��Ӱ༶
		int ban;
		cout << "������༶��" << endl;
		cin >> ban;
		abs->personArray[abs->m_Size].m_Ban = ban;

		//������֤��
		string number;
		cout << "���������֤�ţ�" << endl;
		cin >> number;
		abs->personArray[abs->m_Size].m_Number = number;

		//���סַ
		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		//��ʾ�����ɹ�
		cout << "��ӳɹ���" << endl;
		system("pause");//�밴���������
		system("cls");//��������
	}
}

void showPerson(Addressbooks* abs)//��ʾѧ����Ϣģ��
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "ѧ�ţ�" << abs->personArray[i].m_Id << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "רҵ��" << abs->personArray[i].m_Major << "\t";
			cout << "�༶��" << abs->personArray[i].m_Ban << "\t";
			cout << "���֤�ţ�" << abs->personArray[i].m_Number << "\t";
			cout << "��ͥסַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//���ѧ����Ϣ�Ƿ����
//������ڣ�����ѧ����������ľ���λ�ã������ڷ���-1
//����1 ��Ϣ ������2 �Ա�����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)//�ҵ��û���������
		{
			return i;//�ҵ�����������������е��±���
		}
	}
	return -1;//�������������û�ҵ�������-1
}


void deletePerson(Addressbooks* abs)//ɾ��ָ��ѧ����Ϣģ��
{
	cout << "��������Ҫɾ����ѧ����" << endl;
	string name;
	cin >> name;
	//ret==-1  δ�鵽���ˣ�ret��=-1  �鵽����
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//�鵽���ˣ�����ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//����ͨѶ¼������
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}


void findPerson(Addressbooks* abs)//����ָ����ϵ��ģ��
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	//�ж�ָ����ϵ���Ƿ����
	int ret = isExist(abs, name);

	if (ret != -1)//�ҵ�ѧ����Ϣ
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "ѧ�ţ�" << abs->personArray[ret].m_Id << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "רҵ��" << abs->personArray[ret].m_Major << "\t";
		cout << "�༶��" << abs->personArray[ret].m_Ban << "\t";
		cout << "���֤�ţ�" << abs->personArray[ret].m_Number << "\t";
		cout << "��ͥסַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else//δ�鵽ѧ����Ϣ
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)//�޸�ѧ����Ϣģ��
{
	cout << "��������Ҫ�޸ĵ�ѧ����Ϣ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//�ҵ�ѧ����Ϣ
	{
		//�޸�����
		string name;
		cout << "��������ϵ��������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�޸�ѧ��
		string id;
		cout << "������ѧ�ţ�" << endl;
		cin >> id;
		abs->personArray[abs->m_Size].m_Id = id;

		//�޸��Ա�
		int sex = 0;
		cout << "��������ϵ���Ա�" << endl;
		cout << "ע�⣺1--�У�2--Ů" << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)//����1,2д���Ա���������������
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		//�޸�����
		int age = 0;
		cout << "���������䣺" << endl;
		while (true)
		{
			cin >> age;
			if ((age > 0) && (age <= 120))
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		//�޸�רҵ
		string major;
		cout << "������רҵ��" << endl;
		cin >> major;
		abs->personArray[ret].m_Major = major;

		//�޸İ༶
		int ban;
		cout << "������༶��" << endl;
		cin >> ban;
		abs->personArray[ret].m_Ban = ban;

		//�޸����֤��
		string number;
		cout << "���������֤�ţ�" << endl;
		cin >> number;
		abs->personArray[ret].m_Number = number;

		//�޸�סַ
		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else//δ�ҵ�
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;//����¼ѧ����Ϣ������Ϊ0�����߼���ղ���
	cout << "����ϵͳ�����!" << endl;
	system("pause");
	system("cls");
}

int main()
{
	Addressbooks abs;//����ѧ����Ϣ�ṹ�����
	abs.m_Size = 0;//��ʼ����Ϣϵͳ����

	int select = 0;//�����û�ѡ�����

	while (true)
	{
		showMenu();//�˵�����

		cin >> select;

		switch (select)
		{
		case 1://���ѧ����Ϣ
			addPerson(&abs);//���õ�ַ���ݣ���������ʵ��
			break;
		case 2://��ʾѧ����Ϣ
			showPerson(&abs);
			break;
		case 3://ɾ��ѧ����Ϣ
			//{
				//cout << "��������Ҫɾ����ѧ����Ϣ������" << endl;
				//string name;
				//cin >> name;
				//if (isExist(&abs, name) == -1)
				//{
				//	cout << "���޴��ˣ�" << en3dl;
				//}
				//else
				//{
				//	cout << "�ҵ����ˣ�" << endl;
				//}
			//}
			deletePerson(&abs);
			break;
		case 4://����ѧ����Ϣ
			findPerson(&abs);
			break;
		case 5://�޸�ѧ����Ϣ
			modifyPerson(&abs);
			break;
		case 6://�����Ϣϵͳ
			cleanPerson(&abs);
			break;
		case 0://�˳�����ϵͳ
			cout << "��ӭ�´�ʹ�ã�" << endl;
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