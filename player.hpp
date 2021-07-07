#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "bullet.hpp"
#include "config.hpp"

enum Dir{Left, Right, Up, Down, Stop};

class Bullet;

//PLAYER CLASS//
class Player{
        private:
		//return the player
		static Player* instance;
		//enum for movement
		enum Dir moveDir;
		//player stats
		int health = 100;
		int score = 0;
		Bullet bullets[20];;
		//player clock
		sf::Clock pclock;
        public:
		//player sprite
		sf::Texture texture, texture1;
		sf::Sprite player;
                //constructor
                Player();
		~Player();
		//getters and setters
		int getHealth(){return health;}
		void setHealth(int h){health = h;}
		int getScore(){return score;}
		void setScore(int s){score = s;}

		//draws player to screen
                void Draw(sf::RenderWindow &window);
		//looks at input from player
                void HandleEvent();
		//moves player
                void Move();
		//apply damage to player
		void Damage(int x, sf::RenderWindow &window);	
		//lets the player shoot
		void Shoot();	
		//checks the collision of the player's bullets
		void CheckCollision(Pool &p);
		//special boss case
		void CheckBossCollision(Boss &b);
		static Player* getInstance();

};

#endif
