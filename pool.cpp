#include <SFML/Graphics.hpp>
#include "pool.hpp"
#include <stdlib.h>
#include <iostream>

Pool::Pool(){
	//restart clock
	clock.restart();
}

void Pool::SpawnEnemy(){
	//put the normal enemies in their positions//
	Enemy *e;
	//get inactive enemy
	for(int i=0; i<9; i++){
		e = &ePool[i];
               	//place basic enemies in correct position
               	//should form two lines
               	e->enemy.setPosition(tempx+50 ,tempy+75 );
		//shifts the enemies positions as you spawn them in
               	if(i<=4){
                      	tempx = tempx + 100;
                       	if(i==4){
				tempx = 50;
				tempy = 50;
			}
               	}
               	if(i>4){
                      	tempx = tempx + 100;
               	}
               	//activate the enemy
               	e->isActive = true;
	}
	//reset variables
	tempx = 0;
	tempy = 0;
	FastEnemy *f;
	//put the fast enemies in their positions//
	for(int i=0; i<3; i++){
		//set a reference to the next enemy
		f = &fPool[i];
		//set its position
		f->enemy.setPosition(tempx+100, 25);
		tempx = tempx + 125;
		//activate it
		f->isActive = true;
	}
	//reset variables
	tempx = 125;
	tempy = 0;
	//spawn strong enemy
	StrongEnemy *s;
	//put the strong enemies in their positions//
	for(int i=0; i<3; i++){
		//set reference to next enemy
		s = &sPool[i];
		//set position
		s->enemy.setPosition(tempx,175);
		tempx = tempx + 125;
		//activate the enemy
		s->isActive = true;
	}
}

void Pool::Move(){
	for(int i = 0; i<10; i++){
		ePool[i].Move();
		fPool[i].Move();
		sPool[i].Move();
	}
}

void Pool::Draw(sf::RenderWindow &window){
	for(int i=0; i<10; i++){
		ePool[i].Draw(window);
		fPool[i].Draw(window);
		sPool[i].Draw(window);
	}
}

void Pool::CheckCollision(sf::RenderWindow &window){
	for(int i=0; i<10; i++){
		ePool[i].CheckCollision(window);
		fPool[i].CheckCollision(window);
		sPool[i].CheckCollision(window);
	}	
}

int Pool::Update(sf::RenderWindow &window){
	//loop through the enemy pools
	for(int i=0; i<10; i++){
		//check to see if any of the enemies are still active
		if(ePool[i].isActive == true){
			return RUN;
		}
		if(fPool[i].isActive == true){
			return RUN;
		}
		if(sPool[i].isActive == true){
			return RUN;
		}
	}
	//if all the enemies are gone, the level is complete
	return COMPLETE;
}

Enemy* Pool::GetePool(){
	return ePool;
}

Enemy* Pool::GetfPool(){
	return fPool;
}

Enemy* Pool::GetsPool(){
	return sPool;
}
