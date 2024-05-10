/*
 * Menu.hpp
 *
 *  Created on: May 8, 2024
 *      Author: pc1
 */

#ifndef MENU_HPP_
#define MENU_HPP_
#include <string>
#include <iostream>
#include  <map>

struct Screen
{
	void(*action)();
	std::string text;

	template<typename... Args>
	Screen(const std::string& text, void(*func)(Args...)) : text(text), action(func) {}
};

class Menu
{
private:
	std::map<char,Screen> screens;
public:
	Menu();

	void AddScreen(const char& key,const std::string& text,  const void (*method));

};


#endif /* MENU_HPP_ */
