#include "Fun.h"

int changefun;
void Menu() // ������� ����, ������� ���i� i�������i�.
{
	cout << "����:" << endl; 
	cout << "[1] - �������� ����� ���i����" << endl;
	cout << "[2] - ������� ������ � ��������" << endl;
	cout << "[3] - ���������� ����������" << endl;
	cout << "[4] - �������� ���� i�������i�" << endl;
	cout << "[5] - �������� ����������" << endl;
	cout << "[6] - ����� ����������" << endl;
	cout << "[7] - �������� ����������" << endl;
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

		case 3:
			system("cls");
			if (size != 0)
			{
				Change(d, size);
			}
			else
				cout << "���� ����" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");
			if (size != 0)
			{
				AddData(d, size);
			}
			else
				cout << "���� ����" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			if (size != 0)
			{
				Delete(d, size);
			}
			else
				cout << "���� ����" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			if (size != 0)
			{
				SearchData(d, size);
			}
			else
				cout << "���� ����" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");

			if (size != 0)
			{
				cout << "������ ����� �����: ";
				cin >> file;

				Save(d, size, file);
			}
			else
				cout << "���� ����" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "������ ����� �� ����!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}

	system("cls");
	cout << "��������� ���������" << endl;
	system("pause");
}