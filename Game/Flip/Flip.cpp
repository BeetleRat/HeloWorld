#include <iostream>
#include<Windows.h>
#include <conio.h>
#include<fstream>
#include"Time.h"
#include"MainMenu.h"
#include"Save.h"

using namespace std;

// Скрытие консольной "каретки"
void UnSeeCursor() 
{
	CONSOLE_CURSOR_INFO curs = { 0 };
	curs.dwSize = sizeof(curs);
	curs.bVisible = FALSE;
	::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);
}

void SetRecord(Save& Records, int Rec) // Занести текущего участника в таблицу лидеров
{
	string S = "";
	for (int i = 8; i >= 0; i--)
	{
		cout << endl;
	}
	for (int i = 0; i < 45; i++)
	{
		S = S + " ";
	}
	cout << S << "Введите ваше имя: AAA\b\b\b"; // После вывода строки отводим каретку три раза назад, таким образом участник перепишет три буквы А
	getline(cin, S);
	while (S.length() < 3) // Если введено меньше трех символов
		S = S + "A"; // Добиваем до трех
	S.erase(3, S.length() - 3); // Удаляем все символы, кроме первых трех
	Records.SetRecord(S, Rec); // Заносим рекорд в таблицу рекордов
	Records.SAVE();
}

void SadMenu(Save & Records, const int& Sch) // Вывод сообщения о проигрыше
{
	string S = "";
	for (int i = 8; i >= 0; i--)
	{
		cout << endl;
	}
	for (int i = 0; i < 49; i++)
	{
		S = S + " ";
	}
	cout <<S<< "Вы проиграли(((" << endl;
	cout <<S<< " Ваш счет: " << Sch << endl;
	while (_getch() != 13/*Enter*/ && _getch() != 32/*Space*/)// Ждать нажатия пробела или Enter
	{
	}
	if (Records.GetMin() < Sch) // Если текущий счет больше минимального в таблице лидеров
		SetRecord(Records, Sch); //  Занести текущего участника в таблицу лидеров
}

int GameRun() 
{
	Matr Flip; // Объект класса матрицы отрисовки
	int sch = 1;
	int Sch;
	int R = rand() % 30;
	while (sch != 0) 
	{
		Sch = sch; // Сохранить новый счет для вывода
		if (_kbhit()) // Если была нажата любая клавиша
		{
			sch = Flip.Tack(3); // Прыжек на три строчки вверх
			while (_kbhit()) _getch(); // Ждем оканчания нажатия клавиш(что б птичка не прыгала несколько раз за один кадр)
		}
		else
		{
			sch = Flip.Tack(-1); // Падение на одну строчку вниз
		}

		if (sch % (10+R) == 0) // Каждый десятый кадр
		{
			Flip.Walls(); // Создание стены
			if (sch < 15000)
				R = rand() % (30 - sch / 500);
			else
				R = 0;
		}
		system("cls"); // Очистка консоли
		Flip.OutPut(); // Отрисовка изображения

		cout << "Счет: " << sch;
	}
	system("cls"); // Очистка консоли
	return Sch;

}

int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода (работа с русским текстом)
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода (работа с русским текстом)
	srand(time(NULL)); // Устанавливаем значение системных часов в качестве стартового числа для функции rand()
	Menu UI; //  Объект класса отрисовки меню
	Save Records;
	int sch, Sch; // Счет в текущем кадре и счет для вывода.
	int action=0; // Действие выполняемое по результатам главного меню
	UnSeeCursor(); // Скрытие консольной "каретки"
	bool L = true; // Игра идет
	while (action!=3) // До тех пор, пока в главном меню не будет выбран пункт Выход
	{
		action = UI.MainCicle(); // Запустить главное меню
		L = true; // Начать игру
		switch (action)
		{
		case 1:
			SadMenu(Records, GameRun()); // Вывод сообщения о проигрыше, после проигрыша в игре
			Records.ShowRecord(); // Вывести таблицу лидеров
			while (_getch() != 13/*Enter*/ && _getch() != 32/*Space*/)// Ждать нажатия пробела или Enter
			{
			}
			break;
		case 2:
			Records.ShowRecord(); // Вывести таблицу лидеров
			while (_getch() != 13/*Enter*/ && _getch() != 32/*Space*/)// Ждать нажатия пробела или Enter
			{
			}
			break;
		case 3:
			break;
		default:
			break;
		}

	}	
	system("cls"); // Очистка консоли
}