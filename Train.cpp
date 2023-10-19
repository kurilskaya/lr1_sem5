#include "Train.h"
Train::Train()
{
	cout << "----------------------------------\n ���������� ������\n----------------------------------" << endl << endl;
	try
	{

		setType(2);
		cout << "������� �������� ������ = ";
		cin.ignore(256, '\n');
		getline(cin, name);
		if (name == "")
			throw (string)"�������� �� ����� ���� ������";
		cout << "������� ��� ������� ������ = ";
		cin >> this->year;
		if (!this->year || this->year < 0)
		{
			throw (string)"��� ����� ���� ��� �����������";
		}
		cout << "������� ������� ���������� ������ = ";
		cin.ignore(256, '\n');
		getline(cin, route);
		if (route == "")
			throw (string)"������� �� ����� ���� ������";
		cout << "������� ���������� ������� = ";
		cin >> this->vagon;
		if (this->vagon < 0)
		{
			throw (string)"���������� ������� �� ����� ���� �������������";
		}
		cout << "������� ����� ������������ ����� = ";
		cin >> this->volume;
		if (!this->volume || this->volume < 0)
		{
			throw (string)"����� ����� ���� ��� �����������";
		}
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}
Train::Train(ifstream& fin)
{
	setType(2);
	fin.ignore(256, '\n');
	getline(fin, name);
	fin.ignore(256, '\n');
	getline(fin, route);
	fin >> this->year >> this->vagon >> this->volume;
}
Train::~Train()
{
	cout << "��� ������ ���������� ������ Train" << endl;
	system("pause");
}
void Train::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "�������� �������� ��� ���������:" << endl
			<< "[1] ��������" << endl
			<< "[2] ��� �������" << endl
			<< "[3] �������" << endl
			<< "[4] ���������� �������" << endl
			<< "[5] ����� ������������ �����" << endl
			<< "��� �����: ";
		cin >> index;
		if (index < 1 || index > 5)
		{
			throw (string)"��������� � ������ �������� �� ����������";
		}
		cout << "�������� ��������: ";
		switch (index)
		{
		case 1:
			cout << name << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"�������� �� ����� ���� ������";
			name = sTmp;
			break;
		case 2:
			cout << year << endl;
			cout << "����� ��������: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"��� ����� ���� ��� �����������";
			}
			year = iTmp;
			break;
		case 3:
			cout << route << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);

			if (sTmp == "")
				throw (string)"������� �� ����� ���� ������";
			route = sTmp;
			break;
		case 4:
			cout << vagon << endl;
			cout << "����� ��������: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"���������� ������� �� ����� ���� �������������";
			}
			vagon = iTmp;
			break;
		case 5:
			cout << volume << endl;
			cout << "����� ��������: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"����� ����� ���� ��� �����������";
			}
			volume = iTmp;
			break;
		default:
			break;
		}
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}
void Train::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->name << endl
		<< this->year << endl
		<< this->route << endl
		<< this->vagon << endl
		<< this->volume << endl;
}
void Train::print(ostream& out)
{
	out << "----------------------------------\n ����� \n----------------------------------" << endl
		<< "�������� : " << this->name << endl
		<< "��� ������� : " << this->year << endl
		<< "������� : " << this->route << endl
		<< "���������� ������� : " << this->vagon << endl
		<< "����� ����� : " << this->volume << endl;
}