#include "MainMenu.h"

Menu::Menu()
{
	result = 1;
}

int Menu::MainCicle()
{
	int keyb;
	while (true) // ���� ���������
	{
		Draw(); // ������������ ����
		while (!_kbhit()) {}
		keyb = _getch(); // ��������� ������� �������
		if ((keyb == 214/*�*/ || keyb == 246/*�*/ || keyb == (int)'W' || keyb == (int)'w' || keyb == 72 ) && result > 1)// ���� ��� ������� ����� ��� W 
			result--;
		if ((keyb == 251/*�*/ || keyb == 219/*�*/ || keyb == (int)'S' || keyb == (int)'s' ||keyb == 80 ) && result < 3)// ���� ��� ������� ���� ��� S
			result++;
		if (keyb == 13/*Enter*/|| keyb == 32/*Space*/)// ���� ��� Enter ��� ������
			break;
		
	}
	
	// ��� ����� Enter 
	return result;
}

void Menu::MarkString(const string& S,const int& Size ,const bool& b) // ����� ������, c ����������� �������� ����� ���, � �������� ��������/�� ��������
{
	if (b) // ���� �������� ���������� ���������
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

void Menu::Draw() // ��������� �������� ����
{
	system("cls"); // ������� �������

	for (int i = 7; i >= 0; i--) 
	{
		cout << endl;
	}

	MarkString("���������� ������� �� �������� ������", 40, false); // ����� ���������

	if (result == 1) // ���� ������ �������� ������
	{
		MarkString("������",56, true);
		MarkString("�������",55, false);
		MarkString("�����",56, false);
	}	
	else
		if (result == 2) // ���� ������ �������� �������
		{
			MarkString("������",56, false);
			MarkString("�������",55, true);
			MarkString("�����",56, false);
		}
		else // ���� ������ �������� �����
		{
			MarkString("������",56, false);
			MarkString("�������",55, false);
			MarkString("�����",56, true);
		}

}


