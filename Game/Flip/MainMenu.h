#pragma once
#include<iostream>
#include<string>
#include<conio.h>


using namespace std;

class Menu // ����� ��������� �������� ����
{
private:
	int result; // ������� �� ������� ��������� �����
	void MarkString(const string&, const int&, const bool&); // ����� ������, c ����������� �������� ����� ���, � �������� ��������/�� ��������
	void Draw(); // ��������� ����
public:
	Menu(); // �����������
	int MainCicle(); // ������� ���� 



};