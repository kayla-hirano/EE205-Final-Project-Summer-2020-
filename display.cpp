#include <SFML/Graphics.hpp>
#include <sstream>
#include "config.hpp"
#include "display.hpp"
#include "player.hpp"

Display::Display(int total){
        //set health bar
        health.setFillColor(sf::Color::Green);
        health.setPosition(380, 490);
        health.setSize(sf::Vector2f(total,20));
	//set score font
	Font.loadFromFile("fonts/ostrich.ttf");

	//"Score: " settings
        Score.setFont(Font);
        Score.setString("Score: ");
	Score.setCharacterSize(24);
	Score.setFillColor(sf::Color::White);
        Score.setPosition(380, 440);

	//actual score number settings
	Scorenum.setFont(Font);
	Scorenum.setCharacterSize(24);
	Scorenum.setFillColor(sf::Color::White);
	Scorenum.setPosition(440, 440);
}       

void Display::DrawHP(sf::RenderWindow &window, int total, int h){
        //adjust bar to match health
	health.setSize(sf::Vector2f(h,20));
	int i = total - h;
	health.setPosition(380+i,470);
	//draw to window
	window.draw(health);
}   

void Display::DrawScore(sf::RenderWindow &window, int score){
	//get the player's score
	int total = Player::getInstance()->getScore();
	//change int to a string using stringstream
	std::stringstream ss;
	//move total score into string
	ss << total;
	//set the score with this string
	Scorenum.setString(ss.str());

	//draw to window	
	window.draw(Score);
	window.draw(Scorenum);
}
