/* 4.  Функция переводит часы и минуты в секунды. 
 Во всех заданиях реализуемые функции должны генерировать подходящие исключения.
 Обработку исключений нужно выполнять главной функцией, которая должна демонстрировать обработку всех перехватываемых исключений.
 Функции, реализуемые в заданиях, обязаны выполнять проверку передаваемых параметров и
 генерировать исключения в случае ошибочных.
 Все функции реализуются в четырех вариантах:
	- без спецификации исключений;
	- со спецификацией throw();
	- с конкретной спецификацией с подходящим стандартным исключением;
	- спецификация с собственным реализованным исключением.
	(как пустой класс, как независимый класс с полями-параметрами функции, как наследник от стандартного исключения с полями)
*/

#include <iostream>
using namespace std;

/*
* \brief структура для хранения минут и секунд
*/
struct time_s {
	unsigned int minutes;
	unsigned int seconds;
	static constexpr int SECONDS_CONST = 3600;
	static constexpr int MINUTES_CONST = 60;
};

time_s convertTime(const double hours) {
	time_s t;
	int seconds = hours * t.SECONDS_CONST;
	t.minutes = seconds / t.MINUTES_CONST;
	t.seconds = seconds % t.MINUTES_CONST;
	return t;
}
/*
* \brief без спецификации исключений
*/
time_s convertTime1(const double hours) {
	if (hours <= 0) {
		throw 'e';
	}
	return convertTime(hours);
}

/*
* \brief со спецификацией throw()
*/
time_s convertTime2(const double hours) throw() {
	if (hours <= 0) throw 'e';
	return convertTime(hours);
}

/*
* \brief с конкретной спецификацией с подходящим стандартным исключением
*/
time_s convertTime3(const double hours) throw(invalid_argument) {
	if (hours <= 0) throw invalid_argument("Error, hours value <= 0");
	return convertTime(hours);
}

/*
* \brief независимый класс с полями-параметрами функции
*/
class IndependentException
{
public:
	string _e;
	IndependentException(string e) :_e(e) {}
	string what()
	{
		return _e;
	}
};
/*
* \brief Спецификация с собственным реализованным исключением
*/
time_s convertTime4_1(const  double hours) throw(IndependentException) {
	if (hours <= 0) throw IndependentException("Error, hours value <= 0");
	return convertTime(hours);
}

/*
* \brief пустой класс
*/
class ZeroException {};
/*
* \brief Спецификация с собственным реализованным исключением
*/
time_s convertTime4_2(const double hours) throw(ZeroException) {
	if (hours <= 0) throw ZeroException();
	return convertTime(hours);
}

/*
* \brief Класс наследник от стандартного исключения с полем
*/
class InCorrectValue : public exception
{
public:
	const char* what() const throw() {
		return "Error, hours value <= 0";
	}
};
/*
* \brief Спецификация с собственным реализованным исключением
*/
time_s convertTime4_3(const double hours) {
	if (hours <= 0) throw InCorrectValue();
	return convertTime(hours);
}

int main()
{
	double hours;
	cout << "Input Hours to convert: ";
	cin >> hours;


	cout << "Test error 1: ";
	try {
		time_s converted;
		converted = convertTime1(hours);
		cout << converted.minutes << ":" << converted.seconds << endl;
	}
	catch (char) {
		cout << "Rising err 1\n";
	}


	cout << "Test error 2: ";
	try {
		time_s converted;
		converted = convertTime2(hours);
		cout << converted.minutes << ":" << converted.seconds << endl;
	}
	catch (char) {
		cout << "Rising err 2\n";
	}


	cout << "Test error 3: ";
	try {
		time_s converted;
		converted = convertTime3(hours);
		cout << converted.minutes << ":" << converted.seconds << endl;
	}
	catch (invalid_argument& e) {
		cout << e.what()<<endl;
	}


	cout << "Test error 4-1: ";
	try {
		time_s converted;
		converted = convertTime4_1(hours);
		cout << converted.minutes << ":" << converted.seconds << endl;
	}
	catch (IndependentException& e) {
		cout << e.what()<<endl;
	}


	cout << "Test error 4-2: ";
	try {
		time_s converted;
		converted = convertTime4_2(hours);
		cout << converted.minutes << ":" << converted.seconds << endl;
	}
	catch (ZeroException& e) {
		cout << "Error 4-2\n";
	}


	cout << "Test error 4-3: ";
	try {
		time_s converted;
		converted = convertTime4_3(hours);
		cout << converted.minutes << ":" << converted.seconds << endl;
	}
	catch (InCorrectValue& e) {
		cout << e.what();
	}
}