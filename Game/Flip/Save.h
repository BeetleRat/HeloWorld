#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

class Save // ����� ������ � ������� �� �����
{
private:
	fstream File; // ���������� ��� ������ � �������
	string S; // ���������� ��� ������ �� ��������
	pair<int, string> P; // ���������� ��� ������ � ������ ������ - ���
	vector<pair<int, string>> V1; // ������ ��� ������ - ���
	bool Permission; // ���������� �� ������ �������
	int Min; // ����������� ������

public:
	Save(); // �����������
	~Save();// ����������
	void SAVE(); // ���������� ������� ��������
	void ShowRecord(); // ����� ������ ��������
	void SetRecord(string, int); // ���������� ������ �������
		// �������
	int GetMin();


};