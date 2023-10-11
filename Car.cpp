#include "Car.h"
Car::Car()
{
	cout << "----------------------------------\n ���������� ����������\n----------------------------------" << endl << endl;
	try
	{
		setType(3);
		cout << "������� ��� ������� ���������� = ";
		cin >> this->year;
		if (!this->year || this->year < 0)
		{
			throw (string)"��� ����� ���� ��� �����������";
		}
		cout << "������� ����� ���������� = ";
		cin.ignore(256, '\n');
		getline(cin, brand);
		if (brand == "")
			throw (string)"����� �� ����� ���� ������";
		cout << "������� ������ ���������� = ";
		getline(cin, model);
		if (model == "")
			throw (string)"������ �� ����� ���� ������";
		cout << "������� ����� �������� = ";
		getline(cin, city);
		if (city == "")
			throw (string)"����� �� ����� ���� ������";
		cout << "������� ����� �������� = ";
		cin >> this->time;
		if (!this->time || this->time < 0)
		{
			throw (string)"����� ����� ���� ��� ������������";
		}
		cout << "������� ����� ����� = ";
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
Car::Car(ifstream& fin)
{
	setType(3);
	fin >> this->year >> this->time >> this->volume;
	fin.ignore(256, '\n');
	getline(fin, brand);
	fin.ignore(256, '\n');
	getline(fin, model);
	fin.ignore(256, '\n');
	getline(fin, city);
}
Car::~Car()
{
	cout << "��� ������ ���������� ������ Car" << endl;
}
void Car::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "�������� �������� ��� ���������:" << endl
			<< "[1] ��� �������" << endl
			<< "[2] �����" << endl
			<< "[3] ������" << endl
			<< "[4] ����� ��������" << endl
			<< "[5] ����� ��������" << endl
			<< "[6] ����� �����" << endl
			<< "��� �����: ";
		cin >> index;
		if (index < 1 || index > 6)
		{
			throw (string)"��������� � ������ �������� �� ����������";
		}
		cout << "�������� ��������: ";
		switch (index)
		{
		case 1:

			cout << year << endl;
			cout << "����� ��������: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"��� ����� ���� ��� �����������";
			}
			year = iTmp;
			break;
		case 2:
			cout << brand << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"����� �� ����� ���� ������";
			brand = sTmp;
			break;
		case 3:
			cout << model << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"������ �� ����� ���� ������";
			model = sTmp;
			break;
		case 4:
			cout << city << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"����� �� ����� ���� ������";
			city = sTmp;
			break;
		case 5:
			cout << time << endl;
			cout << "����� ��������: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"����� ����� ���� ��� ������������";
			}
			time = iTmp;
			break;
		case 6:
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
void Car::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->year << endl
		<< this->brand << endl
		<< this->model << endl
		<< this->city << endl
		<< this->time << endl
		<< this->volume << endl;
}
void Car::print(ostream& out)
{
	out << "----------------------------------\n ����������\n----------------------------------" << endl
		<< "��� ������� : " << this->year << endl
		<< "����� : " << this->brand << endl
		<< "������ : " << this->model << endl
		<< "����� �������� : " << this->city << endl
		<< "����� �������� : " << this->time << endl
		<< "����� ����� : " << this->volume << endl;
}