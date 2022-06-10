#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

	struct Company
	{
		string title;
		int phone_comp;
	};
	struct Director
	{
		string name;
		string lastname;
		string surname;
		int phone;
	};
	struct Place {
		string city;
		string street;
		int num_street;
	};
	struct Reg
	{
		int day;
		int month;
		int year;
	};
	struct Capital {
		int start_capital;
		int profit;
	};

	struct Category {
		string category;
	};

	class Data
	{
	private: 
		// Обєкти данних
		Company company;
		Director director;
		Place place;
		Reg reg;
		Capital capital;
		Category cat;
		// Обєкти данних
	public:
		Data(); // конструктор по замовчуванні
		Data(Company _company, Director _director, Place _place, Category _cat, Reg _reg, Capital _capital); // Конструктор з параметрами
		~Data(); // Деструктор

		void Printer(); // вивід в консоль
		void Datainput(Company _company, Director _director, Place _place, Category _cat, Reg _reg, Capital _capital); // ввід данних в консолі

		Company GetCompany() { return company; };
		Director GetDirector() { return director; };
		Place GetPlace() { return place; };
		Reg Reg_date() { return reg; };
		Capital Cap() { return capital; };
		Data& operator = (Data per);
	};