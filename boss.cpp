#include <stdio.h>
#include <iostream>
#include "config.hpp"
#include "player.hpp"

//constructor
//set the stats for the basic enemy
Boss::Boss(){
	boss.setSize(sf::Vector2f(BOSSSIZE, BOSSSIZE/2));
        boss.setOrigin(BOSSSIZE/2,BOSSSIZE/4);
	boss.setPosition(225, 100);
        isActive = true;
	clock.restart();
}


//function to have enemies shuffle back and forth
void Boss::Move(){
        if(isActive){
		//shuffle enemy
		if(shufflecount < 10){
                	if(clock.getElapsedTime().asMilliseconds() >=interval){
                		boss.move(6,0);
				shufflecount++;
				clock.restart();
			}
		}
		if(shufflecount < 20){
                        if(clock.getElapsedTime().asMilliseconds() >=interval){
                                boss.move(-6,0);
                                shufflecount++;
                                clock.restart();
                        }
		}
		if(shufflecount == 20){shufflecount = 0;}
	}
}

//function to draw the enemy to the window
void Boss::Draw(sf::RenderWindow &window){
	//if the enemy is active
        if(isActive){
		//draw the enemy
		window.draw(boss);
	}
	return;
}

//function for when bullet hits boss
void Boss::Damage(int x){
	if(isActive){
		//give the player 10 points
		int totalscore = (Player::getInstance()->getScore()) + 10;
		Player::getInstance()->setScore(totalscore);
		//decrease the boss's health
        	health = health - x;
		//if boss's health reaches zero
        	if(health <= 0){
			//get rid of the enemy 
			isActive = false;
			std::cout<<"Boss defeated!"<<std::endl;
		}
	}
}

//function for if the player and boss collide
void Boss::CheckCollision(sf::RenderWindow &w){
	if(isActive){
		//while the player is still colliding with the boss
        	if(boss.getGlobalBounds().intersects(Player::getInstance()->player.getGlobalBounds())){
			//only damage the player once
			while(firsthit == false){
				std::cout<<"Boss hit!"<<std::endl;
				Player::getInstance()->Damage(10, w);
				firsthit = true;
			}

        	}
		//reset once player and boss stop touching
		if(!boss.getGlobalBounds().intersects(Player::getInstance()->player.getGlobalBounds())){
			firsthit = false;
		}
	}
}
