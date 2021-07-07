#ifndef BOSS_HPP
#define BOSS_HPP

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

//BOSS CLASS//
class Boss{
        protected:
		//only damage player once
		bool firsthit = false;
		//enemy stats
                int health = 200;
		int interval = 250;
		//movement
		int shufflecount = 1;
		//clock for enemy movement
		sf::Clock clock;
        public:
		bool isActive;
                //enemy rectangle
                sf::RectangleShape boss;
                //constructor
                Boss();
		~Boss(){};
		//Moves boss
		void Move();
		//damage boss
		void Damage(int x);
                //draws boss to screen
                void Draw(sf::RenderWindow &window);
		//check to see if player hits enemy
		void CheckCollision(sf::RenderWindow &w);
};

#endif 
