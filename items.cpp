#include <iostream>
#include "items.hpp"
#include "player.hpp"

Items::Items(){
        texture.loadFromFile("images/Potion.png");
        potion.setTexture(texture);
	isActive = true;
	potion.setPosition(250,250);
}

//function to draw the potion to the screen
void Items::DrawHealthPot(sf::RenderWindow &window){
	//if the potion is active
	if(isActive){
		//draw the potion the the screen
		window.draw(potion);
	}
	return;	
}

//function for if the player and enemy collide
void Items::CheckCollision(sf::RenderWindow &w){
	//if the potion is active
	if(isActive){
        	//while the player is still colliding with the enemy
        	if(potion.getGlobalBounds().intersects(Player::getInstance()->player.getGlobalBounds())){
			//restore player's health to fll
        	        Player::getInstance()->setHealth(100);
			//make the enemy inactive
			isActive = false;
        	}
	}
}



