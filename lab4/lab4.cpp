#include "lab4.h"
#include <iostream>
#include <math.h>

Func::Func(const double a) :a(a) {}

double Func::getA() const
{
	return this->a;
}

void Func::setA(double a)
{
	this->a = a;
}

std::istream& operator>>(std::istream& in, Func& f)
{
	double a;
	in >> a;
	f = Func(a);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Func& f)
{
	out << "Value:  " << f.getA() << std::endl;
	return out;
}

double Function::getFunc(const double a) const
{
	return getA();
}

Function::Function(const double a)
{	setA(a);
	SetSin();
	SetCos();
	SetTg();
	SetDerSin();
	SetDerCos();
	SetDerTg();
}

double Function::getA() const
{
	return this->a;
}

void Function::setA(const double a)
{
	this->a = a;
}

void Function::SetSin()
{
	this->_sin = sin(getA());
}

void Function::SetCos()
{
	this->_cos = cos(getA());
}

void Function::SetTg()
{
	this->_tg = tan(getA());
}

void Function::SetDerSin()
{
	this->_derSin = cos(getA());
}

void Function::SetDerCos()
{
	this->_derCos = -sin(getA());
}

void Function::SetDerTg()
{
	this->_derTg = 1 / pow(cos(getA()), 2);
}

double Function::getSin() const
{
	return this->_sin;
}

double Function::getCos() const
{
	return this->_cos;
}

double Function::getTg() const
{
	return  this->_tg;
}

double Function::getDerSin() const
{
	return this->_derSin;
}

double Function::getDerCos() const
{
	return this->_cos;
}

double Function::getDerTg() const
{
	return  this->_derTg;
}

std::istream& operator>>(std::istream& in, Function& f)
{
	double a;
	in >> a;
	f = Function(a);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Function& funct)
{
	out << "sin(x)= " << funct.getSin() << std::endl
		<< "sin(x)'= " << funct.getDerSin() << std::endl
		<< "cos(x)= " << funct.getCos() << std::endl
		<< "cos(x)'= " << funct.getDerCos() << std::endl
		<< "tg(x)= " << funct.getTg() << std::endl
		<< "tg(x)'= " << funct.getDerTg() << std::endl;
	return out;
}