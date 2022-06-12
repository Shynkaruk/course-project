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

void Change(Data* d, int n)
{
	// Тимчасовы перемінні
	Company company; /* Тимчасові переменні - ми під них виділяємо память під час виклмку функції */
	Director director;
	Place place;
	Reg reg;
	Capital capital;
	Category cat;
	int num;
	int changecat; 

	cout << "Введіть номер компанії (від 1 до " << n <<  "): ";
	cin >> num;
	num--;

	if (num >= 0 && num < n)
	{
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
		cout << "Введіть нову назву компанії: " << company.title << endl;
		cout << "Введіть новий номер телефону компанії" << company.phone_comp << endl;

		cout << "Введіть новий ПІБ керуючого: " << endl;
		cin >> director.name >> director.lastname >> director.surname;
		cout << "Введіть новий номер телефону керуючого: ";
		cin >> director.phone;

		cout << "Введіть нове місце регестрації: " << endl;
		cout << "Місто: ";
		cin >> place.city;
		cout << "Вулиця: ";
		cin >> place.street;
		cout << "Номер вулиці: ";
		cin >> place.num_street;

		cout << "Введіть нову дату регестрації: " << endl;
		cout << "День";
		cin >> reg.day;
		cout << "Місяць:";
		cin >> reg.month;
		cout << "Рік: ";
		cin >> reg.year;

		cout << "Введіть новий початковий капітал компанії: ";
		cin >> capital.start_capital;
		cout << "Введіть новий прибуток за квартал: ";
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
	Company company; /* Тимчасові переменні - ми під них виділяємо память під час виклмку функції */
	Director director;
	Place place;
	Reg reg;
	Capital capital;
	Category cat;
	int num;
	int changecat;

	cout << "Введіть номер компанії (від 1 до " << n << "): ";
	cin >> num;
	num--;

	for (int i = 0; i < n; i++) {
		if (num >= 0 && num < n)
		{
			cout << "Компанія №" << i + 1 << endl;
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
	Data* buffer = new Data[n]; // Тимчасовий массив яким ми будемо користуватися для запису нової інформації
	int s = n, new_size = ++n;

	Copy(buffer, d, s); // Данні ми зберігаємо в буффер з розміром - s.

	d = new Data[new_size]; // виділяємо память на одиницю більше

	Copy(d, buffer, s); // з буферу ми зберігаємо данні в динамічний массив

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
	cout << "Введіть нову назву компанії: " << company.title << endl;
	cout << "Введіть новий номер телефону компанії" << company.phone_comp << endl;

	cout << "Введіть новий ПІБ керуючого: " << endl;
	cin >> director.name >> director.lastname >> director.surname;
	cout << "Введіть новий номер телефону керуючого: ";
	cin >> director.phone;

	cout << "Введіть нове місце регестрації: " << endl;
	cout << "Місто: ";
	cin >> place.city;
	cout << "Вулиця: ";
	cin >> place.street;
	cout << "Номер вулиці: ";
	cin >> place.num_street;

	cout << "Введіть нову дату регестрації: " << endl;
	cout << "День";
	cin >> reg.day;
	cout << "Місяць:";
	cin >> reg.month;
	cout << "Рік: ";
	cin >> reg.year;

	cout << "Введіть новий початковий капітал компанії: ";
	cin >> capital.start_capital;
	cout << "Введіть новий прибуток за квартал: ";
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

	cout << "Введіть номер компанії (від 1 до " << n << "): ";
	cin >> num;
	num--;
	if (num >= 0 && num < n) {
		Copy(buffer, d, n); // елементи массива d перезаписуємо в массив buffer
		int r = 0;
		n--;

		d = new Data[n]; // створюємо пустий массив
		for (int i = 0; i < n; i++) {
			if (i != num) {
				d[r] = buffer[i]; // елементи які нам не потрібні ми зберігаємо в буффер і таким чином перезаписуємо данні
				r++; // бігаємо по массиву d;
			}
		}
		cout << "Компанія зі списку видалена" << endl;
	}
	else
		cout << "Такоъ компанії по номеру не існує" << endl;
	delete[]buffer;

}

