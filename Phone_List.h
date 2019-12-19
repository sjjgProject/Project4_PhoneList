#pragma once
#pragma once

#include<iostream>
#include<string>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<cstdlib>
#include<string>
using namespace std;

struct birthday {
	int year;
	int month;
	int day;
};
struct node {
	string phone_number;
	string name;
	string sex;
	string catagory;//���
	string QQ;
	string WeChat;
	birthday day;//����
	string address;
	string email;
	string mail;

	node* leftchild;
	node* rightchild;
	node()
	{
		this->name = "0";
		this->phone_number = "0";
		this->sex = "0";
		this->catagory = "0";
		this->QQ = "0";
		this->WeChat = "0";
		this->day.year = this->day.month = this->day.year = 0;
		this->address = "0";
		this->email = "0";
		this->mail = "0";
	}
	node(string phone_number, string name, string sex, string catagory,
		string QQ, string WeChat, birthday day, string address, string email, string mail)
	{
		this->name = name;
		this->phone_number = phone_number;
		this->sex = sex;
		this->catagory = catagory;
		this->QQ = QQ;
		this->WeChat = WeChat;
		this->day = day;
		this->address = address;
		this->email = email;
		this->mail = mail;
	}
	void displayNode()
	{
		cout << "________________________________________" << endl;
		cout << "������"<<name << endl;
		cout << "   �绰��" << phone_number << endl;
		cout << "   �Ա�" << sex << endl;
		cout << "   ���ࣺ" << catagory << endl;
		cout << "   QQ��" << QQ << endl;
		cout << "   ΢�ţ�" << WeChat << endl;
		cout << "   ���գ�" << day.year <<" "<<day.month<<" "<<day.day<< endl;
		cout << "   ��ַ��" << address << endl;
		cout << "   �������䣺" << email << endl;
		cout << "   �ʱࣺ" << mail << endl;
		cout<<"___________________________________________"<< endl;
		
	}
};

class PhoneList {
public:
	node* root;
	PhoneList() {
		root = NULL;

	}
	
	bool creatListFromFile()//��txtд�������ɹ�����1
	{
		ifstream fin;
		fin.open("Phone.txt", ios::in);//��ȡ��ʽ���ļ�

		if (!fin.is_open())//��ʧ��
		{
			cout << "�ļ����ܴ�" << endl;
			return false;
		}
		else//�򿪳ɹ�
		{
			string sexName;
			char buffer[200];

			//fin.getline(buffer, 190);

			while (!fin.eof())//ѭ������
			{
				node* newMember = new node;
				
				//��������������ڵ�
				fin >> newMember->phone_number >> newMember->name >> newMember->sex >> newMember->catagory >> newMember->QQ;
				fin >> newMember->WeChat >> newMember->day.year >> newMember->day.month >> newMember->day.year;
				fin >> newMember->address >> newMember->email>>newMember->mail;

				
				newMember->leftchild = NULL;
				newMember->rightchild = NULL;

				insert(root,newMember);//���빹���õĽڵ�
			}


			fin.close();//�ر��ļ�
			return true;
		}
	}
	
	bool creatListFromExcel()//��excel��񴴽���
	{
		ifstream fin;
		fin.open("Phone.csv", ios::in);//��ȡ��ʽ���ļ�

		if (!fin.is_open())//��ʧ��
		{
			cout << "�ļ����ܴ�" << endl;
			return false;
		}
		else//�򿪳ɹ�
		{
			string temp;
			//getline(fin, temp);

			//while (!fin.eof())//ѭ������
			while(1)
			{
				getline(fin, temp);
				if (temp[0]==',')
				{
					break;
				}
				node* newMember = new node;

				//��������������ڵ�
				//getline(fin, temp);
				char* token;
				char s[2] = ",";
				string information[12];
				int count = 0;
				char* buf;
				/* ��ȡ��һ�����ַ��� */
				token = strtok_s((char*)temp.c_str(), s,&buf);

				/* ������ȡ���������ַ��� */
				while (token != NULL)
				{
					//cout << token << endl;
					information[count++] = token;
					token = strtok_s(NULL, s,&buf);
				}
				
					newMember->phone_number = information[0];
					newMember->name = information[1];
					newMember->sex = information[2];
					newMember->catagory = information[3];
					newMember->QQ = information[4];
					newMember->WeChat = information[5];
					newMember->day.year = stoi(information[6]);
					newMember->day.month = stoi(information[7]);
					newMember->day.day = stoi(information[8]);
					newMember->address = information[9];
					newMember->email = information[10];
					newMember->mail = information[11];

					newMember->leftchild = NULL;
					newMember->rightchild = NULL;

					insert(root, newMember);//���빹���õĽڵ�
				
			}
				


			fin.close();//�ر��ļ�
			return true;
		}
	}

