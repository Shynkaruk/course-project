#include "Fun.h"

void DataEntry(Data* &d, int& n)
{
	// �������� ��������
	Company company;
	Director director;
	Place place;
	Reg reg;
	Capital capital;
	Category cat;

	int changecat;

	cout << "������ ������ ������� �� ������ ��������: ";
	cin >> n;

	d = new Data[n]; // �������� ����� ��� ������� ������

	for (int i = 0; i < n; i++) {
		cout << "������� �������� ������ :";
		cout << "[1] - ������� �������, [2] - ���������, [3] - �����������." << endl;
		cin >> cat.category;
		switch (changecat) {
		case 1:
			cat.category = "������� �������";
		case 2: 
			cat.category = "���������";
		case 3: 
			cat.category = "�����������";
		}
		cout << "������ ����� ������: " << company.title << endl;
		cout << "������ ����� �������� ������" << company.phone_comp << endl;

		cout << "������ ϲ� ���������: " << endl;
		cin >> director.name >>  director.lastname >> director.surname;
		cout << "������ ����� �������� ���������: ";
		cin >> director.phone;

		cout << "������ ���� �����������: " << endl;
		cout << "̳���: ";
		cin >> place.city;
		cout << "������: ";
		cin >> place.street;
		cout << "����� ������: ";
		cin >> place.num_street;

		cout << "������ ���� �����������: " << endl;
		cout << "����";
		cin >> reg.day;
		cout << "̳����:";
		cin >> reg.month;
		cout << "г�: ";
		cin >> reg.year;

		cout << "������ ���������� ������ ������: ";
		cin >> capital.start_capital;
		cout << "������ �������� �� �������: ";
		cin >> capital.profit;

		// ���������� ������ � ������� �������
		d[i].DataEntry(company, director, place, cat, reg, capital);

		cout << "###########################################################" << endl;
	}
}

void DataRead(Data* (&d), int& n, string file)
{
	ifstream reading(file);

	if (reading) {
		// ��������� �������
		Company company; /* �������� �������� - �� �� ��� �������� ������ �� ��� ������� ������� */
		Director director;
		Place place;
		Reg reg;
		Capital capital;
		Category cat;

		reading >> n; // ������� ���������

		d = new Data[n];
		for (int i = 0; i < n; i++)
		{
			reading >> cat.category;

			reading >> company.title;
			reading >> company.phone_comp;

			reading >> director.lastname >> director.name >> director.surname;
			reading >> director.phone;

			reading >> place.city >> place.street >> place.num_street;
			reading >> reg.day >> reg.month >> reg.year;

			reading >> capital.start_capital;
			reading >> capital.profit;

			d[i].DataEntry(company, director, place, cat, reg, capital);
		}
		cout << "���� ����������" << endl;
	}
	else
		cout << "������� ������� �����" << endl;

	reading.close();
}

void Printer(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "������� �" << i + 1 << endl;
		d[i].Printer();
		cout << "###########################################################" << endl;
	}
}

void Change(Data* d, int n)
{
	// ��������� �������
	Company company; /* �������� �������� - �� �� ��� �������� ������ �� ��� ������� ������� */
	Director director;
	Place place;
	Reg reg;
	Capital capital;
	Category cat;
	int num;
	int changecat; 

	cout << "������ ����� ������ (�� 1 �� " << n <<  "): ";
	cin >> num;
	num--;

	if (num >= 0 && num < n)
	{
		cout << "������� �������� ������ :";
		cout << "[1] - ������� �������, [2] - ���������, [3] - �����������." << endl;
		cin >> cat.category;
		switch (changecat) {
		case 1:
			cat.category = "������� �������";
		case 2:
			cat.category = "���������";
		case 3:
			cat.category = "�����������";
		}
		cout << "������ ���� ����� ������: " << company.title << endl;
		cout << "������ ����� ����� �������� ������" << company.phone_comp << endl;

		cout << "������ ����� ϲ� ���������: " << endl;
		cin >> director.name >> director.lastname >> director.surname;
		cout << "������ ����� ����� �������� ���������: ";
		cin >> director.phone;

		cout << "������ ���� ���� �����������: " << endl;
		cout << "̳���: ";
		cin >> place.city;
		cout << "������: ";
		cin >> place.street;
		cout << "����� ������: ";
		cin >> place.num_street;

		cout << "������ ���� ���� �����������: " << endl;
		cout << "����";
		cin >> reg.day;
		cout << "̳����:";
		cin >> reg.month;
		cout << "г�: ";
		cin >> reg.year;

		cout << "������ ����� ���������� ������ ������: ";
		cin >> capital.start_capital;
		cout << "������ ����� �������� �� �������: ";
		cin >> capital.profit;

		// ���������� ������ � ������� �������
		d[num].DataEntry(company, director, place, cat, reg, capital);
	}
}

