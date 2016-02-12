#include<iostream>
#include"arithmetic.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char str1[256] = { 0 };
	char str2[256] = { 0 };
	double res = 0;
	cout << "Тестирование программы 'Калькулятор для целых чисел на основе обратной польской записи' " << endl;
	cout << "Введите арифметическое выражение" << endl;
	gets(str1);
	opn(str1, str2);
	cout <<" обратная польская запись: " << endl;
	cout << str2 << endl;
	res = result(str2);
	cout << "Результат арифметического выражения: " << endl;
	cout << res << endl;
  return 0;
}