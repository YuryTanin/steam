/*
* 16. Написать программу, в которой описана иерархия классов: 
функция от одной переменной (синус, косинус, тангенс). 
Базовый класс должен иметь методы получения значения функции для данного значения переменной,
а также создания экземпляра класса, представляющего собой производную текущего экземпляра. 
Продемонстрировать работу всех методов  всех классов.
*/

#include "lab4.h"
#include <iostream>
using namespace std;

int main()
{
	auto f = Func();
	cout << "Test default func:" << endl;
	cin >> f;
	cout << f;

	cout << "Test trigonometric functions:" << endl;
	auto trig = Function();
	cin >> trig;
	cout << trig;
	return 0;
}