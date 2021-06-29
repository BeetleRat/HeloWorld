#include"Time.h"

Matr::Matr() // Конструктор
{
	sch = 1;
	n = 0; // Высота птички
	Zero(); // Обнуление матрицы	
}

void Matr::Zero() // Обнуление матрицы
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			matrix[i][j] = 0;
		}
	}
	matrix[n][49] = 1; // Добавляем птичку
}

void Matr::StepForward()// Перерисовка матриы на шаг вперед
{
	sch++; // Увеличиваем текущий счет игрока
	for (int i = 19; i >= 0; i--)
	{
		for (int j = 0; j < 99; j++)
		{
			if (matrix[i][j + 1] == 1) // Если следующий элемент на той же высоте закрашен, 
			{
				// Сдвиг на один элемент
				matrix[i][j + 1] = 0; // Обнуляем следующий элемент
				matrix[i][j] = 1; // Закрашиваем текущий
			}
		}
	}
}

int Matr::Tack(int t)// Сдвиг матрицы (t-смещение птички по высоте)
{
	if ((n >= 19)&&t>0) // Если птичка на максимальной высоте и делает прыжек
	{
		t = 19 - n; // Высота прыжка равняется той, которой птичке не хватает до максимума до максимума(при добавлении этой высоты к текущей высоте птички результат будет равен 19)
	}
	if ((n <= 0)&&t<0) // Если текущая высота 0 и птичка падает
	{
		t = 0; // Высота падения равна 0
	}
	if (matrix[n + t][50] == 1) // Если в месте, в которое переместиться птичка на следующем кадре, стена(элемент закрашен)
	{
		Zero(); // Обнулить матрицу
		sch = 1; // Обнуляем текущий счет
		return 0; // Вернуть игровой счет 0(птичка врезалась игра окончена)
	}
	// Если птичка не врежиться на следующем кадре
	StepForward();// Перересовываем матрицу
	// Перерисовываем птичка
	matrix[n][48] = 0; // После перерисовки матрицы, птичка съехала на один элемент назад, обнуляем его
	n = n + t; // Задаем новую высоту птички
	matrix[n][49] = 1; // Закрашиваем элемент, в котором сейчас находится птичка

	return sch;// Возвращаем текущий счет
}

void Matr::Walls() // Добавление стены
{
	int G; // Высота стены
	G = rand() % 12; // Случайная высота от 0-11 нижней стены
		// Добавление нижней стены в конец матрицы
	for (int i = 0; i < G; i++)
	{
		matrix[i][99] = 1;
	}
		// Добавление верхней стены в конец матрицы. Свободное место между стенами 7
	for (int i = G+7; i < 20; i++)
	{
		matrix[i][99] = 1;
	}
}

void Matr::OutPut() // Отрисовка матрицы
{
	for (int i = 19; i >= 0; i--)
	{
		for (int j = 0; j < 100; j++)
		{
			if (matrix[i][j] == 1) // Если текущий элемент закрашен
			{
				cout << "*"; // Рисуем звездочку
			}
			if (matrix[i][j] == 0) //Если текущий элемент пуст
			{
				cout << " "; // Рисуем пробел
			}
		}
		cout << endl; //Спускаемся для отрисовки следующей строчки
	}
}
