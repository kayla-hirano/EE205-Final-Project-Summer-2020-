#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include "pool.hpp"
#include "boss.hpp"

class Bullet{
	public:
		//enemy pool
		sf::RectangleShape bullet;
		//bullet attack power
		int attack;
		bool isActive;
		Bullet();
		~Bullet(){};
		//can set the speed and when the bullet is out of bounds
		void Move(int speed, int bound);
		void Draw(sf::RenderWindow & window);
		//checks if the bullets hits enemy
		void CheckCollision(Pool &pool);
		//special boss case
		void CheckBossCollision(Boss &b);
};


#endif
