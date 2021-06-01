#pragma once
#include <sstream>
/**
 * \brief Класс Goods для работы с товарами
 */
class Goods
{
private:
	std::string _productName;
	std::string _regDate;
	double _productPrice;
	unsigned int _productQuantity;
	unsigned int _waybillIndex;

	/**
	 * \brief сеттер наименование товара
	 */
	std::string getName() const;
	/**
	 * \brief сеттер дата оформления
	 */
	std::string getRegDate() const;
	/**
	 * \brief сеттер цена товара
	 */
	double getPrice() const;
	/**
	 * \brief сеттер количество единиц товара
	 */
	unsigned int getQuantity() const;
	/**
	 * \brief сеттер номер накладной
	 */
	unsigned int getWaybillIndex() const;

	/**
	 * \brief геттер наименование товара
	 */
	void setName(const std::string name);
	/**
	 * \brief геттер дата оформления
	 */
	void setRegDate(const std::string regDate);
	/**
	 * \brief геттер цена товара
	 */
	void setPrice(const double price);
	/**
	 * \brief геттер количество единиц товара
	 */
	void setQuantity(const unsigned int quantity);
	/**
	 * \brief сеттер номер накладной
	 */
	void setWaybillIndex(const unsigned int waybillIndex);

public:

	/**
	 * \brief Конструктор по умолчанию
	 */
	Goods() = default;

	/**
	 * \brief Параметризованный конструктор
	 */
	Goods(const std::string name, const std::string regDate, const double price,
		const unsigned int quantity, const unsigned int waybillIndex);

	/**
	 * \brief Конструктор копирования
	 */
	Goods(const Goods& other);

	/**
	 * \brief Деструктор
	 */
	~Goods() = default;


	/**
	 * \brief метод изменения цены товара
	 */
	void changePrice(const double newPrice);

	/**
	 * \brief метод изменения количества товара
	 */
	void changeQuantity(const int newQuantity);

	/**
	 * \brief метод вычисления стоимости товаров
	 */
	double cost(const unsigned int quantity) const;

	/**
	 * \brief метод стоимость товара в виде строки
	 */
	std::string toString() const;

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Goods& g);

	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream& out, const Goods& g);

};