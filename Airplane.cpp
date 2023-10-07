#include "Airplane.h"
Airplane::Airplane()
{
	cout << "----------------------------------\n ���������� ��������\n----------------------------------" << endl << endl;
	try
	{
		setType(1);
		cin.ignore(256, '\n');
		cout << "������� ��� �������� = ";
		getline(cin, this->type);
		if (type == "")
			throw (string)"��� �� ����� ���� ������";
		setError(false);
		cout << "������� ������������ �������� = ";
		getline(cin, this->name);
		if (name == "")
			throw (string)"������������ �� ����� ���� ������";
		setError(false);
		cout << "������� ����� ������������ ����� = ";
		cin >> this->volume;
		if (!this->volume || this->volume < 0)
		{
			throw (string)"����� ����� ���� ��� �����������";
		}
		cout << "������� �������� �������� = ";
		cin >> this->size;
		if (!this->size || this->size < 0)
		{
			throw (string)"�������� ����� ���� ��� ������������";
		}
		cout << "����� ������ �������� ������� = ";

		cin.ignore(256, '\n');
		getline(cin, this->city);
		if (city == "")
			throw (string)"������������ �� ����� ���� ������";
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}
Airplane::Airplane(ifstream& fin)
{
	setType(1);
	fin >> this->volume >> this->size;
	fin.ignore(256, '\n');
	getline(fin, type);
	fin.ignore(256, '\n');
	getline(fin, name);
	fin.ignore(256, '\n');
	getline(fin, city);
}
Airplane::~Airplane()
{
	cout << "��� ������ ���������� ������ Airplane" << endl;
	system("pause");
}
void Airplane::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "�������� �������� ��� ���������:" << endl
			<< "[1] ���" << endl
			<< "[2] ������������" << endl
			<< "[3] ����� �����" << endl
			<< "[4] ��������" << endl
			<< "[5] ������" << endl
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
			cout << type << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")

				throw (string)"��� �� ����� ���� ������";
			type = sTmp;
			break;
		case 2:
			cout << name << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"������������ �� ����� ���� ������";
			name = sTmp;
			break;
		case 3:
			cout << volume << endl;
			cout << "����� ��������: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"����� ����� ���� ��� �����������";
			}
			volume = iTmp;
			break;
		case 4:
			cout << size << endl;
			cout << "����� ��������: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"�������� ����� ���� ��� ������������";
			}
			size = iTmp;
			break;
		case 5:
			cout << city << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"������������ �� ����� ���� ������";
			city = sTmp;
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
void Airplane::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->type << endl
		<< this->name << endl
		<< this->volume << endl
		<< this->size << endl
		<< this->city << endl;
}
void Airplane::print(ostream& out)
{
	out << "----------------------------------\n ������� \n---------------------------------" << endl
		<< "��� �������� : " << type << endl
		<< "������������ �������� : " << name << endl
		<< "����� ������������ ����� : " << volume << endl
		<< "�������� : " << size << endl
		<< "������ : " << city << endl;
}
