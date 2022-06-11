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