	void display() {
		display_the_tree(root);
	}

	void display_the_tree(node*root) {//չʾ���ܵĵݹ麯��
		if (root == NULL) {
			return;
		}
		else {
			display_the_tree(root->leftchild);
			//cout << root->name << ":" << root->phone_number << endl;
			root->displayNode();
			display_the_tree(root->rightchild);
		}
	}

	void insert_new_node() {

		string phone_number;
		string name;
		string sex;
		string catagory;//���
		string QQ;
		string WeChat;
		birthday day;//����
		string address;
		string email;
		string mail;
		cout << "______________________________________" << endl;
		cout << "������ϵ����Ϣ,������ʾ˳��:"<<endl;

		cout << "�ֻ���" << endl;
		cin >> phone_number ;

		cout << "������" << endl;
		cin >> name;

		cout << "�Ա�(�л�Ů)��" << endl;
		cin >> sex;

		cout << "��𣨼��ˣ����ѣ�ͬ�£���" << endl;
		cin >>catagory;

		cout << "QQ��" << endl;
		cin >> QQ;

		cout << "΢�ţ�" << endl;
		cin >> WeChat;

		cout << "���գ�������˳�� �м��л��� eg: 1999 12 8��" << endl;
		cin >> day.year>>day.month>>day.year;

		cout << "��ַ��" << endl;
		cin >> address;

		cout << "���䣺" << endl;
		cin >> email;

		cout << "�ʱࣺ" << endl;
		cin >> mail;

		node* temp = new node(phone_number,name,sex,catagory,QQ,WeChat,day,address,email,mail);
		temp->leftchild = temp->rightchild = NULL;
		
		insert(root, temp);
	}

	void insert(node* &myroot, node* &toadd) {//����ĵݹ麯��
		if (myroot == NULL) {
			myroot = toadd;
		}
		else {
			if (toadd->name < myroot->name) {
				insert(myroot->leftchild, toadd);
			}
			else {
				insert(myroot->rightchild, toadd);
			}
		}
	}

	void get_info() {//������������ȡ�������Ϣ
		cout << "������Ҫ���ҵ�����" << endl;
		string name;
		cin >> name;
		
		node* result = searchNodeName( name);
		cout << "������" << root->name;
		cout << "�ֻ����룺" << root->phone_number;
	}


