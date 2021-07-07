#ifndef BG_HPP
#define BG_HPP

#include <SFML/Graphics.hpp>

class BG{
        private:
		//textures for the background
                sf::Texture texture1;
                sf::Sprite sprite1, sprite2;
        public:
		//constructor
                BG();
		~BG(){};
		//function to move the background
                void move();
		//function to draw to window
                void draw(sf::RenderWindow &window);
};

#endif
