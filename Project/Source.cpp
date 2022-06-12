#include "Fun.h"

int changefun;
void Menu() // Початок меню, простий вивiд iнформацiї.
{
	cout << "Меню:" << endl; 
	cout << "[1] - Створити новий довiдник" << endl;
	cout << "[2] - Вивести компанiї з довiдника" << endl;
	cout << "[3] - Редагувати iнформацiю" << endl;
	cout << "[4] - Добавити нову iнформацiю" << endl;
	cout << "[5] - Видалити iнформацiю" << endl;
	cout << "[6] - Пошук iнформацiї" << endl;
	cout << "[7] - Зберегти iнформацiю" << endl;
	cout << "[0] - Вихiд" << endl;
	cout << "Виберiть дiю: ";
	cin >> changefun;
}

int main() {
	setlocale(LC_ALL, "Russian");

	Menu();

	int size = 0; // розмiр данних

	int change;
	string file;

	Data* d = new Data[size]; // Data вказує на массив данних i передає даннi iншому масиву данних

	while (changefun !=0)
	{
		switch (changefun) {
		case 1:
			system("cls");
			cout << "[1] - Заповнити самостiйно " << endl;
			cout << "[2] - Прочитати з файлу" << endl;
			cin >> change;

			if (change == 1) {
				DataEntry(d, size);
			}
			else
			{
				cout << "Введiть назву файлу: ";
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
				cout << "Даннi пустi" << endl;

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
				cout << "Даннi пустi" << endl;

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
				cout << "Даннi пустi" << endl;

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
				cout << "Даннi пустi" << endl;

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
				cout << "Даннi пустi" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");

			if (size != 0)
			{
				cout << "Введiть назву файлу: ";
				cin >> file;

				Save(d, size, file);
			}
			else
				cout << "Даннi пустi" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "Такого пунка не iснує!" << endl;
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