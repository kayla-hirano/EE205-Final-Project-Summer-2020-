#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include "button.hpp"

class MenuState{
	private:
		//fonts and text
		sf::Font Font;
		sf::Text Button1;
		sf::Text Button2;
		sf::Text Controls;
		//game state
		enum state GameState;
		//buttons
		Button button1;
		Button button2;
		//determine whether to display controls
		bool controls = false;
	public:
                //constructors
		MenuState();
		//gets the game state
		state getState();
		//sets the game state
		void setState(state s);
		//checks to see if a button was clicked
		void CheckEvent(sf::RenderWindow &window);
		//draws menu to the screen
		void Draw(sf::RenderWindow &window);
};

#endif
