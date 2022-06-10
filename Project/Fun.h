#include "Data.h";


void DataEntry(Data* (&d), int& n); // введення данних 
void DataRead(Data* (&d), int& n, string file); // читання данних з файлу
void Printer(Data* d, int n); // виведення данних в консоль
void Change(Data* d, int n); // зміна данних
