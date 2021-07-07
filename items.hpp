#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <SFML/Graphics.hpp>

class Player;

class Items{
	private:
		sf::CircleShape healthpot;
		sf::Texture texture;
		sf::Sprite potion; 
	public:
		bool isActive;
		//constructor
		Items();
                //draws items to screen
                void DrawHealthPot(sf::RenderWindow &window);
		//check to see if player rouches item
		void CheckCollision(sf::RenderWindow &w);
};

#endif
