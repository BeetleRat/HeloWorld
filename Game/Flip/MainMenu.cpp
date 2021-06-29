#include "MainMenu.h"

Menu::Menu()
{
	result = 1;
}

int Menu::MainCicle()
{
	int keyb;
	while (true) // Цикл отрисовки
	{
		Draw(); // Отрисовываем меню
		while (!_kbhit()) {}
		keyb = _getch(); // Считываем нажатие клавиши
		if ((keyb == 214/*Ц*/ || keyb == 246/*ц*/ || keyb == (int)'W' || keyb == (int)'w' || keyb == 72 ) && result > 1)// Если это стрелка вверх или W 
			result--;
		if ((keyb == 251/*ы*/ || keyb == 219/*Ы*/ || keyb == (int)'S' || keyb == (int)'s' ||keyb == 80 ) && result < 3)// Если это стрелка вниз или S
			result++;
		if (keyb == 13/*Enter*/|| keyb == 32/*Space*/)// Если это Enter или пробел
			break;
		
	}
	
	// Был нажат Enter 
	return result;
}

void Menu::MarkString(const string& S,const int& Size ,const bool& b) // Вывод строки, c количеством отступов перед ней, в сотоянии выбранно/не выбранно
{
	if (b) // Если выбранно отрисовать звездачки
	{
		for (int i = 0; i < Size-3; i++)
		{
			cout << " ";
		}
		cout << "***" << S << "***" << endl;
	}		
	else
	{
		for (int i = 0; i < Size; i++)
		{
			cout << " ";
		}
		cout << S << endl;
	}	
}

void Menu::Draw() // Отрисовка игрового меню
{
	system("cls"); // Очистка консоли

	for (int i = 7; i >= 0; i--) 
	{
		cout << endl;
	}

	MarkString("КОНСОЛЬНАЯ ПАРОДИЯ НА ПАДАЮЩУЮ ПТИЧКУ", 40, false); // Вывод заголовка

	if (result == 1) // Если сейчас выбранно Играть
	{
		MarkString("Играть",56, true);
		MarkString("Рекорды",55, false);
		MarkString("Выход",56, false);
	}	
	else
		if (result == 2) // Если сейчас выбранно Рекорды
		{
			MarkString("Играть",56, false);
			MarkString("Рекорды",55, true);
			MarkString("Выход",56, false);
		}
		else // Если сейчас выбранно Выход
		{
			MarkString("Играть",56, false);
			MarkString("Рекорды",55, false);
			MarkString("Выход",56, true);
		}

}


