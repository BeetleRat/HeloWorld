#pragma once
#include<iostream>
#include<string>
#include<conio.h>


using namespace std;

class Menu // Класс отрисовки игрового меню
{
private:
	int result; // Вкладка по которой переходит игрок
	void MarkString(const string&, const int&, const bool&); // Вывод строки, c количеством отступов перед ней, в сотоянии выбранно/не выбранно
	void Draw(); // Отрисовка меню
public:
	Menu(); // Конструктор
	int MainCicle(); // Главный цикл 



};