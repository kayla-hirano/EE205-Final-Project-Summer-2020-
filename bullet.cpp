#include <iostream>
#include "config.hpp"
#include "bullet.hpp"

//constructor
Bullet::Bullet(){
	//set attack power
	attack = 10;
	//create bullet
        bullet.setSize(sf::Vector2f(BSIZE,BSIZE));
        bullet.setOrigin(BSIZE/2,BSIZE/2);
	bullet.setPosition(-100, -100);
	//make sure bullet is inactive
	isActive = false;
}

//function to draw the bullet to the window
void Bullet::Draw(sf::RenderWindow & window){
	//if the bullet is active, draw
	if(isActive){
		window.draw(bullet);
	}
}

//function to have the bullet move across the window
void Bullet::Move(int speed, int bound){
	//if the bullet is active, move
	if(isActive){
		//if the bullet moves out of bounds, make it inactive
		bullet.move(0,speed);
		if(bullet.getPosition().y <= bound){
			isActive = false;
		}
	}
}

void Bullet::CheckCollision(Pool &pool){
	//only check active bullets
	if(isActive){
		//go through the whole pool
		for(int i=0; i<20; i++){
			//if the enemy is active
			if((pool.GetePool())[i].isActive){
				//if the bullet interects an enemy
				if(bullet.getGlobalBounds().intersects((pool.GetePool())[i].enemy.getGlobalBounds())){
					//damage the enemy
					(pool.GetePool())[i].Damage(5);
					//get rid of the bullet
					isActive = false;
				}
			}
			else if((pool.GetfPool())[i].isActive){
                                //if the bullet interects an enemy
                                if(bullet.getGlobalBounds().intersects((pool.GetfPool())[i].enemy.getGlobalBounds())){
                                        //damage the enemy
                                        (pool.GetfPool())[i].Damage(5);
                                        //get rid of the bullet
                                        isActive = false;
                                }
                        }
                        if((pool.GetsPool())[i].isActive){
                                //if the bullet interects an enemy
                                if(bullet.getGlobalBounds().intersects((pool.GetsPool())[i].enemy.getGlobalBounds())){
                                        //damage the enemy
                                        (pool.GetsPool())[i].Damage(5);
                                        //get rid of the bullet
                                        isActive = false;
                                }
                        }
		}
	}
}

//special boss case
void Bullet::CheckBossCollision(Boss &b){
	//check active bullets
	if(isActive){
		//if the boss is active
		if(b.isActive){
        		//if the bullet interects the boss
                	if(bullet.getGlobalBounds().intersects(b.boss.getGlobalBounds())){
                		//damage the enemy
                	        b.Damage(10);
                	        //get rid of the bullet
                	        isActive = false;
                   	}
                 }	
	}
}

