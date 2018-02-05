#include <locale.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

void head(char mas[]);
void yellow();
void white();
void red();
bool prost(int x);
void lsearch(int* arr, int len, int ch);
void sort(int* arr, int Len);
void bsearch(int* arr, int len, int ch);
int cow(char* arr, char* arr1);

using namespace std;
unsigned short int nz;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	int i, j;
	while (true)
	{
		cout << "Введите номер задания, 0 - для выхода "; cin >> nz;

		if (nz == 0)
		{
			break;
			system("exit");
		}
		else if (nz == 1)
		{
			/*1.	Написать функцию, которая проверяет, является ли переданное ей число простым? 
				Число называется простым, если оно делится без остатка только на себя и на единицу.*/
			head("1. Написать функцию, которая проверяет, является ли переданное ей число простым? Число называется простым, если оно делится без остатка только на себя и на единицу.");
			int arr[10];
			arr[0] = 1;
			for (i = 1; i < 10; i++)
			{
				arr[i] = arr[i - 1] + 1;				
			}
			yellow();
			cout << " Простые числа в диапозоне от 1 до 10: \n";
			white();
			for (i = 0; i < 10; i++)
			{
				if (prost(arr[i]))printf(" %d\n", arr[i]);					
			}
			cout << endl;			
		}
		else if (nz == 2)
		{
			/*2.	Написать функцию, реализующую алгоритм линейного поиска заданного ключа в 
				одномерном массиве.*/
			head("2. Написать функцию, реализующую алгоритм линейного поиска заданного ключа в одномерном массиве.");
			int mas[10], ch;
			yellow();
			cout << " Массив\n";
			white();
			for (i = 0; i < 10; i++)
			{
				mas[i] = 1 + rand() % 9;
				cout << mas[i] << "\t";
			}
			cout << endl;
			yellow();
			cout << " Число для поиска\n";
			white();
			ch = 1 + rand() % 9;
			cout << ch << endl;
			yellow();
			lsearch(mas, 10, ch);
			cout << endl;
			white();
		}
		else if (nz == 3)
		{
			/*3.	Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в 
				одномерном массиве.*/
			head("3. Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в одномерном массиве.");
			int mas[10], ch;
			yellow();
			cout << " Массив\n";
			white();
			for (i = 0; i < 10; i++)
			{
				mas[i] = 1 + rand() % 9;
				cout << mas[i] << "\t";
			}
			cout << endl;
			yellow();
			cout << " Число для поиска\n";
			white();
			ch = 1 + rand() % 9;
			cout << ch << endl;
			sort(mas, 10);					
			yellow();
			bsearch(mas, 10, ch);
			cout << endl;
			white();
		}
		else if (nz == 4)
		{
			/*4.	Написать игру «Быки и коровы».Программа "загадывает" четырёхзначное число 
				и играющий должен угадать его.После ввода пользователем числа программа 
				сообщает, сколько цифр числа угадано(быки) и сколько цифр угадано и стоит 
				на нужном месте(коровы).После отгадывания числа на экран необходимо вывести 
				количество сделанных пользователем попыток.В программе необходимо использовать 
				рекурсию.*/
			head("4. Написать игру «Быки и коровы». Программа ""загадывает"" четырёхзначное число и играющий должен угадать его. После ввода числа программа сообщает, сколько цифр числа угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы). После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток. В программе необходимо использовать рекурсию.");
			char mas[5],mas1[4];		
			int kol = 0;
			for (int i = 0; i < 4; i++)
			{
				mas1[i] = (1 + rand() % 9) + '0';
				/*cout << mas1[i] << "\t";*/
			}
			cout << endl;
			int n=0;
			cout << "Угадайте четырехзначное число (введите его и нажмие Enter)\n";
			while (n != 4)
			{
				cin >> mas;
				mas[4] = '\0';
				yellow();
				n=cow(mas, mas1);
				kol++;
				white();
				if(n!=4)
				cout << "Попытайтесь еще раз\n";
			}
			yellow();
			if(kol==1)
				cout << "Вы угадали число за " << kol << " попытку.\n";
			else if (kol>1&&kol<5)
				cout << "Вы угадали число за " << kol << " попытки.\n";
			else if(kol>4)
			cout << "Вы угадали число за "<<kol<<" попыток.\n";
			white();
		}
	}	
}

