#include "Goods.h"

Goods::Goods(const std::string name, const std::string regDate, const double price, const unsigned int quantity, const unsigned int waybillIndex)
{
	setName(name);
	setRegDate(regDate);
	setPrice(price);
	setQuantity(quantity);
	setWaybillIndex(waybillIndex);
}

Goods::Goods(const Goods& other): _productName(other.getName()), _regDate(other.getRegDate()),
		_productPrice(other.getPrice()), _productQuantity(other.getQuantity()), _waybillIndex(other.getWaybillIndex())
{
}

void Goods::changePrice(const double newPrice)
{
	if (newPrice < 0)  throw std::invalid_argument("invalid price");
	setPrice(newPrice);
}

void Goods::changeQuantity(const int newQuantity)
{
	if (getQuantity() + newQuantity < 0) throw std::invalid_argument("invalid quantity");
	setQuantity(getQuantity() + newQuantity);
}

double Goods::cost(const unsigned int quantity) const
{
	return quantity*getPrice();
}

std::string Goods::toString() const
{
	return std::to_string(getPrice());
}

std::string Goods::getName() const
{
	return this->_productName;
}

std::string Goods::getRegDate() const
{ 
	return  this->_regDate;
}

double Goods::getPrice() const
{
	return  this->_productPrice;
}

unsigned int Goods::getQuantity() const
{
	return  this->_productQuantity;
}

unsigned int Goods::getWaybillIndex() const
{
	return  this->_waybillIndex;
}

void Goods::setName(const std::string name)
{
	this->_productName = name;
}

void Goods::setRegDate(const std::string regDate)
{
	this->_regDate = regDate;
}

void Goods::setPrice(const double price)
{
	this->_productPrice = price;
}

void Goods::setQuantity(const unsigned int quantity)
{
	this->_productQuantity = quantity;
}

void Goods::setWaybillIndex(const unsigned int waybillIndex)
{
	this->_waybillIndex = waybillIndex;
}

std::istream& operator>>(std::istream& in, Goods& g)
{
	std::string name, regDate;
	double price;
	unsigned int quantity, waybillIndex;
	in >> name >> regDate >> price >> quantity >> waybillIndex;
	g = Goods(name, regDate, price, quantity, waybillIndex);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Goods& g)
{
	out << "Product name: " << g.getName() << std::endl
		<< "Price: " << g.getPrice() << std::endl
		<< "Quantity: " << g.getQuantity() << std::endl
		<< "Date of registration: " << g.getRegDate() << std::endl
		<< "Waybill Index: " << g.getWaybillIndex() << std::endl;
	return out;
}
