/*
 * Fecha.cpp
 *
 *  Created on: May 3, 2024
 *      Author: pc1
 */
#include "Fecha.hpp"

Fecha::Fecha(const int& a, const int& m, const int& d)
{
	anio = a;
	mes = m;
	dia = d;

	if(!fechaValida())
	{
		throw 1;
	}

}

void Fecha::SetFecha (const int& a, const int& m, const int& d)
{
	//manejo error
	anio = a;
	mes = m;
	dia = d;

	if(!fechaValida())
	{
		throw 1;
	}
}

void Fecha::SetAnio (const int& a)
{
	anio = a;
	if(!fechaValida())
	{
		throw 1;
	}
}

void Fecha::SetMes (const int& m)
{
	mes = m;
	if(!fechaValida())
	{
		throw 1;
	}
}

void Fecha::SetDia (const int& d)
{
	dia = d;
	if(!fechaValida())
	{
		throw 1;
	}
}

bool Fecha::fechaValida()
{
	if (anio < 0 || mes < 1 || mes > 12 || dia < 1)
	{
		return false;
	}

	int diaEnMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return ( dia <= diaEnMes[mes - 1] );
}

bool Fecha::operator< (const Fecha& f)
{

	if (this->anio != f.GetAnio())
	{
		return (this->anio < f.GetAnio());
	}else if (this->mes != f.GetMes())
	{
		return (this->mes < f.GetMes());
	}else if (this->dia != f.GetDia())
	{
		return (this->dia < f.GetDia());
	}
}

bool Fecha::operator> (const Fecha& f)
{
	return !(*this < f);
}

bool Fecha::operator== (const Fecha& f)
{
	return ( (anio == f.GetAnio()) && (mes == f.GetMes()) && (dia == f.GetDia()) );
}

bool Fecha::operator!= (const Fecha& f)
{
	return !(*this == f);
}


std::ostream& operator<< (std::ostream& os, const Fecha& f)
{
	os << std::setw(4) << std::setfill('0') << f.GetAnio() << "-" << std::setw(2) << std::setfill('0') << f.GetMes()
					<< "-" << std::setw(2) << std::setfill('0') << f.GetDia();
	return os;
}

std::istream& operator>> (std::istream& is, Fecha& f)
{
	char delimit;
	int anio, mes, dia;

	//validar
	is >> anio >> delimit >> mes >> delimit >> dia;

	f.SetFecha(anio, mes, dia);

	return is;
}


