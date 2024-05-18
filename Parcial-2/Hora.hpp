/*
 * Hora.hpp
 *
 *  Created on: May 15, 2024
 *      Author: pc1
 */

#ifndef HORA_HPP_
#define HORA_HPP_


#include <iostream>
#include <iomanip>
#include <sstream>

enum { HORA_INVALIDA, MIN_INVALIDO };

class Hora
{
private:
	int hora;
	int min;

	void HoraValida();
public:
	Hora(): hora(0), min(0) {};
	Hora(const int& h, const int& mi);

	int GetHora () const { return hora; }
	int GetMin () const { return min; }

	//manejo error
	void SetHora (const int& h);
	void SetMinuto (const int& m);

	//operadores

	bool operator< (const Hora& f);
	bool operator> (const Hora& f);
	bool operator== (const Hora& f);
	bool operator!= (const Hora& f);

};

std::ostream& operator<< (std::ostream& os, const Hora& f);
std::istream& operator>> (std::istream& is, Hora& f);

class HoraException: public std::exception
{
	int nro;
public:
	HoraException(const int& _nro): nro(_nro) {};
	virtual const char* what() const throw();
};



#endif /* HORA_HPP_ */
