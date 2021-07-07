#ifndef POOL_HPP
#define POOL_HPP

#include <SFML/Graphics.hpp>
#include "enemy.hpp"

#define RUN 1
#define COMPLETE 2

class Pool{
	private:
		//enemy pool
		Enemy ePool[10];
		//Fast enemy pool
		FastEnemy fPool[10];
		//Strong enemy pool
		StrongEnemy sPool[10];

		sf::Clock clock;
		//for placing enemies
		int tempx = 0;
		int tempy = 0;
		bool complete = false;
	public:
		Pool();
		~Pool(){};
		void SpawnEnemy();
		//get the different enemy pools
		Enemy * GetePool();
		Enemy * GetfPool();
		Enemy * GetsPool();
		
		void Move();
		void Draw(sf::RenderWindow &window);
		void CheckCollision(sf::RenderWindow &window);
		int Update(sf::RenderWindow &window);
};

#endif