void Copy(Data* per, Data* per_0, int n)  // per - ������ ������. per_0 - ������ � �������.
{
	for (int i = 0; i < n; i++) {
		per[i] = per_0[i];
	}
}

void SearchData(Data*& d, int& n)
{
	Company company; /* �������� �������� - �� �� ��� �������� ������ �� ��� ������� ������� */
	Director director;
	Place place;
	Reg reg;
	Capital capital;
	Category cat;
	int num;
	int changecat;

	cout << "������ ����� ������ (�� 1 �� " << n << "): ";
	cin >> num;
	num--;

	for (int i = 0; i < n; i++) {
		if (num >= 0 && num < n)
		{
			cout << "������� �" << i + 1 << endl;
			d[i].Printer();
			cout << "###########################################################" << endl;
		}
	}
}

void Save(Data* d, int n, string file)
{
	ofstream record(file);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			record << d[i].Cat().category;

			record << d[i].GetCompany().title;
			record << d[i].GetCompany().phone_comp;

			record << d[i].GetDirector().lastname << d[i].GetDirector().name << d[i].GetDirector().surname;
			record << d[i].GetDirector().phone;

			record << d[i].GetPlace().city << d[i].GetPlace().street << d[i].GetPlace().num_street;
			record << d[i].Reg_date().day << d[i].Reg_date().month << d[i].Reg_date().year;

			record << d[i].Cap().start_capital;
			record << d[i].Cap().profit;

			if (i < n - 1)
				record << endl;

		}
	}
	else
		cout << "������� ���������� ������" << endl;

	record.close();
}

void AddData(Data*& d, int& n)
{
	Company company;
	Director director;
	Place place;
	Reg reg;
	Capital capital;
	Category cat;

	int changecat;
	Data* buffer = new Data[n]; // ���������� ������ ���� �� ������ ������������� ��� ������ ���� ����������
	int s = n, new_size = ++n;

	Copy(buffer, d, s); // ���� �� �������� � ������ � ������� - s.

	d = new Data[new_size]; // �������� ������ �� ������� �����

	Copy(d, buffer, s); // � ������ �� �������� ���� � ��������� ������

	cout << "������� �������� ������ :";
	cout << "[1] - ������� �������, [2] - ���������, [3] - �����������." << endl;
	cin >> cat.category;
	switch (changecat) {
	case 1:
		cat.category = "������� �������";
	case 2:
		cat.category = "���������";
	case 3:
		cat.category = "�����������";
	}
	cout << "������ ���� ����� ������: " << company.title << endl;
	cout << "������ ����� ����� �������� ������" << company.phone_comp << endl;

	cout << "������ ����� ϲ� ���������: " << endl;
	cin >> director.name >> director.lastname >> director.surname;
	cout << "������ ����� ����� �������� ���������: ";
	cin >> director.phone;

	cout << "������ ���� ���� �����������: " << endl;
	cout << "̳���: ";
	cin >> place.city;
	cout << "������: ";
	cin >> place.street;
	cout << "����� ������: ";
	cin >> place.num_street;

	cout << "������ ���� ���� �����������: " << endl;
	cout << "����";
	cin >> reg.day;
	cout << "̳����:";
	cin >> reg.month;
	cout << "г�: ";
	cin >> reg.year;

	cout << "������ ����� ���������� ������ ������: ";
	cin >> capital.start_capital;
	cout << "������ ����� �������� �� �������: ";
	cin >> capital.profit;

	// ���������� ������ � ������� ������� � ����� �������� �������
	d[s].DataEntry(company, director, place, cat, reg, capital);
	delete[]buffer;
}

void Delete(Data*& d, int& n)
{
	int num;
	Data* buffer = new Data[n];
	int changecat;

	cout << "������ ����� ������ (�� 1 �� " << n << "): ";
	cin >> num;
	num--;
	if (num >= 0 && num < n) {
		Copy(buffer, d, n); // �������� ������� d ������������ � ������ buffer
		int r = 0;
		n--;

		d = new Data[n]; // ��������� ������ ������
		for (int i = 0; i < n; i++) {
			if (i != num) {
				d[r] = buffer[i]; // �������� �� ��� �� ������ �� �������� � ������ � ����� ����� ������������ ����
				r++; // ����� �� ������� d;
			}
		}
		cout << "������� � ������ ��������" << endl;
	}
	else
		cout << "����� ������ �� ������ �� ����" << endl;
	delete[]buffer;

}

