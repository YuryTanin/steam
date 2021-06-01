#pragma once
#include <sstream>
#include <math.h>

/**
* \brief Класс Triad для работы с тройками чисел
*/
class Triad
{
private:

	/**
	 * \brief геттер значения поля А
	 */
	double getA() const;
	/**
	 * \brief геттер значения поля B
	 */
	double getB() const;
	/**
	 * \brief геттер значения поля С
	 */
	double getC() const;

	/**
	 * \brief Сеттер поля А
	 */
	void setA(double a);

	/**
	 * \brief Сеттер поля В
	 */
	void setB(double b);

	/**
	 * \brief Сеттер поля С
	 */
	void setC(double c);

protected:
	double a;
	double b;
	double c;

public:

	/**
	 * \brief Конструктор по умолчанию
	 */
	Triad() = default;

	/**
	 * \brief Параметризованный конструктор
	 */
	explicit Triad(const double a, const double b, const double c);

	/**
	 * \brief Деструктор
	 */
	virtual ~Triad() = default;

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Triad& triad);
	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream& out, const Triad& triad);
	/**
	 * \brief Перегруженный оператор сложения с числом
	 */
	friend Triad operator+(const Triad& t, const double n);
	/**
	 * \brief Перегруженный оператор умножения на число
	 */
	friend Triad operator*(const Triad& t, const double n);
	/**
	 * \brief Перегруженный оператор проверки на равенство
	 */
	friend bool operator==(const Triad& t1, const Triad& t2);

};

/**
* \brief Класс Vector3D для работы с тройками чисел
*/
class Vector3D: public Triad
{
public:

	/**
	 * \brief Конструктор по умолчанию
	 */
	Vector3D() = default;

	/**
	 * \brief Параметризованный конструктор
	 */
	Vector3D(const double x, const double y, const double z);

	/**
	 * \brief Деструктор
	 */
	~Vector3D() = default;

	/**
	 * \brief геттер значения поля X
	 */
	double getX() const;
	/**
	 * \brief геттер значения поля Y
	 */
	double getY() const;
	/**
	 * \brief геттер значения поля Z
	 */
	double getZ() const;

	/**
	 * \brief Сеттер поля X
	 */
	void setX(double x);
	/**
	 * \brief Сеттер поля Y
	 */
	void setY(double y);
	/**
	 * \brief Сеттер поля Z
	 */
	void setZ(double z);


	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Vector3D& v);

	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream& out, const Vector3D& v);
	/**
	 * \brief Перегруженный оператор сложения
	 */
	friend Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
	/**
	 * \brief Перегруженный оператор скалярного умножения
	 */
	friend double operator*(const Vector3D& v1, const Vector3D& v2);

};