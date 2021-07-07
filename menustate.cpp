#include "menustate.hpp"

//constructor
MenuState::MenuState(){
	//button settings
        button1.Set(120, 40, 250, 215, sf::Color::Blue);
        button2.Set(120, 40, 250, 315, sf::Color::Blue);

        Font.loadFromFile("fonts/ostrich.ttf");

        //button text settings
        Button1.setFont(Font);
        Button1.setString("Start Game");
        Button1.setCharacterSize(24);
        Button1.setFillColor(sf::Color::White);
        Button1.setPosition(210, 200);

        Button2.setFont(Font);
	Button2.setString("Controls");
        Button2.setCharacterSize(24);
        Button2.setFillColor(sf::Color::White);
        Button2.setPosition(220, 300);

	//controls text settings
	Controls.setFont(Font);
	Controls.setString("Use the arrow keys to move, and SPACE to shoot");
	Controls.setCharacterSize(24);
	Controls.setFillColor(sf::Color::White);
	Controls.setPosition(75, 350);
}

//getters and setters
state MenuState::getState(){
	return GameState;
}

void MenuState::setState(state s){
	GameState = s;
}

//function to handle player input
void MenuState::CheckEvent(sf::RenderWindow &window){
	//check the events from the two buttons
	button1.CheckEvent(window);
	//if the first button is clicked, start game
	if(button1.clicked == true){
		GameState = Game;
	}
	//if second button was clicked, display controls
	button2.CheckEvent(window);
	if(button2.clicked == true){
		//display controls
		controls = true;
	}
	return;
}

//function to draw the menu to the screen
void MenuState::Draw(sf::RenderWindow &window){
        //draw the buttons
        window.draw(button1.button);
        window.draw(button2.button);
	//draw the button text
	window.draw(Button1);
	window.draw(Button2);
	//draw the controls if the button is clicked
	if(controls == true){
		window.draw(Controls);
	}

}

