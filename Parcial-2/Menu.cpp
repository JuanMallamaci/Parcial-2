/*
 * Menu.cpp
 *
 *  Created on: May 8, 2024
 *      Author: pc1
 */
#include "Menu.hpp"

char DefScreen()
{
	std::cout << "Ingrese: ";

	char key;
	std::cin >> key;
	return key;
}

void Menu::LoopScreen(const char& exitKey)
{
	char lectura('d');

	while(lectura != exitKey)
	{
		auto pt = screen.find(lectura);

		if(pt != screen.end())
		{
			FuncPtr accion = pt->second;
			lectura = accion();
//			std::cin >>lectura;
		}else
		{
			lectura = 'd';
		}


	}

}

