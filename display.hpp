#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SFML/Graphics.hpp>

class Display{
	private:
		//fonts and text
		sf::Font Font;
		sf::Text Score;
		sf::Text Scorenum;
		//health bar
		sf::RectangleShape health;
	public:
                //constructors
		Display(){}
		~Display(){};
                Display(int total);
                //draws player info to screen
                void DrawHP(sf::RenderWindow &window, int total, int h);
		void DrawScore(sf::RenderWindow &window, int score);
};

#endif
