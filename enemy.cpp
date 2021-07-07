#include <stdio.h>
#include <iostream>
#include "config.hpp"
#include "player.hpp"

//constructor
//set the stats for the basic enemy
Enemy::Enemy(){
        texture.loadFromFile("images/Enemy.png");
	texture1.loadFromFile("images/EnemyHurt.png");
        enemy.setTexture(texture);
        enemy.setOrigin(ESIZE/2,ESIZE/2);
        isActive = false;
	clock.restart();
}

//constructor
//set the stats for the fast enemy
FastEnemy::FastEnemy(){
        texture.loadFromFile("images/FastEnemy.png");
	texture1.loadFromFile("images/FastEnemyHurt.png");
        enemy.setTexture(texture);
        enemy.setOrigin(ESIZE/2,ESIZE/2);
        isActive = false;
	interval = 250;
        clock.restart();
}

//constructor
//set the stats for the strong enemy
StrongEnemy::StrongEnemy(){
        texture.loadFromFile("images/StrongEnemy.png");
	texture1.loadFromFile("images/StrongEnemyHurt.png");
        enemy.setTexture(texture);
        enemy.setOrigin(ESIZE,ESIZE/2);
        isActive = false;
	health = 20;
        clock.restart();
}

//constructor 
//set the stats for the meteor
Meteor::Meteor(){
	srand(time(0));
	texture.loadFromFile("images/Meteor.png");
	enemy.setTexture(texture);
	enemy.setOrigin(ESIZE/2, ESIZE/2);
	isActive = false;
	health = 10;
	clock.restart();
}

//custom function to spawn the meteor
void Meteor::Spawn(){
	if(!isActive){
		//get a random time interval between 2 and 5 seconds
		int random = rand()%5 + 1;
		//every 3 seconds
		if(clock.getElapsedTime().asSeconds() >= random){
			//get a randoom number that's inside the window boundary
			random = rand()%501;
			//place the meteor in that area
			enemy.setPosition(random, -10);
			//the meteor is active
			isActive = true;
			//restart the clock
			clock.restart();
		}
	}
	return;
}

//custom function to have the meteor fall
void Meteor::Fall(){
	//if the meteor is active
	if(isActive){
		//let the meteor fall
		enemy.move(0, 6);
		//make the meteor inactive if it goes off screen
                if(enemy.getPosition().y >= 510){
                        isActive = false;
                }
	}
}



//function to have enemies shuffle back and forth
void Enemy::Move(){
        if(isActive){
		//shuffle enemy
		if(shufflecount < 4){
                	if(clock.getElapsedTime().asMilliseconds() >=interval){
                		enemy.move(espeed,0);
				shufflecount++;
				clock.restart();
			}
		}
		if(shufflecount < 8){
                        if(clock.getElapsedTime().asMilliseconds() >=interval){
                                enemy.move(-espeed,0);
                                shufflecount++;
                                clock.restart();
                        }
		}
		if(shufflecount == 8){shufflecount = 0;}
	}
}

//function to draw the enemy to the window
void Enemy::Draw(sf::RenderWindow &window){
	//if the enemy is active
        if(isActive){
		//draw the enemy
		window.draw(enemy);
	}
	return;
}

//function for when bullet hits enemy
void Enemy::Damage(int x){
	//set the texture to the hurt sprite 
	enemy.setTexture(texture1);
	//give the player 10 points
	int totalscore = (Player::getInstance()->getScore()) + 10;
	Player::getInstance()->setScore(totalscore);
	//decrease the enemy's health
        health = health - x;
	//if enemy's health reaches zero
        if(health <= 0){
		//get rid of the enemy 
		isActive = false;
	}
}

//function for if the player and enemy collide
void Enemy::CheckCollision(sf::RenderWindow &w){
	if(isActive){
		//while the player is still colliding with the enemy
        	if(enemy.getGlobalBounds().intersects(Player::getInstance()->player.getGlobalBounds())){
			//only damage the player once
			while(firsthit == false){
				std::cout<<"Enemy hit!"<<std::endl;
				Player::getInstance()->Damage(10, w);
				firsthit = true;
			}

        	}
		//reset once player and enemy stop touching
		if(!enemy.getGlobalBounds().intersects(Player::getInstance()->player.getGlobalBounds())){
			firsthit = false;
		}
	}
}
