#pragma once
#include<ctime>
#include<iostream>
#include<string>

using namespace std;

class Matr // Класс отрисовки игрового изображения
{
	private:
		int matrix[20]; // Последний столбец
		int n; // Высота полета птички
		int sch; // Счет игрока
		string S[20]; // Матрица отрисовки
	public:
		Matr(); // Конструктор
		void Zero(); // Обнуление матрицы отрисовки
		int Tack(int); // Сдвиг матрицы (t-смещение птички по высоте)
		void Walls(); // Создание стены
		void OutPut(); // Отрисовка изображения
};