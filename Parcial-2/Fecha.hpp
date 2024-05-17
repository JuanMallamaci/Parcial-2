/*
 * Fecha.hpp
 *
 *  Created on: May 3, 2024
 *      Author: pc1
 */

#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <iostream>
#include <iomanip>
#include <exception>

enum { ANIO_INVALIDO, MES_INVALIDO, DIA_INVALIDO };

class Fecha
{
private:
	int anio;
	int mes;
	int dia;

	void FechaValida();
public:
	Fecha(): anio(0), mes(0), dia(0){};
	Fecha(const int& a, const int& m, const int& d);

	int GetAnio () const { return anio; }
	int GetMes () const { return mes; }
	int GetDia () const { return dia; }

	//manejo error
	void SetFecha (const int& a, const int& m, const int& d);
	void SetAnio (const int& a);
	void SetMes (const int& m);
	void SetDia (const int& d);

	//operadores
	bool operator< (const Fecha& f);
	bool operator> (const Fecha& f);
	bool operator== (const Fecha& f);
	bool operator!= (const Fecha& f);

};

std::ostream& operator<< (std::ostream& os, const Fecha& f);
std::istream& operator>> (std::istream& is, Fecha& f);

class FechaException: public std::exception
{
	int nro;
public:
	FechaException(const int& _nro): nro(_nro) {};
	virtual const char* what() const throw();
};


#endif /* FECHA_HPP_ */
