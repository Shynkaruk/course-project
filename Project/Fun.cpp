#include "Fun.h"

void DataEntry(Data* &d, int& n)
{
	// тимчасовi переменнi
	Company company;
	Director director;
	Place place;
	Reg reg;
	Capital capital;
	Category cat;

	int changecat;

	cout << "Введiть скiльки шаблонiв ви хочете добавити: ";
	cin >> n;

	d = new Data[n]; // видiлення памятi для массива данних

	for (int i = 0; i < n; i++) {
		cout << "Виберiть категорiю компанiї :";
		cout << "[1] - Юридичнi послуги, [2] - Бугалтерiя, [3] - Розважальна." << endl;
		cin >> changecat;
		switch (changecat) {
		case 1:
			cat.category = "Юридичнi послуги";
		case 2: 
			cat.category = "Бугалтерiя";
		case 3: 
			cat.category = "Розважальна";
		}
		cout << "Введiть назву компанiї: " << company.title << endl;
		cout << "Введiть номер телефону компанiї" << company.phone_comp << endl;

		cout << "Введiть ПiБ керуючого: " << endl;
		cin >> director.name >>  director.lastname >> director.surname;
		cout << "Введiть номер телефону керуючого: ";
		cin >> director.phone;

		cout << "Введiть мiсце регестрацiї: " << endl;
		cout << "Мiсто: ";
		cin >> place.city;
		cout << "Вулиця: ";
		cin >> place.street;
		cout << "Номер вулицi: ";
		cin >> place.num_street;

		cout << "Введiть дату регестрацiї: " << endl;
		cout << "День";
		cin >> reg.day;
		cout << "Мiсяць:";
		cin >> reg.month;
		cout << "Рiк: ";
		cin >> reg.year;

		cout << "Введiть початковий капiтал компанiї: ";
		cin >> capital.start_capital;
		cout << "Введiть прибуток за квартал: ";
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
		// Тимчасовы перемiннi
		Company company; /* Тимчасовi переменнi - ми пiд них видiляємо память пiд час виклмку функцiї */
		Director director;
		Place place;
		Reg reg;
		Capital capital;
		Category cat;

		reading >> n; // кiлькiсть перемiнних

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
		cout << "Компанiя №" << i + 1 << endl;
		d[i].Printer();
		cout << "###########################################################" << endl;
	}
}

void Change(Data* d, int n)
{
	// Тимчасовы перемiннi
	Company company; /* Тимчасовi переменнi - ми пiд них видiляємо память пiд час виклмку функцiї */
	Director director;
	Place place;
	Reg reg;
	Capital capital;
	Category cat;
	int num;
	int changecat; 

	cout << "Введiть номер компанiї (вiд 1 до " << n <<  "): ";
	cin >> num;
	num--;

	if (num >= 0 && num < n)
	{
		cout << "Виберiть категорiю компанiї :";
		cout << "[1] - Юридичнi послуги, [2] - Бугалтерiя, [3] - Розважальна." << endl;
		cin >> changecat;
		switch (changecat) {
		case 1:
			cat.category = "Юридичнi послуги";
		case 2:
			cat.category = "Бугалтерiя";
		case 3:
			cat.category = "Розважальна";
		}
		cout << "Введiть нову назву компанiї: " << company.title << endl;
		cout << "Введiть новий номер телефону компанiї" << company.phone_comp << endl;

		cout << "Введiть новий ПiБ керуючого: " << endl;
		cin >> director.name >> director.lastname >> director.surname;
		cout << "Введiть новий номер телефону керуючого: ";
		cin >> director.phone;

		cout << "Введiть нове мiсце регестрацiї: " << endl;
		cout << "Мiсто: ";
		cin >> place.city;
		cout << "Вулиця: ";
		cin >> place.street;
		cout << "Номер вулицi: ";
		cin >> place.num_street;

		cout << "Введiть нову дату регестрацiї: " << endl;
		cout << "День";
		cin >> reg.day;
		cout << "Мiсяць:";
		cin >> reg.month;
		cout << "Рiк: ";
		cin >> reg.year;

		cout << "Введiть новий початковий капiтал компанiї: ";
		cin >> capital.start_capital;
		cout << "Введiть новий прибуток за квартал: ";
		cin >> capital.profit;

		// введенення данних в елемент массива
		d[num].DataEntry(company, director, place, cat, reg, capital);
	}
}