void head(char mas[])
{
	int len, third, s1_len, s2_len, s3_len, maks;
	len = strlen(mas);
	third = len / 3;
	s1_len = third;
	for (int i = s1_len; i < len; i++)
	{
		if (mas[s1_len] != ' ') s1_len++;
		else break;
	}
	s2_len = third;
	for (int i = s1_len + s2_len; i < len; i++)
	{
		if (mas[s1_len + s2_len] != ' ') s2_len++;
		else break;
	}
	s3_len = len - (s1_len + s2_len);
	vector<char>str1(s1_len);
	vector<char>str2(s2_len);
	vector<char>str3(s3_len);
	for (int i = 0; i < s1_len; i++)
	{
		str1[i] = mas[i];
	}
	for (int i = s1_len + 1; i < s1_len + s2_len; i++)
	{
		str2[i - (s1_len + 1)] = mas[i];
	}
	for (int i = s1_len + s2_len + 1; i < len; i++)
	{
		str3[i - (s1_len + s2_len + 1)] = mas[i];
	}
	maks = s1_len;
	if (s2_len > maks)maks = s2_len;
	if (s3_len > maks)maks = s3_len;
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	setlocale(LC_ALL, ".866");
	cout << " Ъ";
	for (int i = 0; i <= maks + 1; i++)cout << "Д";
	cout << "ї\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s1_len; i++) cout << str1[i];
	if (s1_len < maks)
	{
		for (int i = 0; i < maks - s1_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s2_len; i++) cout << str2[i];
	if (s2_len < maks)
	{
		for (int i = 0; i < maks - s2_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s3_len; i++) cout << str3[i];
	if (s3_len < maks)
	{
		for (int i = 0; i < maks - s3_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " А";
	for (int i = 0; i <= maks + 1; i++)cout << "Д";
	cout << "Щ\n";
	SetConsoleTextAttribute(hConsole, 15);
	setlocale(LC_ALL, ".1251");
}

void yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

bool prost(int x)
{
	int r = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x%i == 0)r++;
	}
	if (r == 2) return true;
	else return false;
}

void lsearch(int* arr,int len, int ch)
{
	int r = 0;
	for (int i = 0; i < len; i++)
	{		
		if (arr[i] == ch)
		{
			printf("Число %d найдено, в индексе массива %d", ch, i);
			r = 1;
			break;
		}			
	}
	if(r==0) printf("Число %d не найдено", ch);
}

void bsearch(int* arr, int len, int ch)
{
	int L = 0;
	int R = len-1;
	int m;
	
	int r = 0;

	while (L<=R)
	{
		m = (R+L) / 2;
		if (ch > arr[m]) L = m;
		if (ch < arr[m]) R = m;
		if (ch == arr[m])
		{
			printf("Число %d найдено\n", ch);
			r = 1;
			break;
		}
	}	
	if (r == 0)
	{
		printf("Число %d не найдено\n", ch);
	}
}

void sort(int* arr, int Len)
{
	int prom;
	for (int i = 0; i < Len; i++) 
	{
		for (int j = 0; j < Len - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				prom = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = prom;
			}
		}
	}
}

int cow(char* arr, char* arr1)
{	
	int c = 0, b = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr1[i] == arr[j])b++;
		}
	}
	/*if (b > 4) b = 4;*/
	cout <<"Быков "<<b<<endl;
	for (int i = 0; i < 4; i++)
	{
		if (arr1[i] == arr[i])c++;
	}
	cout << "Коров " << c << endl;
	return c;
}