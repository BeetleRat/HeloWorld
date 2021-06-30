#include "Save.h"



Save::Save()
{
	Size = 30; // ������������� ���������� �������� ��������
	S = "";
	File.open("Records.txt", ios_base::in|ios_base::out | ios_base::app);// ��������� ���� ��� ������,������ � ������(����� ������� ���� ��������� ���� �� ����� �� �� �����������)
	if (!File.is_open()) // ����  ���� �� �������� 
	{
		cout << "������! ���� � ��������� �� ������." << endl;
		Permission = false; // ������ �� ������ �������
		system("pause");
		
	}
	else
	{
		Permission = true; // ���������� �� ������ �������
		Min = 0;// ��������� ������������ �������
		while (!File.eof())
		{
			getline(File, S); // ��������� ������ �� �����
			P.second = ""; // �������� ���
			P.first = 0; // �������� ������
			for (int i = 0; i < S.length();i++) // ���� �� ������
			{
				if (i < 3) // ������ ��� ������� ��� ���
					P.second = P.second + S[i]; // ��������� ���
				else 
				{
					if ((int)S[i] >= (int)'0' && (int)S[i] <= (int)'9') // ���� ����� �� �����
					{
						P.first = (int)S[i] - (int)'0'; // ������ ����� ���� �����
						i++;
						while (i< S.length()&& (int)S[i] >= (int)'0' && (int)S[i] <= (int)'9') // ���� ������ ���� ����� � ������ �� �����������
						{
							P.first = P.first * 10 + (int)S[i] - (int)'0'; // ��������� ������
							i++;
						}
						V1.push_back(P); // ��������� � ������ ��������
					}
				}
			}
		}
		CheckRecord(); // �������� ������������ ������ ��������
		Min = V1[0].first; // ���������� ������������ �������
	}
	File.close(); // ��������� ����
}

Save::~Save()
{
	SAVE();
}

void Save::CheckRecord() // �������� ������������ ������ ��������
{
	while (V1.size() > Size-1) // ������� ������ �������
		V1.pop_back();

	P.second = "AAA"; // �������� ���
	P.first = 0; // �������� ������

	while (V1.size() < Size - 1) // ��������� �����������
		V1.push_back(P);
	
	sort(V1.begin(), V1.end()); // ���������� �������
}

void Save::SAVE()
{
	File.open("Records.txt", ios_base::out | ios_base::trunc);// ��������� ���� ��� ��������(����� ������� ���� ��������� ���� �� ����� �� �� �����������)
	if (!File.is_open()) // ����  ���� �� �������� 
	{
		cout << "������! ���� � ��������� �� ������." << endl;
		Permission = false;
		system("pause");

	}
	else
	{
		if (Permission)// ���� ���� ���������� �� ������ �������
		{
			for (int i = 0; i < V1.size() - 1; i++)
			{
				File << V1[i].second << " - " << V1[i].first << endl;
			}
			File << V1[V1.size() - 1].second << " - " << V1[V1.size() - 1].first;
		}
	}
	File.close(); // ��������� ����
}

void Save::ShowRecord() // ����� ������ ��������
{
	if (Permission) // ���� ���� ���������� �� ������ �������
	{
		system("cls"); // ������� �������
		// ������������ ������ �������
		S = "";
		for (int i = 0; i < 50; i++)
		{
			S = S + " ";
		}
		// ����� ������ ��������
		for (int i = V1.size()-1; i >= 0; i--)
		{
			cout << S << V1[i].second << " - " << V1[i].first << endl;
		}
	}
}

void Save::SetRecord(int Rec) // ���������� ������ �������
{
	if (Permission&& Rec>Min)// ���� ���� ���������� �� ������ �������
	{
		S = "";
		for (int i = 8; i >= 0; i--)
		{
			cout << endl;
		}
		for (int i = 0; i < 45; i++)
		{
			S = S + " ";
		}
		cout << S << "������� ���� ���: AAA\b\b\b"; // ����� ������ ������ ������� ������� ��� ���� �����, ����� ������� �������� ��������� ��� ����� �
		getline(cin, S);
		while (S.length() < 3) // ���� ������� ������ ���� ��������
			S = S + "A"; // �������� �� ����
		S.erase(3, S.length() - 3); // ������� ��� �������, ����� ������ ����
			// ���������� ����������
		P.second = S;
		P.first = Rec;
		V1.push_back(P);
		sort(V1.begin(), V1.end()); // ���������� ��������
		V1.erase(V1.begin()); // �������� ������������ �������
		Min = V1[0].first; // ���������� ������������ �������
		SAVE();
	}
}