	void searchTreeName(node* root, node*& member, string name)//�ݹ�������Ա
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			if (root->name == name)
			{
				member = root;
				return;
			}
			else
			{
				searchTreeName(root->leftchild, member, name);
				searchTreeName(root->rightchild, member, name);
			}
		}
	}

	node* searchNodeName(string name)//���Ҳ����ؽڵ�,�Ҳ�������NULL
	{
		node* member = NULL;
		searchTreeName(root, member, name);
		return member;
	}

	void searchAssignName(string name, node*& member)//���Ҳ��ѽ�������ڵ����
	{
		member = NULL;
		searchTreeName(root, member, name);
	}

	void searchTreePhone(node* root, node*& member, string phone)//�ݹ�������Ա,���绰����
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			if (root->phone_number == phone)
			{
				member = root;
				return;
			}
			else
			{
				searchTreePhone(root->leftchild, member, phone);
				searchTreePhone(root->rightchild, member, phone);
			}
		}
	}

	node* searchNodePhone(string phone)//���Ҳ����ؽڵ�,�Ҳ�������NULL
	{
		node* member = NULL;
		searchTreePhone(root, member, phone);
		return member;
	}

	void searchAssignPhone(string phone, node*& member)//���Ҳ��ѽ�������ڵ����
	{
		member = NULL;
		searchTreePhone(root, member, phone);
	}

	void deleteBFS(string name) {
		if (delete_node(root, name) == false)
		{
			cout << "ɾ��ʧ��!" << endl;
		}
		else
		{
			cout << "ɾ���ɹ���" << endl;
		}
		
	}

	void swapall(node*a, node*b) {
		swap(a->name, b->name);
		swap(a->phone_number, b->phone_number);
		swap(a->sex, b->sex);
		swap(a->catagory, b->catagory);
		swap(a->QQ, b->QQ);
		swap(a->WeChat, b->WeChat);
		swap(a->day, b->day);
		swap(a->address, b->address);
		swap(a->email, b->email);
		swap(a->mail, b->mail);
	}

	bool delete_node(node* &myroot, string name)
	{
		//���ڵ�Ϊ��
		if (myroot == NULL)
		{
			cout << "ͨѶ¼Ϊ�գ�";
			return false;
		}
		//ֻ��һ���ڵ�,ֱ��ɾ��
		if (myroot->leftchild == NULL && myroot->rightchild == NULL)
		{
			delete myroot;
			myroot = NULL;
			return true;
		}

		node* parent = NULL;//ָ��ɾ���ڵ�ĸ�ĸ�ڵ�
		node* del = myroot;//ָ��Ҫɾ���Ľڵ㣬��ʼ��Ϊ���ڵ�

		while (del)//ѭ���ҵ�Ҫɾ���Ľڵ�
		{
			if (name > del->name)
			{
				parent = del;
				del = del->rightchild;
			}
			else if (name < del->name)
			{
				parent = del;
				del = del->leftchild;
			}
			else
			{
				break;
			}
		}
		cout << "��ĸ�� "<<parent->name << "Ҫɾ����" << del->name;

		if (del)//���ǿ���
		{
			if (name != del->name)//�Ҳ���������
			{
				cout << "ERROR:��������������󣡽��ص����˵���" << endl;
				return false;
			}
			else if (del->leftchild == NULL)//Ҫɾ���Ľڵ�û��������
			{
				if (del == myroot)//���ڵ�
				{
					myroot = del->rightchild;
				}
				else//�Ǹ�
				{
					if (del == parent->leftchild)//��ĳ�ڵ�������
					{
						parent->leftchild = del->rightchild;
					}
					else//��ĳ�ڵ�������
					{
						parent->rightchild = del->rightchild;
					}
				}
			}
			else if (del->rightchild == NULL)//û��������
			{
				if (del == myroot)//�Ǹ�
				{
					myroot = del->leftchild;
				}
				else//���Ǹ�
				{
					if (del == parent->leftchild)
					{
						parent->leftchild = del->leftchild;
					}
					else
					{
						parent->rightchild = del->rightchild;
					}
				}
			}
			else//��������
			{
				node* parent = del;
				node* firstInorder = del->rightchild;

				if (firstInorder->leftchild == NULL) 
				{//ֻ������������ֱ�ӻ���Ϣ
					
					swapall(del, firstInorder);//������Ϣ
					del->rightchild = firstInorder->rightchild;
					delete firstInorder;
					firstInorder = NULL;
					return true;
				}
				else
				{
					while (firstInorder->leftchild)//����������������
					{
						parent = firstInorder;
						firstInorder = firstInorder->leftchild;
					}

					swapall(del, firstInorder);//������Ϣ
					parent->leftchild = firstInorder->leftchild;
					delete del;
					del = NULL;
					return true;
				}
				
			}
		}
	}

};