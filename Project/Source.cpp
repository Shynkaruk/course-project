#include "Fun.h"

int changefun;
void Menu() // Початок меню, простий вивiд iнформацiї.
{
	cout << "Меню:" << endl; 
	cout << "[1] - Створити новий довiдник" << endl;
	cout << "[2] - Вивести компанії з довідника" << endl;
	cout << "[3] - Редагувати інформацію" << endl;
	cout << "[4] - Добавити нову iнформацiю" << endl;
	cout << "[5] - Видалити інформацію" << endl;
	cout << "[6] - Пошук інформації" << endl;
	cout << "[7] - Зберегти інформацію" << endl;
	cout << "[0] - Вихiд" << endl;
	cout << "Виберiть дiю: ";
	cin >> changefun;
}

void main() {
	setlocale(LC_ALL, "Russian");

	Menu();

	int size = 0; // розмір данних

	int change;
	string file;

	Data* d = new Data[size]; // Data вказує на массив данних і передає данні іншому масиву данних

	while (changefun !=0)
	{
		switch (changefun) {
		case 1:
			system("cls");
			cout << "[1] - Заповнити самостійно " << endl;
			cout << "[2] - Прочитати з файлу" << endl;
			cin >> change;

			if (change == 1) {
				DataEntry(d, size);
			}
			else
			{
				cout << "Введіть назву файлу: ";
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
				cout << "Данні пусті" << endl;

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
				cout << "Данні пусті" << endl;

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
				cout << "Данні пусті" << endl;

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
				cout << "Данні пусті" << endl;

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
				cout << "Данні пусті" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");

			if (size != 0)
			{
				cout << "Введіть назву файлу: ";
				cin >> file;

				Save(d, size, file);
			}
			else
				cout << "Данні пусті" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "Такого пунка не існує!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}

	system("cls");
	cout << "Программа завершена" << endl;
	system("pause");
}