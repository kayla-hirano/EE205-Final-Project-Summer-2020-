#include <SFML/Graphics.hpp>
#include "button.hpp"
#include <iostream>

//constructor
Button::Button(){}

void Button::Set(int width, int height, int x, int y, sf::Color c){
        button.setSize(sf::Vector2f(width, height));
        button.setOrigin(width/2, height/2);
        button.setPosition(x, y);
        button.setFillColor(c);
}


void Button::CheckEvent(sf::RenderWindow &window){

	sf::Vector2i mpos;

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
         	//left click
                mpos = sf::Mouse::getPosition(window);
                //check the position of mouse
                //std::cout<<mpos.x<<", "<<mpos.y<<std::endl;
                                
		//if over button, do something
                //button is rect, rect has function contains
                if(button.getGlobalBounds().contains(mpos.x, mpos.y)){
                	WasClicked(window);
                }
                //otherwise, do nothing
	}

}

//if button is clicked, set clicked to true
void Button::WasClicked(sf::RenderWindow &w){
	clicked = true;
	return;

}

