#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.hpp"
#include "bg.hpp"
#include "display.hpp"
#include "player.hpp"
#include "items.hpp"
#include "menustate.hpp"

int main(){

	//variable to determine whether to move to boss phase
	bool boss = false;

	//window size
	sf::RenderWindow window(sf::VideoMode(WSIZE, WSIZE), "Pew Pew");
        //code to improve framerate
        window.setFramerateLimit(60);

	////////////////
	//CREATE ITEMS//
	////////////////

	//create menu
	MenuState menu;
	//create background
	BG bg;
	//create player
	Player *player = Player::getInstance();
        //create display
	int totalhealth = player->getHealth();
        Display dp(totalhealth);
	//create enemy pool
        Pool enemypool;
	//spawn enemies
	enemypool.SpawnEnemy();	
	//create meteors
	Meteor meteor;
	//create items
	Items potion;
	//create boss 
	Boss bossenemy;

	//////////////////
	//IN GAME EVENTS//
	//////////////////

	//while the window is open
	while(window.isOpen()){

		//events that happen in window
		sf::Event event;
		while(window.pollEvent(event)){
			//if the game is playing, control the player
			if(menu.getState() == Game){
				//user input here
				player->HandleEvent();
			}
			//close window
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}


	//if the menu is being displayed
	if(menu.getState() == Menu){
		//move the background
		bg.move();

		menu.CheckEvent(window);

		/////////////
		//DRAWABLES//
		/////////////

		bg.draw(window);
		menu.Draw(window);
		player->Draw(window);

	}


	//if the game is being played
	if(menu.getState() == Game){

		/////////////
		//MOVEABLES//
		/////////////

		player->Move();
		bg.move();
		if(boss == true){
			//boss stuff
			bossenemy.Move();
		}
		enemypool.Move();

		meteor.Spawn();
		meteor.Fall();

		//check for collisions
		enemypool.CheckCollision(window);
		//if the update function returns complete
		if(enemypool.Update(window)==COMPLETE){
	        	//if no enemies are active, the level is over
			//start the boss stage
			boss = true;
		}

		meteor.CheckCollision(window);
		player->CheckCollision(enemypool);
		if(boss == true){
			potion.CheckCollision(window);
			bossenemy.CheckCollision(window);
			player->CheckBossCollision(bossenemy);
		}

		//every frame clear window, draw shapes, and display
		window.clear();

		/////////////
		//DRAWABLES//
		/////////////

		//draw background first
		bg.draw(window);

		player->Draw(window);
		enemypool.Draw(window);
		meteor.Draw(window);
		if(boss == true){
			potion.DrawHealthPot(window);
			bossenemy.Draw(window);
		}

		//draw display last
		dp.DrawHP(window, totalhealth, player->getHealth());
		dp.DrawScore(window, player->getScore());
	}

	window.display();
	}

	return 0;
}
