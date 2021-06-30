#include "Save.h"



Save::Save()
{
	Size = 30; // Устанавливаем количество хранимых рекордов
	S = "";
	File.open("Records.txt", ios_base::in|ios_base::out | ios_base::app);// Открываем файл для чтения,записи и дописи(таким образом файл создастся если до этого он не существовал)
	if (!File.is_open()) // Если  файл не открылся 
	{
		cout << "Ошибка! Файл с рекордами не найден." << endl;
		Permission = false; // Запрет на работу функций
		system("pause");
		
	}
	else
	{
		Permission = true; // Разрешение на работу функций
		Min = 0;// Обнуление минимального рекорда
		while (!File.eof())
		{
			getline(File, S); // Считываем строку из файла
			P.second = ""; // Обнуляем имя
			P.first = 0; // Обнуляем рекорд
			for (int i = 0; i < S.length();i++) // Идем по строке
			{
				if (i < 3) // Первые три символа это имя
					P.second = P.second + S[i]; // Формируем имя
				else 
				{
					if ((int)S[i] >= (int)'0' && (int)S[i] <= (int)'9') // Если дошли до цифры
					{
						P.first = (int)S[i] - (int)'0'; // Рекорд равен этой цифре
						i++;
						while (i< S.length()&& (int)S[i] >= (int)'0' && (int)S[i] <= (int)'9') // Пока подряд идут цифры и строка не закончилась
						{
							P.first = P.first * 10 + (int)S[i] - (int)'0'; // Формируем рекорд
							i++;
						}
						V1.push_back(P); // Добавляем в список рекордов
					}
				}
			}
		}
		CheckRecord(); // Проверка корректности списка рекордов
		Min = V1[0].first; // Сохранение минимального рекорда
	}
	File.close(); // Закрываем файл
}

Save::~Save()
{
	SAVE();
}

void Save::CheckRecord() // Проверка корректности списка рекордов
{
	while (V1.size() > Size-1) // Удаляем лишние рекорды
		V1.pop_back();

	P.second = "AAA"; // Обнуляем имя
	P.first = 0; // Обнуляем рекорд

	while (V1.size() < Size - 1) // Добавляем нехватающие
		V1.push_back(P);
	
	sort(V1.begin(), V1.end()); // Сортировка вектора
}

void Save::SAVE()
{
	File.open("Records.txt", ios_base::out | ios_base::trunc);// Открываем файл для перепеси(таким образом файл создастся если до этого он не существовал)
	if (!File.is_open()) // Если  файл не открылся 
	{
		cout << "Ошибка! Файл с рекордами не найден." << endl;
		Permission = false;
		system("pause");

	}
	else
	{
		if (Permission)// Если есть разрешение на работу функций
		{
			for (int i = 0; i < V1.size() - 1; i++)
			{
				File << V1[i].second << " - " << V1[i].first << endl;
			}
			File << V1[V1.size() - 1].second << " - " << V1[V1.size() - 1].first;
		}
	}
	File.close(); // Закрываем файл
}

void Save::ShowRecord() // Вывод списка рекордов
{
	if (Permission) // Если есть разрешение на работу функций
	{
		system("cls"); // Очистка консоли
		// Формирование строки отступа
		S = "";
		for (int i = 0; i < 50; i++)
		{
			S = S + " ";
		}
		// Вывод списка рекордов
		for (int i = V1.size()-1; i >= 0; i--)
		{
			cout << S << V1[i].second << " - " << V1[i].first << endl;
		}
	}
}

void Save::SetRecord(int Rec) // Добавление нового рекорда
{
	if (Permission&& Rec>Min)// Если есть разрешение на работу функций
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
		cout << S << "Введите ваше имя: AAA\b\b\b"; // После вывода строки отводим каретку три раза назад, таким образом участник перепишет три буквы А
		getline(cin, S);
		while (S.length() < 3) // Если введено меньше трех символов
			S = S + "A"; // Добиваем до трех
		S.erase(3, S.length() - 3); // Удаляем все символы, кроме первых трех
			// Сохранение результата
		P.second = S;
		P.first = Rec;
		V1.push_back(P);
		sort(V1.begin(), V1.end()); // Сортировка вектороа
		V1.erase(V1.begin()); // Удаление минимального рекорда
		Min = V1[0].first; // Сохранение минимального рекорда
		SAVE();
	}
}
