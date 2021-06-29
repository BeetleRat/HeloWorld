#include <iostream>
#include<Windows.h>
#include <conio.h>
#include"Time.h"

using namespace std;

// Скрытие консольной "каретки"
void UnSeeCursor() 
{
	CONSOLE_CURSOR_INFO curs = { 0 };
	curs.dwSize = sizeof(curs);
	curs.bVisible = FALSE;
	::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);
}

void SadMenu(const int& Sch) // Вывод сообщения о проигрыше
{
	for (int i = 8; i >= 0; i--)
	{
		cout << endl;
	}
	for (int i = 0; i < 50; i++)
	{
		cout << " ";
	}
	cout << "Вы проиграли(((" << endl;
	for (int i = 0; i < 50; i++)
	{
		cout << " ";
	}
	cout << "Ваш счет: " << Sch << endl;
}

int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода (работа с русским текстом)
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода (работа с русским текстом)
	srand(static_cast<unsigned int>(time(0))); // Устанавливаем значение системных часов в качестве стартового числа для функции rand()
	Matr Flip; // Объект класса матрицы отрисовки
	int sch = 1, Sch; // Счет в текущем кадре и счет для вывода.
	UnSeeCursor(); // Скрытие консольной "каретки"
	bool L = true; // Игра идет
	
	while (true) // Цикл отрисовки
	{
		system("cls"); // Очистка консоли
		if (L) // Если игра идет
		{
			sch++; // Увеличиваем счет игрока			
			if (_kbhit()) // Если была нажата любая клавиша
			{
				sch = Flip.Tack(3, sch); // Прыжек на три строчки вверх
				while (_kbhit()) _getch(); // Ждем оканчания нажатия клавиш(что б птичка не прыгала несколько раз за один кадр)
			}
			else
			{
				sch = Flip.Tack(-1, sch); // Падение на одну строчку вниз
			}

			if (sch % 10 == 0) // Каждый десятый кадр
			{
				Flip.Walls(); // Создание стены
			}

			Flip.OutPut(); // Отрисовка изображения

			if (sch == 0) // Если после прыжка/падения птичка попала в стену
				L = false; // Закончить игру
			else
				Sch = sch; // Сохранить новый счет для вывода

			cout << "Счет: " << Sch;
		}
		else // Если игра закончилать
		{
			if (_kbhit()) // Ессли нажата любая клавиша
			{
				L = true; // Начать игру
				sch = 1; // Обнулить счет игрока 
				while (_kbhit()) _getch(); // Ожидание конца нажатия клавиш(что бы птичка была на земле в момент начала игры)
			}
			else
			{
				SadMenu(Sch); // Вывод сообщения о проигрыше
			}
		}
	}
}