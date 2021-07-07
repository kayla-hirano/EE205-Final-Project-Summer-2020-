#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

//determines the game state
enum state{Menu, Game};

class Button{
	private:
		int buttonfunction;
	public:
		bool clicked = false;
		sf::RectangleShape button;

		//constructor
		Button();
		//set the parameters of the button
		void Set(int width, int height, int x, int y, sf::Color c);
		//check to see is button was clicked
		void CheckEvent(sf::RenderWindow &window);
		//if clicked, run this function
		void WasClicked(sf::RenderWindow &w);
};

#endif