void Copy(Data* per, Data* per_0, int n)  // per - пустий массив. per_0 - массив з данними.
{
	for (int i = 0; i < n; i++) {
		per[i] = per_0[i];
	}
}

void SearchData(Data*& d, int& n)
{
	Company company; /* Тимчасовi переменнi - ми пiд них видiляємо память пiд час виклмку функцiї */
	Director director;
	Place place;
	Reg reg;
	Capital capital;
	Category cat;
	int num;
	int changecat;

	cout << "Введiть номер компанiї (вiд 1 до " << n << "): ";
	cin >> num;
	num--;

	for (int i = 0; i < n; i++) {
		if (num >= 0 && num < n)
		{
			cout << "Компанiя №" << i + 1 << endl;
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
		cout << "Помилка збереження данних" << endl;

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
	Data* buffer = new Data[n]; // Тимчасовий массив яким ми будемо користуватися для запису нової iнформацiї
	int s = n, new_size = ++n;

	Copy(buffer, d, s); // Даннi ми зберiгаємо в буффер з розмiром - s.

	d = new Data[new_size]; // видiляємо память на одиницю бiльше

	Copy(d, buffer, s); // з буферу ми зберiгаємо даннi в динамiчний массив

	cout << "Виберiть категорiю компанiї :";
	cout << "[1] - Юридичнi послуги, [2] - Бугалтерiя, [3] - Розважальна." << endl;
	cin >> changecat;
	switch (changecat) {
	case 1:
		cat.category = "Юридичнi послуги";
	case 2:
		cat.category = "Бугалтерiя";
	case 3:
		cat.category = "Розважальна";
	}
	cout << "Введiть нову назву компанiї: " << company.title << endl;
	cout << "Введiть новий номер телефону компанiї" << company.phone_comp << endl;

	cout << "Введiть новий ПiБ керуючого: " << endl;
	cin >> director.name >> director.lastname >> director.surname;
	cout << "Введiть новий номер телефону керуючого: ";
	cin >> director.phone;

	cout << "Введiть нове мiсце регестрацiї: " << endl;
	cout << "Мiсто: ";
	cin >> place.city;
	cout << "Вулиця: ";
	cin >> place.street;
	cout << "Номер вулицi: ";
	cin >> place.num_street;

	cout << "Введiть нову дату регестрацiї: " << endl;
	cout << "День";
	cin >> reg.day;
	cout << "Мiсяць:";
	cin >> reg.month;
	cout << "Рiк: ";
	cin >> reg.year;

	cout << "Введiть новий початковий капiтал компанiї: ";
	cin >> capital.start_capital;
	cout << "Введiть новий прибуток за квартал: ";
	cin >> capital.profit;

	// введенення данних в елемент массива з новим розмыром массива
	d[s].DataEntry(company, director, place, cat, reg, capital);
	delete[]buffer;
}

void Delete(Data*& d, int& n)
{
	int num;
	Data* buffer = new Data[n];
	int changecat;

	cout << "Введiть номер компанiї (вiд 1 до " << n << "): ";
	cin >> num;
	num--;
	if (num >= 0 && num < n) {
		Copy(buffer, d, n); // елементи массива d перезаписуємо в массив buffer
		int r = 0;
		n--;

		d = new Data[n]; // створюємо пустий массив
		for (int i = 0; i < n; i++) {
			if (i != num) {
				d[r] = buffer[i]; // елементи якi нам не потрiбнi ми зберiгаємо в буффер i таким чином перезаписуємо даннi
				r++; // бiгаємо по массиву d;
			}
		}
		cout << "Компанiя зi списку видалена" << endl;
	}
	else
		cout << "Такоъ компанiї по номеру не iснує" << endl;
	delete[]buffer;

}

