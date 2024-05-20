/*
 * Hora.cpp
 *
 *  Created on: May 15, 2024
 *      Author: pc1
 */

#include "Hora.hpp"


Hora::Hora(const int& h, const int& mi)
{

	hora = h;
	min = mi;

	if(!HoraValida())
	{
		throw 4;
	}

}

void Hora::SetHora (const int& h)
{
	hora = h;
	if(!HoraValida())
	{
		throw 2;
	}
}

void Hora::SetMinuto (const int& m)
{
	min = m;
	if(!HoraValida())
	{
		throw 3;
	}
}

bool Hora::HoraValida()
{
	if (hora  < 0 || hora > 23 || min < 0 || min > 59)
	{
		return false;
	}
	return true;
}

bool Hora::operator< (const Hora& f)
{
	int aux;
	aux = (min + hora*60) - (f.GetMin() + f.GetHora()*60);
	return (aux > 0);
}

bool Hora::operator> (const Hora& f)
{
	return !(*this < f);
}

bool Hora::operator== (const Hora& f)
{
	return ( (hora == f.GetHora()) && (min == f.GetMin()));
}

bool Hora::operator!= (const Hora& f)
{
	return !(*this == f);
}


std::ostream& operator<< (std::ostream& os, const Hora& f)
{
	os << std::setw(2) << std::setfill('0') << f.GetHora() << "-" << std::setw(2) << std::setfill('0') << f.GetMin() ;
	return os;
}

std::istream& operator>> (std::istream& is, Hora& f)
{
	int hora, minuto;
	char delimit;

	is >> hora;
	is >> delimit;
	if( delimit != '-' )
	{
		throw std::invalid_argument("Formato de hora incorrecto");
	}

	is >> minuto;
	is >> delimit;
	if( delimit != '-' )
	{
		throw std::invalid_argument("Formato de hora incorrecto");
	}

	f.SetHora(hora);
	f.SetMinuto(minuto);

	return is;
}


