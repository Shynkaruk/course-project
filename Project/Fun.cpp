#include "Fun.h"

void DataEntry(Data* &d, int& n)
{
	// тимчасові переменні
	Company company;
	Director director;
	Place place;
	Reg reg;
	Capital capital;
	Category cat;

	int changecat;

	cout << "Введіть скільки шаблонів ви хочете добавити: ";
	cin >> n;

	d = new Data[n]; // виділення памяті для массива данних

	for (int i = 0; i < n; i++) {
		cout << "Виберіть категорію компанії :";
		cout << "[1] - Юридичні послуги, [2] - Бугалтерія, [3] - Розважальна." << endl;
		cin >> cat.category;
		switch (changecat) {
		case 1:
			cat.category = "Юридичні послуги";
		case 2: 
			cat.category = "Бугалтерія";
		case 3: 
			cat.category = "Розважальна";
		}
		cout << "Введіть назву компанії: " << company.title << endl;
		cout << "Введіть номер телефону компанії" << company.phone_comp << endl;

		cout << "Введіть ПІБ керуючого: " << endl;
		cin >> director.name >>  director.lastname >> director.surname;
		cout << "Введіть номер телефону керуючого: ";
		cin >> director.phone;

		cout << "Введіть місце регестрації: " << endl;
		cout << "Місто: ";
		cin >> place.city;
		cout << "Вулиця: ";
		cin >> place.street;
		cout << "Номер вулиці: ";
		cin >> place.num_street;

		cout << "Введіть дату регестрації: " << endl;
		cout << "День";
		cin >> reg.day;
		cout << "Місяць:";
		cin >> reg.month;
		cout << "Рік: ";
		cin >> reg.year;

		cout << "Введіть початковий капітал компанії: ";
		cin >> capital.start_capital;
		cout << "Введіть прибуток за квартал: ";
		cin >> capital.profit;

		// введенення данних в елемент массива
		d[i].DataEntry(company, director, place, cat, reg, capital);

		cout << "###########################################################" << endl;
	}
}

void DataRead(Data* (&d), int& n, string file)
{
	ifstream reading(file);

	if (reading) {
		// Тимчасовы перемінні
		Company company; /* Тимчасові переменні - ми під них виділяємо память під час виклмку функції */
		Director director;
		Place place;
		Reg reg;
		Capital capital;
		Category cat;

		reading >> n; // кількість перемінних

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
		cout << "Файл прочитаний" << endl;
	}
	else
		cout << "Помилка читання файла" << endl;

	reading.close();
}

void Printer(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Компанія №" << i + 1 << endl;
		d[i].Printer();
		cout << "###########################################################" << endl;
	}
}
