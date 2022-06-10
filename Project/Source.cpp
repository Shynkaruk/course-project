#include "Data.h"

int changefun;
void Menu() // Початок меню, простий вивiд iнформацiї.
{
	cout << "Меню:" << endl; 
	cout << "[0] - Створити новий довiдник" << endl;
	cout << "[1] - Вивести довiдник" << endl;
	cout << "[2] - Редагувати довiдник" << endl;
	cout << "[3] - Видалити довiдник" << endl;
	cout << "[4] - Добавити нову iнформацiю" << endl;
	cout << "[5] - Зберiгти довiдник" << endl;
	cout << "[10] - Вихiд" << endl;
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
		}
	}
}