#include "Data.h";

	void DataEntry(Data*& d, int& n); // введення данних 
	void DataRead(Data* (&d), int& n, string file); // читання данних з файлу
	void Printer(Data* d, int n); // виведення данних в консоль
	void Change(Data* d, int n); // зміна данних
	void AddData(Data* &d, int& n); // додавання данних 
	void Delete(Data* &d, int &n); // видалення данних
	void Copy(Data* per, Data* per_0, int n);
	void SearchData(Data*& d, int& n);
	void Save(Data* d, int n, string file);