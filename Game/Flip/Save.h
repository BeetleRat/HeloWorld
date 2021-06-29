#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

class Save // Класс работы с данными из файла
{
private:
	fstream File; // Переменная для работы с файлами
	string S; // Переменная для работы со строками
	pair<int, string> P; // Переменная для работы с парами рекорд - имя
	vector<pair<int, string>> V1; // Вектор пар рекорд - имя
	bool Permission; // Разрешение на работу функций
	int Min; // Минимальный рекорд

public:
	Save(); // Конструктор
	~Save();// Деструктор
	void SAVE(); // Сохранение таблицы рекордов
	void ShowRecord(); // Вывод списка рекордов
	void SetRecord(string, int); // Добавление нового рекорда
		// Геттеры
	int GetMin();


};