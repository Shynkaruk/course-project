#include "Fun.h"

int changefun;
void Menu() // ������� ����, ������� ���i� i�������i�.
{
	cout << "����:" << endl; 
	cout << "[1] - �������� ����� ���i����" << endl;
	cout << "[2] - ������� ������ � ��������" << endl;
	cout << "[3] - �������� ���i����" << endl;
	cout << "[4] - �������� ���� i�������i�" << endl;
	cout << "[5] - ����i��� ���i����" << endl;
	cout << "[0] - ���i�" << endl;
	cout << "�����i�� �i�: ";
	cin >> changefun;
}

void main() {
	setlocale(LC_ALL, "Russian");

	Menu();

	int size = 0; // ����� ������

	int change;
	string file;

	Data* d = new Data[size]; // Data ����� �� ������ ������ � ������ ���� ������ ������ ������

	while (changefun !=0)
	{
		switch (changefun) {
		case 1:
			system("cls");
			cout << "[1] - ��������� ��������� " << endl;
			cout << "[2] - ��������� � �����" << endl;
			cin >> change;

			if (change == 1) {
				DataEntry(d, size);
			}
			else
			{
				cout << "������ ����� �����: ";
				cin >> file;

				DataRead(d, size, file);
			}
			system("pause");
			Menu();
			break;
		case 2:
			system("cls");

			if (size != 0)
			{
				Printer(d, size);
			}
			else
				cout << "���� ����" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
}