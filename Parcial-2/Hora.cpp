/*
 * Hora.cpp
 *
 *  Created on: May 15, 2024
 *      Author: Mallamaci, Pelayes
 */

#include "Hora.hpp"


Hora::Hora(const int& h, const int& mi)
{

	hora = h;
	min = mi;

	HoraValida();
}

void Hora::SetHora (const int& h)
{
	hora = h;
	HoraValida();
}

void Hora::SetMinuto (const int& m)
{
	min = m;
	HoraValida();
}

void Hora::HoraValida()
{
	HoraException Err(HORA_INVALIDA);

	if (hora  < 0 || hora > 23 || min < 0 || min > 59)
	{
		throw Err;
	}
}

bool Hora::operator< (const Hora& f)
{
	int aux;
	aux = (min + hora*60) - (f.GetMin() + f.GetHora()*60);
//	return (aux > 0);
	return ((min + hora*60) < (f.GetMin() + f.GetHora()*60));
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

	f.SetHora(hora);
	f.SetMinuto(minuto);

	return is;
}

const char* HoraException::what() const throw()
{
	switch (nro)
	{
	case HORA_INVALIDA:
		return "Error hora invalida";
	default:
		return "Error no contemplado en Hora";
	}
}

