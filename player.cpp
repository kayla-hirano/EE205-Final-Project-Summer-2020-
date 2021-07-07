#include <iostream>
#include "player.hpp"
//#include "enemy.hpp"

Player *Player::instance = NULL;

//constructor
Player::Player(){
        texture.loadFromFile("images/Player.png");
	texture1.loadFromFile("images/PlayerHurt.png");
        player.setTexture(texture);
        player.setOrigin(PSIZE/2,PSIZE/2);
        player.setPosition(WSIZE/2, 400);
	moveDir = Stop;
	score = 0;
	pclock.restart();
	//b = new bullets[20];
}

//destructor
Player::~Player(){
	delete instance;
}

//function that returns the player
Player* Player::getInstance(){
	if(!instance)
		instance = new Player();
	return instance;
}

//function to draw the player to the window
void Player::Draw(sf::RenderWindow &window){
	//draw player
	window.draw(player);
	//draw the player's bullets here as well
	for(int i=0; i<20; i++){
		bullets[i].Draw(window);
	}
        return;
}

//function that takes keyboard and mouse input
void Player::HandleEvent(){
	//if pressed left
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                //move left
                moveDir = Left;
        }
	//if pressed right
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                //move right
                moveDir = Right;
        }
	//if pressed up
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                //move up
                moveDir = Up;
        }
	//if pressed down
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                //move down
                moveDir = Down;
        }
	//if left clicked
	else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                //left click
                moveDir = Stop;
        }
	//if pressed spacebar
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		//shoot
		Shoot();
	}
        return;
}

//function that takes care of the edges of the window when moving
void Player::Move(){
        //move left or right
        switch(moveDir){
                case Left:
                //if player reaches boundary, stop
                        if(player.getPosition().x < 0 + PSIZE/2){
                                moveDir = Stop;
                                break;
                        }
                        //if not, move
                        player.move(-movespeed,0);
                        break;
                case Right:
                        if(player.getPosition().x > WSIZE - PSIZE/2){
                                moveDir = Stop;
                                break;
                        }
                        player.move(movespeed,0);
                        break;
                case Up:
                        if(player.getPosition().y < 0 +PSIZE/2){
                                moveDir = Stop;
                                break;
                        }
                        player.move(0,-movespeed);
                        break;
		case Down:
			if(player.getPosition().y > WSIZE - PSIZE/2){
				moveDir = Stop;
				break;
			}
			player.move(0, movespeed);
			break;
	}

	//have the bullets move here too
	for(int i=0; i<20; i++)
		bullets[i].Move(-8, -10);

	return;
}

//function that decreases the health of the player
void Player::Damage(int x, sf::RenderWindow &window){
	//decrease the health
	health -=x;
	//decrease the score by 10
	if(score >= 10){
		score = score - 10;
	}
	//if the health is getting low
	if(health <= 30){
		//set the damaged enemy sprite
		player.setTexture(texture1);
	}
	//if the health reaches zero
        if(health <= 0){
		//close the screen for a game over
		window.close();
                std::cout<<"Game over"<<std::endl;
		//stop the player's movements
		moveDir = Stop;
        }
}

//function to help prepare the player to shoot
void Player::Shoot(){
	//leave a short interval between each bullet
	if(pclock.getElapsedTime().asSeconds()<0.25){
		return;
	}

	Bullet *b;
	//loop through the bullets and find on that's inactive
	for(int i=0; i<20; i++){
		if(!bullets[i].isActive){
			//assign a reference 
			b = &bullets[i];
			break;
		}
	}
	//set the bullet's position
	b->bullet.setPosition(player.getPosition().x, player.getPosition().y);
	//make the bullet active
	b->isActive = true;
	//restart clock
	pclock.restart();
}

//function to check if the bullets collided with any enemies
void Player::CheckCollision(Pool &p){
	//loop through the bullets and check to collision for each
	for(int i=0; i<20; i++){
		bullets[i].CheckCollision(p);
	}
}

//special function for boss
void Player::CheckBossCollision(Boss &b){
	//loop through the bullets and check the collision for each
	for(int i=0; i<20; i++){
		bullets[i].CheckBossCollision(b);
	}
}
