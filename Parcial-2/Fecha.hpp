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

class Fecha
{
private:
	int anio;
	int mes;
	int dia;

	bool fechaValida();
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
	/**
	 *
	 * @param f
	 * @return
	 */
	bool operator< (const Fecha& f);
	bool operator> (const Fecha& f);
	bool operator== (const Fecha& f);
	bool operator!= (const Fecha& f);

};

std::ostream& operator<< (std::ostream& os, const Fecha& f);
std::istream& operator>> (std::istream& is, Fecha& f);


#endif /* FECHA_HPP_ */
