#include "Data.h"

Data::Data()
{
	company.title = "";
	company.phone_comp = 0;

	director.name = ""; // імя
	director.lastname = ""; // призвіще
	director.surname = ""; // по-батькові

	place.city = ""; // місто
	place.street = ""; // вулиця
	place.num_street = 0; // номер вулиці

	cat.category = "";

	reg.day = 0;
	reg.month = 0;
	reg.year = 0;

	capital.start_capital = 0;
	capital.profit = 0;
  
}

Data::Data(Company _company, Director _director, Place _place, Category _cat, Reg _reg, Capital _capital)
{
	company.title = _company.title;
	company.phone_comp = _company.phone_comp;


	director.name = _director.name;
	director.lastname = _director.lastname; 
	director.surname = _director.surname;
	
	place.city = _place.city;
	place.street = _place.street;
	place.num_street = _place.num_street;

	cat.category = _cat.category;

	reg.day = _reg.day;
	reg.month = _reg.month;
	reg.year = _reg.year;

	capital.start_capital = _capital.start_capital;
	capital.profit = _capital.profit;
}

Data::~Data()
{
}

void Data::Printer()
{
	cout << "Компанія: " << company.title << "Телефон: " << company.title << endl;
	cout << "Керуючий: " << director.name << " " << director.lastname << " " << director.surname << endl;
	cout << "Номер телефону керуючого: " << director.phone << endl;
	cout << "Місце регестрації: " << place.city << "," << place.street << "," << place.num_street;
	cout << "Дата регестрації: " << reg.day << "." << reg.month << "." << reg.year << endl;
	cout << "Стартовий капітал: " << capital.start_capital << "$ " << "Прибуток в місяць: " << capital.profit << "$" << endl;
}

void Data::Datainput(Company _company, Director _director, Place _place, Category _cat, Reg _reg, Capital _capital)
{
	company.title = _company.title;
	company.phone_comp = _company.phone_comp;


	director.name = _director.name;
	director.lastname = _director.lastname;
	director.surname = _director.surname;

	place.city = _place.city;
	place.street = _place.street;
	place.num_street = _place.num_street;

	cat.category = _cat.category;

	reg.day = _reg.day;
	reg.month = _reg.month;
	reg.year = _reg.year;

	capital.start_capital = _capital.start_capital;
	capital.profit = _capital.profit;
}

Data& Data::operator=(Data per)
{
	this->company.title = per.company.title;
	this->company.phone_comp = per.company.phone_comp;


	this->director.name = per.director.name;
	this->director.lastname = per.director.lastname;
	this->director.surname = per.director.surname;

	this->place.city = per.place.city;
	this->place.street = per.place.street;
	this->place.num_street = per.place.num_street;

	this->cat.category = per.cat.category;

	this->reg.day = per.reg.day;
	this->reg.month = per.reg.month;
	this->reg.year = per.reg.year;

	this->capital.start_capital = per.capital.start_capital;
	this->capital.profit = per.capital.profit;

	return *this;
}

