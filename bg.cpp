#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "bg.hpp"

BG::BG(){
	//load the image and set as sprites
        texture1.loadFromFile("images/Background.png");
        sprite1.setTexture(texture1);
        sprite2.setTexture(texture1);
        //set second sprite just outside the window
        sprite2.setPosition(0,-WSIZE);
}

void BG::draw(sf::RenderWindow &window){
	//draw the two sprites to window
        window.draw(sprite1);
        window.draw(sprite2);
}

void BG::move(){
	//both bakgrounds are moving at the same speed
        sprite1.move(0,3);
        sprite2.move(0,3);
	//if the first background leaves the screen, have the next one move in
        if(sprite1.getPosition().y >= WSIZE){
                sprite1.setPosition(0, -WSIZE);
        }
	//move the previous background back to the start, should be continuous
        if(sprite2.getPosition().y >= WSIZE){
                sprite2.setPosition(0, -WSIZE);
        }
}

