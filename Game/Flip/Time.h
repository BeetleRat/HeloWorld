#pragma once
#include<ctime>
#include<iostream>

using namespace std;

class Matr // Класс отрисовки игрового изображения
{
	private:
		int matrix[20][100]; // Матрица отрисовки
		int n; // Высота полета птички
		int sch; // Счет игрока
	public:
		Matr(); // Конструктор
		void Zero(); // Обнуление матрицы отрисовки
		void StepForward(); // Перерисовка матриы на шаг вперед
		int Tack(int); // Сдвиг матрицы (t-смещение птички по высоте)
		void Walls(); // Создание стены
		void OutPut(); // Отрисовка изображения
};