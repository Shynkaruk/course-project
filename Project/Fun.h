#include "Data.h";

	void DataEntry(Data*& d, int& n); // �������� ������ 
	void DataRead(Data* (&d), int& n, string file); // ������� ������ � �����
	void Printer(Data* d, int n); // ��������� ������ � �������
	void Change(Data* d, int n); // ���� ������
	void AddData(Data* &d, int& n); // ��������� ������ 
	void Delete(Data* &d, int &n); // ��������� ������
	void Copy(Data* per, Data* per_0, int n);
	void SearchData(Data*& d, int& n);
	void Save(Data* d, int n, string file);