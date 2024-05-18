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

	FechaValida();
}

void Fecha::SetFecha (const int& a, const int& m, const int& d)
{
	//manejo error
	anio = a;
	mes = m;
	dia = d;

	FechaValida();
}

void Fecha::SetAnio (const int& a)
{
	anio = a;
	FechaValida();
}

void Fecha::SetMes (const int& m)
{
	mes = m;
	//FechaException mesErr(MES_INVALIDO);
	FechaValida();
}

void Fecha::SetDia (const int& d)
{
	dia = d;
	FechaValida();
}


void Fecha::FechaValida()
{
	FechaException diaErr(DIA_INVALIDO);
	FechaException mesErr(MES_INVALIDO);
	FechaException anioErr(ANIO_INVALIDO);
	int diaEnMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if(anio < 0)
	{
		throw anioErr;
	}else if(mes < 1 || mes > 12)
	{
		throw mesErr;
	}else if(dia < 1 || (dia >= diaEnMes[mes-1]) )
	{
		throw diaErr;
	}
}
/*
bool Fecha::fechaValida()
{
	if (anio < 0 || mes < 1 || mes > 12 || dia < 1)
	{

		return false;
	}



	return ( dia <= diaEnMes[mes - 1] );
}
*/
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

const char* FechaException::what() const throw()
{
	switch (nro)
	{
	case DIA_INVALIDO:
		return "Error dia invalido";
	case MES_INVALIDO:
		return "Error mes invalido.";
	case ANIO_INVALIDO:
		return "Error anio invalido";
	default:
		return "Error";
	}
}
