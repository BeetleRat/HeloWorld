#pragma once
#include<ctime>
#include<iostream>

using namespace std;

class Matr // Класс отрисовки игрового изображения
{
	private:
		int matrix[20][100]; // Матрица отрисовки
		int n; // Высота полета птички
	public:
		Matr(); // Конструктор
		void Zero(); // Обнуление матрицы отрисовки
		int Tack(int, int); // Сдвиг на один шаг вперед
		void OutPut(); // Отрисовка изображения
		void Walls(); // Создание стены
};