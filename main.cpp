#include"Phone_List.h"
#include<iostream>
#include<Windows.h>
using namespace std;
void correct(node*& temp)
{
	int tocorrect;
			cin >> tocorrect;

			switch (tocorrect)
			{
			case 1:
			{
				cout << "�����µĵ绰��" << endl;
				string s;
				cin >> s;
				temp->phone_number = s;

				break;
			}
			case 2:
			{
				cout << "�����µ����֣�" << endl;
				string s;
				cin >> s;
				temp->name = s;
				break;
			}
			case 3:
			{
				cout << "�����µ��Ա�" << endl;
				string s;
				cin >> s;
				temp->sex = s;
				break;
			}
			case 4:
			{
				cout << "�����µķ��ࣺ" << endl;
				string s;
				cin >> s;
				temp->catagory = s;
				break;
			}
			case 5:
			{
				cout << "�����µ�QQ��" << endl;
				string s;
				cin >> s;
				temp->QQ = s;
				break;
			}
			case 6:
			{
				cout << "�����µ�΢�ţ�" << endl;
				string s;
				cin >> s;
				temp->WeChat = s;
				break;
			}
			case 7:
			{
				cout << "�����µ����գ�" << endl;
				cout << "��ݣ�";
				int y;
				cin >> y;
				cout << "�·�:";
				int m;
				cin >> m;
				cout << "���ڣ�";
				int d;
				cin >> d;
				temp->day.year = y;
				temp->day.month = m;
				temp->day.day = d;
				break;
			}
			case 8:
			{
				cout << "�����µĵ�ַ��" << endl;
				string s;
				cin >> s;
				temp->address = s;
				break;
			}
			case 9:
			{
				cout << "�����µ����䣺" << endl;
				string s;
				cin >> s;
				temp->email = s;
				break;
			}
			case 10:
			{
				cout << "�����µ��ʱࣺ" << endl;
				string s;
				cin >> s;
				temp->mail = s;
				break;
			}
			default:
				cout << "������󣡷������˵���" << endl;
				break;
		}
}
void displayInfoMenu()
{
	cout << "______________�����޸���Ϣ�����_________________" << endl;
	cout << "1.�绰               2.����                 3.�Ա�" << endl;
	cout << "4.����               5.QQ                   6.΢��" << endl;
	cout << "7.����               8.��ַ                 9.����" << endl;
	cout << "10.�ʱ�                                           " << endl;

}
void Menu()
{
	cout << "*******************�˵�********************" << endl;
	cout << "   1.����ͨѶ¼       2.չʾ��ϵ����Ϣ" << endl;
	cout << "   3.�½���ϵ��       4.ɾ����ϵ��" << endl;
	cout << "   5.�޸���ϵ����Ϣ   6.�鿴ͨѶ¼" << endl;
	cout << "   7.�˳�����" << endl;

	cout << "����������ѡ�" << endl;
}

int main()
{

	cout << "***********************************" << endl;
	cout << "            ��ӭʹ��ͨѶ¼           " << endl;
	cout << "***********************************" << endl;

	bool flag = 1;
	PhoneList myList;

	while (flag)
	{
		Menu();
		int choice;
		cin >> choice;

		switch (choice)
		{

		case 1://����
		{
			cout << "************����ͨѶ¼***************" << endl;
			cout << "����1��txt�ĵ����룻����2��excel�ļ����룺";
			int mod;
			cin >> mod;
			if (mod == 1)
			{
				cout << "���ڵ���......." << endl;
				Sleep(3000);
				if (myList.creatListFromFile())
				{
					cout << "����ɹ���" << endl;
				}
				else
				{
					cout << "����ʧ�ܣ�" << endl;
				}
			}
			else if (mod == 2)
			{
				cout << "���ڵ���......." << endl;
				Sleep(3000);
				if (myList.creatListFromExcel())
				{
					cout << "����ɹ���" << endl;
				}
				else
				{
					cout << "����ʧ�ܣ�" << endl;
				}
			}
			else
			{
				cout << "û�д�ģʽ���������˵���" << endl;
			}
			break;
		}
		case 2://2.չʾ��ϵ����Ϣ
		{
			cout << "���������밴1�� �����绰�����밴2: " << endl;
			int mod;
			cin >> mod;

			node* temp;
			if (mod == 1)//���ּ���
			{
				string name;
				cin >> name;
				myList.searchAssignName(name, temp);
				if (temp != NULL)
				{
					temp->displayNode();
				}
				else
				{
					cout << "���޴��ˣ��������˵���" << endl;
				}
			}
			else if (mod == 2)
			{
				string phone;
				cin >> phone;
				myList.searchAssignPhone(phone, temp);
				if (temp != NULL)
				{
					temp->displayNode();
				}
				else
				{
					cout << "���޴��ˣ��������˵���" << endl;
				}

			}
			else
			{
				cout << "û�д�ģʽ���������˵���" << endl;
			}
			break;
		}
		case 3:// 3.�½���ϵ��
		{
			cout << "_________________�½���ϵ��____________________" << endl;
			myList.insert_new_node();
			cout << "����ɹ���" << endl;
			break;
		}
		case 4:// 4.ɾ����ϵ��
		{
			cout << "_________________ɾ����ϵ��____________________" << endl;
			cout << "����Ҫɾ����ϵ�˵�������" << endl;
			string name;
			cin >> name;
			myList.deleteBFS(name);

			break;
		}
		case 5://5.�޸���ϵ����Ϣ
		{
			cout << "_________________�޸���ϵ��____________________" << endl;
			cout << "������������ϵ���밴1���ӵ绰���������ϵ���밴2" << endl;
			int mod;
			cin >> mod;

			node* temp;
			bool success=1;
			if (mod == 1)
			{
				cout << "������Ҫ�޸ĵ���ϵ�˵����֣�" << endl;
				string name;
				cin >> name;
				myList.searchAssignName(name, temp);
				if (temp == NULL)
				{
					success = 0;
				}
				
			}
			else if (mod == 2)
			{
				cout << "������Ҫ�޸ĵ���ϵ�˵ĵ绰���룺" << endl;
				string phone;
				cin >> phone;
				myList.searchAssignPhone(phone, temp);
				if (temp == NULL)
				{
					success = 0;
				}
			}
			else
			{
				cout << "û�д�ģʽ���������˵���" << endl;
				break;
			}
			if (success == 1)
			{
				displayInfoMenu();
				correct(temp);
			}
			else
			{
				cout << "���޴���ϵ�ˣ��������˵���" << endl;
			}
			
			
			break;
		}
		case 6:// 6.�鿴ͨѶ¼
		{
			myList.display();
			break;
		}

		case 7://exit
		{
			flag = 0;
			cout << "       ��лʹ�ã�����ϵ��         " << endl;
			cout << "_________________________________________" << endl;
			break;
		}

		default:
		{
			cout << "�������ѡ��������˵���" << endl;
			break;
		}

		}
	}
	return 0;
}


