#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

//ENEMY CLASS//
class Enemy{
        protected:
		//only damage player once
		bool firsthit = false;
		//enemy stats
		int espeed = 6;
                int health = 10;
		int interval = 500;
		//movement
		int shufflecount = 1;
		//clock for enemy movement
		sf::Clock clock;
        public:
		bool isActive;
                //enemy sprite
                sf::Texture texture, texture1;
                sf::Sprite enemy;
                //constructor
                Enemy();
		~Enemy(){};
		//parameterized constructor
		Enemy(int x, int y);
		//Moves enemy
		void Move();
		//damage enemy
		void Damage(int x);
                //draws enemy to screen
                void Draw(sf::RenderWindow &window);
		//check to see if player hits enemy
		void CheckCollision(sf::RenderWindow &w);
};

//classes inheriting from enemy
class FastEnemy: public Enemy{
	public:
		FastEnemy();
};

class StrongEnemy: public Enemy{
	public:
		StrongEnemy();
};

//not a traditional enemy, meteors fall from the sky
class Meteor: public Enemy{
	public:
		Meteor();
		void Spawn();
		void Fall();
};

#endif
